#ifndef Lista_h
#define Lista_h

// Librerias
#include <iostream>
#include <cstdlib>
#include <string>
#include "Nodo.h"

using namespace std;

template <class T>
class Lista
{
	private: // Atributos
		Nodo<T> *primero, *ultimo;
		int n;
	public: // Metodos
		//Constructores
		Lista() {this->primero = NULL, this->ultimo = NULL, this->n = 0;}
		Lista(const Lista<T> &);

		// Consultores
		bool esVacia() {return(this->n == 0);}
		int longitud() {return(this->n);}
		T getPrimero() {return(primero->getElemento());}
		T getUltimo() {return(ultimo->getElemento());}
		T consultarK(int);
		T consultar(int);
		int getPos(T);
		bool esta(T);
		T mayorElem();
		T menorElem();

		// Modificadores
		void insertar(T, int);
		void insertarEnOrden(T);
		void insHead(T);
		void delHead();
		void insQueque(T);
		void eliminar(int);
		void setPrimero(T e) {this->primero->setElemento(e);}
		void setUltimo(T e) {this->ultimo->setElemento(e);}
		void modificar(T, int);
		void invertir();

		// Otros
		void subLista(Lista<T> &, int, int);
		Lista<T> sublista(int, int);
		bool esSublista(const Lista <T> &);
		int cuantasVecesSublista(const Lista<T> &);
		//void extraerSublista(const Lista<T> &);
		void invertirSublista(T, T);
		Lista<T> shuffleMerge(const Lista<T> &);
		Lista<T> merge(const Lista<T> &);
		void ordenar();

		// Destructor
		void vaciar();
		~Lista();

		// Sobrecarga de operadores
		Lista<T> operator+(const Lista<T> &);
		void operator=(const Lista<T> &);
		bool operator>(const Lista<T> &);
		bool operator<(const Lista<T> &);
		bool operator==(const Lista<T> &);
		bool operator>=(const Lista<T> &);
		bool operator<=(const Lista<T> &);

		template <class Ts>
		friend ostream& operator<<(ostream&, const Lista<Ts> &);

};

// Constructor
template <typename T>
Lista<T>::Lista(const Lista<T> &l)
{
	Nodo<T> *nuevo, *act;
	act = l.primero;
	this->primero = NULL;
	this->ultimo = NULL;
	while(act != NULL)
	{
		nuevo = new Nodo<T> (act->getElemento());
		if(this->primero == NULL)
		{
			nuevo->setSiguiente(act);
			this->primero = nuevo;
		}
		else
		{
			this->ultimo->setSiguiente(nuevo);
		}
		this->ultimo = nuevo;
		act = act->getSiguiente();
	}
	this->n = l.n;
}

// Constultores
template <typename T>
T Lista<T>::consultarK(int k)
{
	int i;
	Nodo<T> *act;
	act = this->primero;
	for(i = (this->n - 1); i >= k; i--)
	{
		act = act->getSiguiente();
	}
	return(act->getElemento());
}


template <typename T>
T Lista<T>::consultar(int pos)
{
	Nodo<T> *act, *sig;
	if(pos == 1)
	{
		act = this->primero;
	}
	else
	{
		if(pos == this->n)
		{
			act = this->ultimo;
		}
		else
		{
			act = this->primero;
			for(int i = 1; i < pos; i++)
			{
				act = act->getSiguiente();
			}
		}
	}
	return(act->getElemento());
}

template <typename T>
int Lista<T>::getPos(T e)
{
	int pos;
	Nodo<T> *act;
	bool encontrado;

	act = this->primero;
	encontrado = false;
	pos = 1;
	while(act != NULL && !encontrado)
	{
		if(act->getElemento() == e)
		{
			encontrado = true;
		}
		else
		{
			act = act->getSiguiente();
			pos++;
		}
	}

	if(encontrado)
	{
		return(pos);
	}
	else
	{
		return(-1);
	}
}

template <typename T>
bool Lista<T>::esta(T e)
{
	bool encontrado = false;
	Nodo<T> *act = this->primero;
	while(act != NULL && !encontrado)
	{
		if(act->getElemento() == e)
		{
			encontrado = true;
		}
		else
		{
			act = act->getSiguiente();
		}
	}
	return(encontrado);
}

template <typename T>
T Lista<T>::mayorElem()
{
	T mayor;
	Nodo<T> *act;
	mayor = this->primero->getElemento();
	act = this->primero->getSiguiente();
	while(act != NULL)
	{
		if(act->getElemento() > mayor)
		{
			mayor = act->getElemento();
		}
		act = act->getSiguiente();
	}
	return(mayor);
}

template <typename T>
T Lista<T>::menorElem()
{
	T menor;
	Nodo<T> *act;
	menor = this->primero->getElemento();
	act = this->primero->getSiguiente();
	while(act != NULL)
	{
		if(act->getElemento() < menor)
		{
			menor = act->getElemento();
		}
		act = act->getSiguiente();
	}
	return(menor);
}

// Modificadores
template <typename T>
void Lista<T>::insertar(T e, int pos)
{
	Nodo<T> *nuevo, *ant, *sig;
	if(pos < 1 || pos > this->n + 1)
	{
		cout << "Error, se intento insertar en una posicion invalida" << endl;
	}
	else
	{
		nuevo = new Nodo<T> (e);
		if(pos == 1)	// Insertar al principio
		{
			nuevo->setSiguiente(this->primero);
			this->primero = nuevo;
		}
		else
		{
			// Insertar en medio o al final
			ant = this->primero;
			sig = ant->getSiguiente();
			for(int i = 2; i < pos; i++)
			{
				ant = sig;
				sig = sig->getSiguiente();
			}
			ant->setSiguiente(nuevo);
			nuevo->setSiguiente(sig);
		}
		if(pos == (this->n + 1))
		{
			this->ultimo = nuevo;
		}
		this->n++;
	}
}

template <typename T>
void Lista<T>::insertarEnOrden(T e)
{
	Nodo<T> *nuevo, *act, *ant;

	bool encontrado = false;
	nuevo = new Nodo<T> (e);
	act = this->primero;
	ant = act;

	while(act != NULL && !encontrado)
	{
		if(act->getElemento() >= e)
			encontrado = true;
		else
		{
			ant = act;
			act = act->getSiguiente();
		}
	}

	if(act == this->primero)
	{
		nuevo->setSiguiente(this->primero);
		this->primero = nuevo;
	}
	else
	{
		ant->setSiguiente(nuevo);
		nuevo->setSiguiente(act);
	}
	this->ultimo = nuevo;
	this->n++;
}

template <typename T>
void Lista<T>::insHead(T e)
{
	Nodo<T> *nuevo;
	nuevo = new Nodo<T> (e);
	nuevo->setSiguiente(this->primero);
	this->primero = nuevo;
	if(this->ultimo = NULL)
	{
		this->ultimo = nuevo;
	}
	this->n++;
}

template <typename T>
void Lista<T>::delHead()
{
	Nodo<T> *act;
	act = this->primero;
	if(act != NULL)
	{
		this->primero = act->getSiguiente();
		delete act;
		if(this->primero == NULL)
		{
			this->ultimo = NULL;
		}
		this->n--;
	}
}

template <typename T>
void Lista<T>::insQueque(T e)
{
	Nodo<T> *nuevo;
	nuevo = new Nodo<T> (e);
	if(this->primero == NULL)
	{
		this->primero = nuevo;
	}
	else
	{
		this->ultimo->setSiguiente(nuevo);
	}
	this->ultimo = nuevo;
	this->n++;
}

template <typename T>
void Lista<T>::eliminar(int pos)
{
	Nodo<T> *ant, *act, *sig;
	if(pos < 1 || pos > this->n + 1)
	{
		cout << "Error, se intento eliminar una posicion invalida" << endl;
	}
	else
	{
		if(pos == 1)
		{
			act = this->primero;
			this->primero = act->getSiguiente();
			if(this->primero == NULL)
			{
				this->ultimo = NULL;
			}
		}
		else
		{
			ant = this->primero;
			act = ant->getSiguiente();
			sig = act->getSiguiente();
			for(int i = 2; i < pos; i++)
			{
				ant = act;
				act = sig;
				sig = sig->getSiguiente();
			}
			ant->setSiguiente(sig);
			if(sig == NULL)
			{
				this->ultimo = ant;
			}
		}
		delete act;
		this->n--;
	}
}

template <typename T>
void Lista<T>::modificar(T e, int pos)
{
	Nodo<T> *act;
	if(pos < 1 || pos > this->n)
	{
		cout << "Error, se intento insertar en una posicion invalida" << endl;
	}
	else
	{
		act = this->primero;
		for(int i = 2; i <= pos; i++)
		{
			act = act->getSiguiente();
		}
		act->setElemento(e);
	}
}

template <typename T>
void Lista<T>::invertir()
{
	Nodo<T> *ant, *act, *sig;
	this->ultimo = this->primero;
	ant = NULL;
	act = this->primero;
	while(act != NULL)
	{
		sig = act->getSiguiente();
		act->setSiguiente(ant);
		ant = act;
		act = sig;
	}
	this->primero = ant;
}

// Otros
template <typename T>
void Lista<T>::subLista(Lista<T> &l, int org, int dest)
{
	int i;
	Nodo<T> *act;
	if(this->primero != NULL && org <= dest && dest <= this->n)
	{
		act = this->primero;
		for(i = 1; i < org; i++)
		{
			act = act->getSiguiente();
		}

		for(i = org; i <= dest; i++)
		{
			l.insQueque(act->getElemento());
			act = act->getSiguiente();
		}
	}
	else
	{
		cout << "Las posiciones de origen y destino no son validas" << endl;
	}
}

template <typename T>
Lista<T> Lista<T>::sublista(int a, int b)	// a y b son posiciones de la lista
{
	Lista<T> l;
	int i;
	Nodo<T> *act;
	if( 1 <= a <= this->n && 1 <= b <= this->n)
	{
		if(a > b)
		{
			int aux = a;
			a = b;
			b = aux;
		}
		act = this->primero;
		for(i = 1; i < a; i++)
		{
			act = act->getSiguiente();
		}

		for(i = a; i <= b; i++)
		{
			l.insQueque(act->getElemento());
			act = act->getSiguiente();
		}
	}
	return l;
}

template <typename T>
bool Lista<T>::esSublista(const Lista <T> &b)
{
	bool band;
	Nodo<T> *act, *aux_a, *aux_b;
	int cont;
	act = this->primero;
	aux_a = act;
	aux_b = b.primero;
	cont = 0;
	while(act != NULL && aux_b != NULL && b.n <= (this->n - cont))
	{
		cont++;
		if(act->getElemento() == aux_b->getElemento())
		{
			band = true;	// Parto de la idea de que b es sublista de a
			while(aux_b != NULL && band)
			{
				if(aux_a->getElemento() == aux_b->getElemento())
				{
					aux_a = aux_a->getSiguiente();
					aux_b = aux_b->getSiguiente();
				}
				else
				{
					aux_b = b.primero;
					band = false;
				}
			}
		}
		act = act->getSiguiente();
		aux_a = act;
	}
	return (aux_b == NULL);
}

template <typename T>
int Lista<T>::cuantasVecesSublista(const Lista<T> &b)
{
	bool band;
	Nodo<T> *act, *aux_a, *aux_b;
	int cont, veces;
	act = b.primero;
	aux_b = act;
	aux_a = this->primero;
	cont = 0;
	veces = 0;
	while(act != NULL && this->n <= (b.n - cont))
	{
		cont++;
		if(act->getElemento() == aux_a->getElemento())
		{
			band = true;	// Parto de la idea de que b es sublista de a
			while(aux_a != NULL && band)
			{
				if(aux_a->getElemento() == aux_b->getElemento())
				{
					aux_a = aux_a->getSiguiente();
					aux_b = aux_b->getSiguiente();
				}
				else
				{
					aux_a = this->primero;
					band = false;
				}
			}

			if(band && aux_a == NULL)
			{
				veces++;
				aux_a = this->primero;
			}
		}
		act = act->getSiguiente();
		aux_b = act;
	}
	return(veces);
}

/*template <class T>
void Lista<T>::extraerSublista(const Lista<T> &b)
{
	bool band, pos1;
	Nodo<T> *act, *aux_a, *aux_b, *aux, *ant;
	int cont, i;
	act = this->primero;
	aux_a = act;
	aux_b = b.primero;
	cont = 0;
	i = 1;
	while(act != NULL && b.n <= (this->n - cont))
	{
		cont++;
		if(act->getElemento() == aux_b->getElemento())
		{
			band = true;	// Parto de la idea de que b es sublista de a
			while(aux_b != NULL && band)
			{
				if(aux_a->getElemento() == aux_b->getElemento())
				{
					aux_a = aux_a->getSiguiente();
					aux_b = aux_b->getSiguiente();
				}
				else
				{
					aux_b = b.primero;
					band = false;
				}
			}

			if(band)
			{
				aux_b = b.primero;
				if(this->primero->getElemento() == aux_b->getElemento() && i == 1)
				{
					pos1 = true;
				}
				else
				{
					pos1 = false;
				}

				while(aux_b != NULL)
				{
					if(pos1)
					{
						aux = this->primero;
						this->primero = aux->getSiguiente();
					}
					else
					{
						ant = act;
						aux = act;
						act = aux->getSiguiente();
						ant->setSiguiente(act);
					}
					aux_b = aux->getSiguiente();
					delete(aux);
					this->n--;
				}

				if(aux_b == NULL)
				{
					aux_b = b.primero;
				}
			}
		}
		act = act->getSiguiente();
		aux_a = act;
		i++;
	}
}*/

template <typename T>
void Lista<T>::invertirSublista(T a, T b)
{
	Nodo<T> *aux, *act, *sig, *ant, *prim;
	bool ini, fin, pos1;
	int i;

	act = this->primero;
	sig = act->getSiguiente();
	ini = false;
	fin = false;
	pos1 = false;
	i = 1;
	while(act != NULL)
	{
		if(act->getElemento() != a && act->getElemento() != b && !ini)
		{
			ant = act;
			act = sig;
			sig = act->getSiguiente();			
		}
		else 
		{														
			if(i == 1)
			{
				pos1 = true;				
			}
			ini = true;
		}							
		if(ini)
		{
			if(!fin)
			{
				prim = act;
				fin = true;
			}
			aux = sig->getSiguiente();
			sig->setSiguiente(act);
			if(sig->getElemento() == a || sig->getElemento() == b)
			{
				prim->setSiguiente(aux);
				ini = false;
				if(!pos1)
				{
					ant->setSiguiente(sig);
				}
				else
				{
					this->primero = sig;
				}
			}
			act = sig;
			sig = aux;
			if(!ini)
			{
				act = NULL;
			}
		}
		i++;
	}
}

template <typename T>
Lista<T> Lista<T>::shuffleMerge(const Lista<T> &l)
{
	Lista<T> aux;
	Nodo<T> *act_1, *act_2;
	act_1 = this->primero;
	act_2 = l.primero;
	while(act_1 != NULL && act_2 != NULL)
	{
		aux.insQueque(act_1->getElemento());
		aux.insQueque(act_2->getElemento());
		act_1 = act_1->getSiguiente();
		act_2 = act_2->getSiguiente();
	}

	while(act_1 != NULL)
	{
		aux.insQueque(act_1->getElemento());
		act_1 = act_1->getSiguiente();
	}

	while(act_2 != NULL)
	{
		aux.insQueque(act_2->getElemento());
		act_2 = act_2->getSiguiente();
	}
	return(aux);
}

template <typename T>
Lista<T> Lista<T>::merge(const Lista<T> &a)
{
	Lista<T> l;
	Nodo<T> *act_1, *act_2;
	act_1 = this->primero;
	act_2 = a.primero;
	while(act_1 != NULL && act_2 != NULL)
	{
		if(act_1->getElemento() <= act_2->getElemento())
		{
			l.insQueque(act_1->getElemento());
			act_1 = act_1->getSiguiente();
		}
		else
		{
			l.insQueque(act_2->getElemento());
			act_2 = act_2->getSiguiente();
		}	
	}

	while(act_1 != NULL)
	{
		l.insQueque(act_1->getElemento());
		act_1 = act_1->getSiguiente();
	}

	while(act_2 != NULL)
	{
		l.insQueque(act_2->getElemento());
		act_2 = act_2->getSiguiente();
	}
	return l;
}

template <typename T>
void Lista<T>::ordenar()
{
	int i, j;
	T aux;
	Nodo<T> *v[this->n];
	Nodo<T> *act;

	act = this->primero;
	if(act != NULL)
	{
		/* El cada posicion del vector apuntara
		   a cada nodo de la Lista */

		for(i = 0; i < this->n; i++)
		{
			cout << "Nodo: " << act->getElemento() << endl;
			v[i] = act;
			act = act->getSiguiente();
		}

		/* Ordena en forma ascendente los elementos
		   de la Lista */
		for(i = 1; i < this->n; i++)
		{
			j = i;
			aux = v[j]->getElemento();
			while(j > 0 && aux < v[j-1]->getElemento())
			{
				v[j]->setElemento(v[j-1]->getElemento());
				j--;
			}
			v[j]->setElemento(aux);
		}
	}
}

// Destructor
template <typename T>
void Lista<T>::vaciar()
{
	Nodo<T> *act = this->primero;
	while(act != NULL)
	{
		this->primero = act->getSiguiente();
		delete act;
		act = this->primero;
	}
	this->ultimo = NULL;
	this->n = 0;
}

template <typename T>
Lista<T>::~Lista()
{
	this->vaciar();
}


// Sobrecarga de operadores
template <typename T>
Lista<T> Lista<T>::operator+(const Lista<T> &l)
{
	Lista<T> aux;
	Nodo<T> *act_1, *act_2;
	act_1 = this->primero;
	act_2 = l.primero;
	while(act_1 != NULL)
	{
		aux.insQueque(act_1->getElemento());
		act_1 = act_1->getSiguiente();
	}

	while(act_2 != NULL)
	{
		aux.insQueque(act_2->getElemento());
		act_2 = act_2->getSiguiente();
	}
	return(aux);
}

template <typename T>
void Lista<T>::operator=(const Lista<T> &l)
{
	int i;
	Nodo<T> *act_1, *act_2, *nuevo;
	if(this != &l)
	{
		this->vaciar();
		act_1 = this->primero;
		act_2 = l.primero;
		for(i = 1; i <= l.n; i++, act_2 = act_2->getSiguiente())
		{
			nuevo = new Nodo<T> (act_2->getElemento());
			if(i == 1)
			{
				this->primero = nuevo;
				act_1 = nuevo;
			}
			else
			{
				act_1->setSiguiente(nuevo);
				act_1 = act_1->getSiguiente();
			}
		}
		this->ultimo = nuevo;
		this->n = l.n;
	}
}

template <typename T>
bool Lista<T>::operator>(const Lista<T> &l)
{
	if(this != &l)
		return(this->n > l.n);
	else
		return false;
}

template <typename T>
bool Lista<T>::operator<(const Lista<T> &l)
{
	return !(*this > l);
}

template <typename T>
bool Lista<T>::operator==(const Lista<T> &l)
{
	int i;
	bool esIgual;
	Nodo<T> *act_1, *act_2;
	if(this != &l)
	{
		if(this->n != l.n)
		{
			return false;
		}
		else
		{	
			act_1 = this->primero;
			act_2 = l.primero;
			i = 1;
			do
			{
				esIgual = (act_1->getElemento() == act_2->getElemento());
				act_1 = act_1->getSiguiente();
				act_2 = act_2->getSiguiente();
				i++;
			}while(i <= this->n && esIgual);
			return esIgual;
		}
	}
	else
		return true;
}

template <typename T>
bool Lista<T>::operator>=(const Lista<T> &l)
{
	if(this != &l)
		return(*this > l || *this == l);
	else
		return true;
}

template <typename T>
bool Lista<T>::operator<=(const Lista<T> &l)
{
	if(this != &l)
		return(*this < l || *this == l);
	else
		return true;
}
		
template <typename T>
ostream& operator<<(ostream& out, const Lista<T> &l)
{
	Nodo<T> *act = l.primero;
	while(act != NULL)
	{
		out << act->getElemento();
		act = act->getSiguiente();
		if(act != NULL)
		{
			cout << " ";
		}
	}
	out << endl;
	return out;
}

#endif