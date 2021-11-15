#include <iostream>
#include <string>
#include "Lista.h"

using namespace std;

//Funcion que guarda el contador del inicio y lo verifica
int saveCount(int counter) {
	do {
		cin >> counter;
	}while (counter <=0);

	return counter;
}

void addNicknamesToList(Lista<string> *listNickname, Lista<string> *listNickname2, int counter) {
	string nickname;
	char temporal;

	cout << "\nEscribe el nombre y apodo: " << endl;
	// getline(cin, nickname);
	while(cin >> nickname && cin.get(temp) && temp != '\n'){
		if(counter % 2 == 0) {
			listNickname->insertar(nickname, counter);
		} else {
			listNickname->insertar(nickname, counter);
		}
	}
}

//Funcion para mostrar la lista
void showList(Lista<string> *listNickname) {
	int countList = listNickname->longitud();
	int i;

	for(i = 2; i <= countList; i++) {
		cout << "Nombre: " << listNickname->consultar(i) << endl;
	}
}

//Funcion para revisar la checklist (Funcion secundaria, despues del main)
void checkList(int childrenCount, int wordsForLine) {
	Lista<string> *listNickname = new Lista<string>;
	Lista<string> *listNickname2 = new Lista<string>;
	string nickname;

	int counter = 0;
	while(counter <= childrenCount) {
		counter++;
		addNicknamesToList(listNickname, listNickname2, counter);
	}

	showList(listNickname);
}


int main() {
	int childrenCount, wordsForLine;
	string words;

	cout << "/************************************************/" << endl;
	cout << "/*** Esta es la lista para los niños de santa ***/" << endl;
	cout << "/************************************************/\n" << endl;

	cout << "Ingrese la cantidad de niños a colocar en la lista: ";
	childrenCount = saveCount(childrenCount);

	// cout << "Ingrese la cantidad de nombres por linea: ";
	// wordsForLine = saveCount(wordsForLine);

	// cout << "\nEscribe " << wordsForLine << " nombres por linea. \n" << endl;
	checkList(childrenCount, wordsForLine);


	return 0;
}