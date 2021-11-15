#include <iostream>
#include <string>
#include "nodoColita.h"
using namespace std;

template <class T> class Cola{
private:
	NodoColita<T> *inicio;
	NodoColita<T> *ultimo;
public:
	Cola();
	bool isEmpty();
	void queue(T);
	T dequeue();
	bool revisar(char);
	void showStack();
};

template <class T> Cola<T>::Cola(){
	inicio = NULL;
	ultimo = NULL;
}

template <class T> bool Cola<T>::isEmpty(){
	if (inicio==NULL && ultimo==NULL){
		return true;
	}
	return false;
}
template <class T> void Cola<T>::queue(T patata){
	if (isEmpty()){
		NodoColita<T> * newNodoColita = new NodoColita<T>(patata);
		inicio = newNodoColita;
		ultimo = newNodoColita;
	}
	else{
		NodoColita<T> *newNodoColita = new NodoColita<T>(patata);
		ultimo->siguiente=newNodoColita;
		newNodoColita->anterior=ultimo;
		ultimo = newNodoColita;
	}
}
template <class T> T Cola<T>::dequeue(){
	if(!isEmpty()){
		if(inicio == ultimo){
			T temp = inicio->dato;
			free(inicio); 
			inicio = NULL;
			ultimo = NULL;
			return temp;
		}
		else{
			T temp = inicio->dato;
			NodoColita<T>* recuerdo = inicio->siguiente;
			recuerdo->anterior = NULL;
			free(inicio);
			inicio = recuerdo;
			return temp;
		}
	}
	return 0;
}
template <class T> bool Cola<T>::revisar(char texto){
	if (!isEmpty()){
		NodoColita<T>* temp = inicio;
		while(temp->siguiente != NULL){
			if (temp->dato==texto){
				temp->cantidad += 1;
				return true;
			}
			temp = temp->siguiente;
		}
		if (temp->dato==texto){
			temp->cantidad += 1;
			return true;
		}
	}
	return false;
}

template <class T> void Cola<T>::showStack(){
	cout << "Histograma:" << endl;
	if (!isEmpty()){
		NodoColita<T>* temp = inicio;
		while(temp->siguiente != NULL){
			cout << temp->dato << " " << (int)temp->dato <<  "\t";
			for (int i=0; i<temp->cantidad;i++){
				cout << "X";
			}
			cout << endl;
			temp = temp->siguiente;
		}
		cout << temp->dato << " " << (int)temp->dato <<  "\t";
		for (int i=0; i<temp->cantidad;i++){
			cout << "X";
		}
		cout << endl;
	}
	else{
		cout << "No hay datos en la pila" << endl;
	}
}
