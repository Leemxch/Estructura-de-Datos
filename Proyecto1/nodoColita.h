#include <iostream>
using namespace std; 

template <class T> class NodoColita{	
public:
	T dato;
	int cantidad;
	NodoColita* siguiente;
	NodoColita* anterior;
	NodoColita(T);
	int getCantidad();
	void setCantidad(int);
};

template <class T> NodoColita<T>::NodoColita(T datos){
	dato = datos;
	cantidad = 1;
	siguiente = NULL;
	anterior = NULL;
}
