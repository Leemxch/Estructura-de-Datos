#include <iostream>
#include <string>
using namespace std; 

template <class T> class nodoNum{	
public:
	int pos;
	nodoNum<T>* siguiente;
	nodoNum<T>(int);
};

template <class T> nodoNum<T>::nodoNum(int posision){
	pos = posision;
	siguiente = NULL;
}
