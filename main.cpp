#include <iostream>
#include <string>
#include "Lista.h"

using namespace std;

//Funcion que guarda el contador del inicio y lo verifica
int saveCount(int count) {
	do {
		cin >> count;
	}while (count <=0);

	return count;
}

void addNicknamesToList(Lista<string> *listNickname, int count) {
	string nickname;

	cout << "\nEscribe el nombre y apodo: " << endl;
	getline(cin, nickname);
	listNickname->insertar(nickname, count);
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
	string nickname;

	int count = 0;
	while(count <= childrenCount) {
		count++;
		addNicknamesToList(listNickname, count);
	}

	showList(listNickname);
}


int main() {
	int childrenCount, wordsForLine;

	cout << "/************************************************/" << endl;
	cout << "/*** Esta es la lista para los niños de santa ***/" << endl;
	cout << "/************************************************/\n" << endl;

	cout << "Ingrese la cantidad de niños a colocar en la lista: ";
	childrenCount = saveCount(childrenCount);

	cout << "Ingrese la cantidad de nombres por linea: ";
	wordsForLine = saveCount(wordsForLine);

	cout << "\nEscribe " << wordsForLine << " nombres por linea. \n" << endl;
	checkList(childrenCount, wordsForLine);

	return 0;
}