#ifndef Nodo_h
#define Nodo_h

// Librerias
#include <iostream>
#include <string>

using namespace std;

template <class T>
class Nodo
{
	// Atributos
	protected:
		T elem;
		Nodo<T> *siguiente;
	public:
		// Constructores
		Nodo();
		Nodo(T e) {this->elem = e, this->siguiente = NULL;}
		Nodo(T e, Nodo<T> *sig) {this->elem = e, this->siguiente = sig;}

		// Consultores
		T getElemento() {return(this->elem);}
		Nodo<T> *getSiguiente() {return(this->siguiente);}

		// Modificadores
		void setElemento(T e) {this->elem = e;}
		void setSiguiente(Nodo<T> *sig) {this->siguiente = sig;}
};

#endif