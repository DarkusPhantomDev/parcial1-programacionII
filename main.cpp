#include <iostream>
#include <string>
#include "Lista.h"

using namespace std;

int saveCount(int count) {
	do {
		cin >> count;
	} while (count <=0);

	return count;
}

void checkList(int childrenCount, int wordsForLine) {
	Lista<string> *listName = new Lista<string>;
	Lista<string> *listNickname = new Lista<string>;
	string nameAndNickname;

	int count = 0;
	//cout << "Escribe el nombre y apodo:" << endl;

	while(count <= childrenCount) {
		count++;
		cout << "\nEscribe el nombre y apodo: " << endl;
		getline(cin, nameAndNickname);
		listName->insertar(nameAndNickname, count);
	}

	int countList = listName->longitud();
	int i;

	for(i = 2; i <= countList; i++) {
		cout << "Nombre: " << listName->consultar(i) << endl;
	}

}

int main() {
	int childrenCount, wordsForLine;

	cout << "Esta es la lista para los niños de santa \n" << endl;

	cout << "Ingrese la cantidad de niños a colocar en la lista: ";
	childrenCount = saveCount(childrenCount);

	cout << "Ingrese la cantidad de nombres por linea: ";
	wordsForLine = saveCount(wordsForLine);

	cout << "\nEscribe " << wordsForLine << " nombres por linea. \n" << endl;

	checkList(childrenCount, wordsForLine);

	return 0;
}