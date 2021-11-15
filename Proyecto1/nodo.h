#include <iostream>
#include <string>
#include "nodoNum.h"
using namespace std; 

template <class T> class Nodo{	
public:
	T dato;
	nodoNum<int>* pos;
	Nodo<T>* siguiente;
	nodoNum<int>* ultimo;
	Nodo(T,int);
	void insertarPos(int);
};

template <class T> Nodo<T>::Nodo(T datos,int posicion){
	dato = datos;
	pos = new nodoNum<int>(posicion);
	ultimo = pos;
	siguiente = NULL;
}

template <class T> void Nodo<T>::insertarPos(int pos){
	nodoNum<int> *auxiliar = new nodoNum<int>(pos);
	ultimo->siguiente = auxiliar;
	ultimo = auxiliar; 
}
