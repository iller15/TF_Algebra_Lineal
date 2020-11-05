#include <iostream>
#include <time.h>
using namespace std;

int** ingreso_Data(int &n, int &m) {
	//los vectores que ingresa el usuario
	int** vecs;
	do {
		cout << "Ingrese la dimension en la que desee trabajar (entre 3 y 8): " << endl;
		cin >> n;
	} while (n > 8 || n < 3);

	do{
		cout << "Ingrese la cantidad de vectores con los que desea trabajar (entre 3 y 8): " << endl;
		cin >> m;
	} while (n > 8 || n < 3);

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

int** random_Data(int &n, int &m) {
	int** vecs;
	srand(time(NULL));
	n = rand() % 8 + 3;
	m = rand() % 8 + 3;

	vecs = new int* [m];

	for (int i = 0; i < m; i++) {
		int* aux = new int[n];
		for (char e = 0; e < n; e++) {
			aux[e] = rand() % 9 + 0;
		};
		vecs[i] = aux;
	};

	return vecs;
}

int** data(int &n,int &m) {
	int des;
	cout << "Desea que los vectores se generen aleatoriamente (1) o desea ingresar la data (2): " << endl;
	cin >> des;

	if (des == 2) {
		return ingreso_Data(n, m);
	}
	else {
		//vecs salen de una funcion aleatoria
		return random_Data(n, m);
	}
}

int main() {
	//Dimension en la que estamos trabajando
	int n = 0;
	//Cantidad de vectores
	int m = 0;
	int** vecs;
		

	vecs = data(n, m);


	cout <<"n: " << n << " m: " << m << endl;
	

	
	for (int i = 0; i < m; i++) {
		for (int e = 0; e < n; e++) {
			cout << vecs[i][e] << " " ;
		}
		cout << endl;
	}

	return 0;
}