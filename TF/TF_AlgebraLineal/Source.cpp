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

double** newOne(int fils, int cols) {
	double** m = new double* [fils];
	for (int j = 0; j < fils; j++)
		m[j] = new double[cols];
	return m;
}

double** m_copy(double** matrix, int n, int cols) {
	double** aux = newOne(n, cols);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < cols; j++)
			aux[i][j] = matrix[i][j];
	return aux;
}

void opArr(double* arr, int n, int value, string tipo) {

	for (short i = 0; i < n; i++) {
		if ("+" == tipo)
			arr[i] += value;
		else if ("-" == tipo)
			arr[i] -= value;
		else if ("*" == tipo)
			arr[i] *= value;
		else if ("/" == tipo)
			arr[i] /= value;
	}
}

int numFVacias(double** Matrix, int n) {
	int rango = n;
	int cont = 0;
	for (char i = 0; i < n; i++) {
		for (char c = 0; c < n; c++)
			if (Matrix[i][c] == 0)
				cont++;
		if (cont == n)
			rango--;
		cont = 0;
	}
	return rango;
}

int Rango(int n, double** Matrix) {
	double* aux = new double[n];
	double** A = m_copy(Matrix, n, n);

	for (int f = 0; f < n - 2; f++) {
		//convertir el primer elemento de la fila en 1
		for (int bajada = f; bajada < n - 1; bajada++) {
			for (int i = f; i < n; i++) {
				aux[i] = (A[f][i] / A[f][f]);
			}
			//multiplicalo por el número que quieres convertir en 0
			opArr(aux, n, A[bajada + 1][f], "*");
			for (int i = f; i < n; i++) {
				A[bajada + 1][i] -= aux[i];
			}
		}
		//esto es para mostrar como queda la matriz
		//show(A, n, n); cout << endl; _getch();
	}
	return numFVacias(A, n);
}

int main() {
	//Dimension en la que estamos trabajando
	int n = 0;
	//Cantidad de vectores
	int m = 0;
	int** vecs;
	
	//llenando la data
	vecs = data(n, m);


	cout <<"n: " << n << " m: " << m << endl;
	//mostrando la matriz
	for (int i = 0; i < m; i++) {
		for (int e = 0; e < n; e++) {
			cout << vecs[i][e] << " " ;
		}
		cout << endl;
	}

	return 0;
}