#include <iostream>
using namespace std;

//ALGORITMO QUICKSORT (ORDENAMIENTO)
void qs(int *num, int lim_izq, int lim_der){
	int izq = lim_izq,
		der = lim_der,
		pivote = num[(izq + der) / 2],
		temporal;

	//4,6,7,3,8,5,9
	do{
		while (num[izq]<pivote && izq<lim_der) izq++;
		while (pivote<num[der] && der > lim_izq) der--;
		if (izq <= der){
			temporal = num[izq];
			num[izq] = num[der];
			num[der] = temporal;
			izq++;
			der--;
		}
	} while (izq <= der);
	if (lim_izq<der) qs(num, lim_izq, der);
	if (lim_der>izq) qs(num, izq, lim_der);
}

void mostrarEnteros(int *num, int tamano){
	cout << "[";
	for (int i = 0; i < tamano; i++)
		cout << num[i] << " ";
	cout << "]" << endl;
}

void mostrarLetras(char *letra, int tamano){
	cout << "[";
	for (int i = 0; i < tamano; i++)
		cout << letra[i] << " ";
	cout << "]" << endl;
}

void quicksort(int *num, int n){
	qs(num, 0, n - 1);//arreglo,izquierdo,derecho
}
//FIN ALGORITMO QUICKSORT

void busquedaBinaria(int *num, int tamano, int buscar){
	int max = tamano - 1,
		min = 0,
		medio;
	while (min + 1<max){
		medio = (max + min) / 2;
		if (num[medio] == buscar){
			cout << " Elemento Encontrado en la pocision " << medio + 1 << endl;
			return;
		}
		if (num[medio]<buscar) min = medio;
		if (num[medio]>buscar) max = medio;
	}
	cout << " El Elemento no se encontro " << endl;
}

void busquedaSecuencial(char *palabra, int tamano, char buscar){
	for (int i = 0; i<tamano; i++)
	if (palabra[i] == buscar)
		cout << " Elemento encontrado en la pocision " << i << endl;
}


int main(int argc, char const *argv[]){
	//vector de enteros 32,60,8,5,73,45,3,20
	int temporal[] = { 32, 60, 8, 5, 73, 45, 3, 20 };
	int tamano = sizeof(temporal) / sizeof(int);//Tamaño del vector
	cout << endl << "---- EJEMPLO PARA BUSQUEDA BINARIA ------" << endl;
	cout << " Enteros Desordenados : " << endl;
	mostrarEnteros(temporal, tamano);//mostrando enteros desordenamente
	quicksort(temporal, tamano);// ORDENADO ->  3,5,8,20,32,45,60,73
	cout << endl << " Enteros Ordenados : " << endl;
	mostrarEnteros(temporal, tamano);//mostrando enteros ordenados

	cout << endl << " Busqueda Binaria para encontrar el " << " 60 --> " << endl << endl;
	busquedaBinaria(temporal, tamano, 60);//busca el numero
	cout << endl << " Busqueda Binaria para encontrar el " << " 80 --> " << endl << endl;
	busquedaBinaria(temporal, tamano, 80);//busca el numero
	cout << endl << "---- EJEMPLO PARA BUSQUEDA SECUENCIAL ------" << endl<<endl;
	cout << "Letras en nuestro vector : " << endl;
	char palabra[] = { 'i', 'n', 'f', 'o', 'r', 'm', 'a', 't', 'i', 'c', 'a' };
	tamano = sizeof(palabra) / sizeof(char);
	mostrarLetras(palabra, tamano);
	cout << endl << " Busqueda Secuencial para encontrar la letra " << " 'c' " << endl << endl;
	busquedaSecuencial(palabra, tamano, 'c');
	return 0;
}