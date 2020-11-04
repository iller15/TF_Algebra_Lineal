#include <iostream>

using namespace std;

int** ingreso_Data(int &n, int &m) {
	//los vectores que ingresa el usuario
	int** vecs;
	do {
		cout << "Ingrese la dimension en la que desee trabajar (entre 3 y 8): " << endl;
		cin >> n;
	} while (n > 8 || n < 3);

	cout << "Ingrese la cantidad de vectores con los que desea trabajar: " << endl;
	cin >> m;

	vecs = new int*[m];

	for (int i = 0; i < m; i++) {
		int* aux = new int[n];
		cout << "Llene los datos del vector " << i + 1 << ":" << endl;

		for (char e = 0; e < n; e++) {
			cin >> aux[e];
		};
		vecs[i] = aux;
	};
	
	return vecs;
}

int** random_Data(int n, int m) {
	int** vecs;
	return vecs;
}


int main() {
	//Dimension en la que estamos trabajando
	int n;
	//Cantidad de vectores
	int m;
	int** vecs;

	int des;
	cout << "Desea que los vectores se generen aleatoriamente (1) o desea ingresar la data (2): " << endl;
	cin >> des;
	
	if (des == 2) {
		vecs = ingreso_Data(n, m);
	}
	else {
		//vecs salen de una funcion aleatoria
		vecs = random_Data(n, m);

	}


	for (int i = 0; i < m; i++) {
		for (int e = 0; e < n; e++) {
			cout << vecs[i][e];
		}
	}

	return 0;
}