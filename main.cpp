#include <iostream>
#include <string>

using namespace std;

int saveCount(int count) {
	do {
		cin >> count;
	} while (count <=0);

	return count;
}

int main() {
	int childrenCount, wordsForLine;

	cout << "Esta es la lista para los niños de santa \n" << endl;

	cout << "Ingrese la cantidad de niños a colocar en la lista: ";
	childrenCount = saveCount(childrenCount);

	cout << "Ingrese la cantidad de nombres por linea: ";
	wordsForLine = saveCount(wordsForLine);

	cout << "\nEscribe " << wordsForLine << " nombres por linea. \n" << endl;
	cout << "Escribe el nombre: ";

	return 0;
}