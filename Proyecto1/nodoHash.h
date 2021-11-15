#include <iostream>
#include <string>
#include "nodo.h"
using namespace std; 

template <class T> class nodoHash{	
public:
	char letra;
	Nodo<string>* lista;
	Nodo<string>* ultimo;
	nodoHash* siguiente;
	nodoHash* anterior;
	nodoHash(char);
};

template <class T> nodoHash<T>::nodoHash(char caracter){
	letra = caracter;
	lista = NULL;
	ultimo = NULL;
	siguiente = NULL;
	anterior = NULL;
}
