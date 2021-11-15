#include <iostream>
#include <string>
#include "nodoHash.h"
using namespace std;

template <class T> class tablaHash{
private:
	nodoHash<T>* inicioNum;
	nodoHash<T>* ultimoNum;
	nodoHash<T>* inicioLetra;
	nodoHash<T>* ultimoLetra;
	nodoHash<T>* inicioLetraMayus;
	nodoHash<T>* ultimoLetraMayus;

	
public:
	tablaHash();
	bool insert(string,int);
	void mostrarDatos();
	void mostrarDatosPos();
	string buscar(string);
};

template <class T> tablaHash<T>::tablaHash(){
	inicioNum = new nodoHash<T>('0');
	ultimoNum = inicioNum;
	for (int i=0; i<10;i++){
		nodoHash<T>* newNodo = new nodoHash<T>('1'+i);
		ultimoNum->siguiente=newNodo;
		newNodo->anterior=ultimoNum;
		ultimoNum = newNodo;
	}
	inicioLetra = new nodoHash<T>('a');
	ultimoLetra = inicioLetra;
	for (int i=0; i<25;i++){
		nodoHash<T>* newNodo = new nodoHash<T>('b'+i);
		ultimoLetra->siguiente=newNodo;
		newNodo->anterior=ultimoLetra;
		ultimoLetra = newNodo;
	}
	inicioLetraMayus = new nodoHash<T>('A');
	ultimoLetraMayus = inicioLetraMayus;
	for (int i=0; i<25;i++){
		nodoHash<T>* newNodo = new nodoHash<T>('B'+i);
		ultimoLetraMayus->siguiente=newNodo;
		newNodo->anterior=ultimoLetraMayus;
		ultimoLetraMayus = newNodo;
	}
}

template <class T> bool tablaHash<T>::insert(string patata, int pos){
	if (patata[0] >= '0' && patata[0] <= '9'){
		nodoHash<T>* auxiliar = inicioNum;
		for(int i=0; i<patata[0]-'0';i++){
			 auxiliar = auxiliar->siguiente;
		}
		Nodo<string>* auxiliarNodo = auxiliar->lista;
		while(auxiliarNodo != NULL){
			if (auxiliarNodo->dato == patata){
				auxiliarNodo->insertarPos(pos);
				return true;
			}
			auxiliarNodo = auxiliarNodo->siguiente;
		} 
		Nodo<string>* newNodo = new Nodo<string>(patata,pos);
		if (auxiliar->lista == NULL){
			auxiliar->lista = newNodo;
			auxiliar->ultimo = newNodo;
		}
		else{
			Nodo<string>* auxiliar2 = auxiliar->ultimo;
			auxiliar2->siguiente = newNodo;
			auxiliar->ultimo = newNodo; 
		}
		return true;
	}
	else{
		if (patata[0] >= 'a' && patata[0] <= 'z'){
			if (patata[0] >= 'a' && patata[0] <= 'n'){
				nodoHash<T>* auxiliar = inicioLetra;
				for(int i=0; i<patata[0]-'a';i++){
					 auxiliar = auxiliar->siguiente;
				}
				Nodo<string>* auxiliarNodo = auxiliar->lista;
				while(auxiliarNodo != NULL){
					if (auxiliarNodo->dato == patata){
						auxiliarNodo->insertarPos(pos);
						return true;
					}
					auxiliarNodo = auxiliarNodo->siguiente;
				} 
				Nodo<string>* newNodo = new Nodo<string>(patata,pos);
				if (auxiliar->lista == NULL){
					auxiliar->lista = newNodo;
					auxiliar->ultimo = newNodo;
				}
				else{
					Nodo<string>* auxiliar2 = auxiliar->ultimo;
					auxiliar2->siguiente = newNodo;
					auxiliar->ultimo = newNodo; 
				}
				return true;
			}
			else{
				nodoHash<T>* auxiliar = ultimoLetra;
				for(int i=0; i<'z'-patata[0];i++){
					 auxiliar = auxiliar->anterior;
				}
				Nodo<string>* auxiliarNodo = auxiliar->lista;
				while(auxiliarNodo != NULL){
					if (auxiliarNodo->dato == patata){
						auxiliarNodo->insertarPos(pos);
						return true;
					}
					auxiliarNodo = auxiliarNodo->siguiente;
				} 
				Nodo<string>* newNodo = new Nodo<string>(patata,pos);
				if (auxiliar->lista == NULL){
					auxiliar->lista = newNodo;
					auxiliar->ultimo = newNodo;
				}
				else{
					Nodo<string>* auxiliar2 = auxiliar->ultimo;
					auxiliar2->siguiente = newNodo;
					auxiliar->ultimo = newNodo; 
				}
				return true;
			}
		}
		else{
			if (patata[0] >= 'A' && patata[0] <= 'N'){
				nodoHash<T>* auxiliar = inicioLetraMayus;
				for(int i=0; i<patata[0]-'A';i++){
					 auxiliar = auxiliar->siguiente;
				}
				Nodo<string>* auxiliarNodo = auxiliar->lista;
				while(auxiliarNodo != NULL){
					if (auxiliarNodo->dato == patata){
						auxiliarNodo->insertarPos(pos);
						return true;
					}
					auxiliarNodo = auxiliarNodo->siguiente;
				} 
				Nodo<string>* newNodo = new Nodo<string>(patata,pos);
				if (auxiliar->lista == NULL){
					auxiliar->lista = newNodo;
					auxiliar->ultimo = newNodo;
				}
				else{
					Nodo<string>* auxiliar2 = auxiliar->ultimo;
					auxiliar2->siguiente = newNodo;
					auxiliar->ultimo = newNodo; 
				}
				return true;
			}
			else{
				nodoHash<T>* auxiliar = ultimoLetraMayus;
				for(int i=0; i<'Z'-patata[0];i++){
					 auxiliar = auxiliar->anterior;
				}
				Nodo<string>* auxiliarNodo = auxiliar->lista;
				while(auxiliarNodo != NULL){
					if (auxiliarNodo->dato == patata){
						auxiliarNodo->insertarPos(pos);
						return true;
					}
					auxiliarNodo = auxiliarNodo->siguiente;
				} 
				Nodo<string>* newNodo = new Nodo<string>(patata,pos);
				if (auxiliar->lista == NULL){
					auxiliar->lista = newNodo;
					auxiliar->ultimo = newNodo;
				}
				else{
					Nodo<string>* auxiliar2 = auxiliar->ultimo;
					auxiliar2->siguiente = newNodo;
					auxiliar->ultimo = newNodo; 
				}
				return true;
			}
		}
		
	}
	return false;
}
template <class T> void tablaHash<T>::mostrarDatos(){
	nodoHash<T>* auxiliar = inicioNum;
	for(int i=0; i<10;i++){
		if(auxiliar->lista != NULL){
			Nodo<string>* auxiliar2 = auxiliar->lista;
			cout << auxiliar->letra << ": ";
			while (auxiliar2 != NULL){
				cout << auxiliar2->dato;
				if(auxiliar2->siguiente != NULL){
					cout << ", ";
				}
				auxiliar2 = auxiliar2->siguiente;
			}
			cout << "\n";
		}
		auxiliar = auxiliar->siguiente;
	}
	nodoHash<T>* auxiliar3 = inicioLetra;
	for(int i=0; i<26;i++){
		if (auxiliar3->lista != NULL){
			Nodo<string>* auxiliar4 = auxiliar3->lista;
			cout << auxiliar3->letra << ": ";
			while (auxiliar4 != NULL){
				cout << auxiliar4->dato;
				if(auxiliar4->siguiente != NULL){
					cout << ", ";
				}
				auxiliar4 = auxiliar4->siguiente;
			}
			cout << "\n";
		}
		auxiliar3 = auxiliar3->siguiente;
	}
	nodoHash<T>* auxiliar5 = inicioLetraMayus;
	for(int i=0; i<26;i++){
		if (auxiliar5->lista != NULL){
			Nodo<string>* auxiliar6 = auxiliar5->lista;
			cout << auxiliar5->letra << ": ";
			while (auxiliar6 != NULL){
				cout << auxiliar6->dato;
				if(auxiliar6->siguiente != NULL){
					cout << ", ";
				}
				auxiliar6 = auxiliar6->siguiente;
			}
			cout << "\n";
		}
		auxiliar5 = auxiliar5->siguiente;
	}
}

template <class T> void tablaHash<T>::mostrarDatosPos(){
	nodoHash<T>* auxiliar = inicioNum;
	for(int i=0; i<10;i++){
		if (auxiliar->lista!=NULL){
			Nodo<string>* auxiliar2 = auxiliar->lista;
			cout << auxiliar->letra << ": ";
			while (auxiliar2 != NULL){
				cout << auxiliar2->dato << " || ";
				nodoNum<int>* auxiliar5 = auxiliar2->pos;
				while(auxiliar5 != NULL){
					cout << auxiliar5->pos;
					if(auxiliar5->siguiente != NULL){
						cout << ", ";
					}
					auxiliar5 = auxiliar5->siguiente;
				}
				auxiliar2 = auxiliar2->siguiente;
			}
			cout << "\n";
		}
		auxiliar = auxiliar->siguiente;
	}
	nodoHash<T>* auxiliar3 = inicioLetra;
	for(int i=0; i<26;i++){
		if (auxiliar3->lista != NULL){
			Nodo<string>* auxiliar4 = auxiliar3->lista;
			cout << auxiliar3->letra << ": ";
			while (auxiliar4 != NULL){
				cout << auxiliar4->dato << " || ";
				nodoNum<int>* auxiliar6 = auxiliar4->pos;
				while(auxiliar6 != NULL){
					cout << auxiliar6->pos;
					if(auxiliar6->siguiente != NULL){
						cout << ", ";
					}
					auxiliar6 = auxiliar6->siguiente;
				}
				auxiliar4 = auxiliar4->siguiente;
			}
			cout << "\n";
		}
		auxiliar3 = auxiliar3->siguiente;
	}
	nodoHash<T>* auxiliar7 = inicioLetraMayus;
	for(int i=0; i<26;i++){
		if (auxiliar7->lista != NULL){
			Nodo<string>* auxiliar8 = auxiliar7->lista;
			cout << auxiliar7->letra << ": ";
			while (auxiliar8 != NULL){
				cout << auxiliar8->dato << " || ";
				nodoNum<int>* auxiliar9 = auxiliar8->pos;
				while(auxiliar9 != NULL){
					cout << auxiliar9->pos;
					if(auxiliar9->siguiente != NULL){
						cout << ", ";
					}
					auxiliar9 = auxiliar9->siguiente;
				}
				auxiliar8 = auxiliar8->siguiente;
			}
			cout << "\n";
		}
		auxiliar7 = auxiliar7->siguiente;
	}
}

template <class T> string tablaHash<T>::buscar(string patata){
	string texto = "";
	if (patata[0] >= '0' && patata[0] <= '9'){
		nodoHash<T>* auxiliar = inicioNum;
		for(int i=0; i<patata[0]-'0';i++){
			 auxiliar = auxiliar->siguiente;
		}
		Nodo<string>* auxiliarNodo = auxiliar->lista;
		while(auxiliarNodo != NULL){
			if (auxiliarNodo->dato == patata){
				texto += "posiciones: ";
				nodoNum<int>* recorrido = auxiliarNodo->pos;
				int count=0;
				while(recorrido!=NULL){
					texto += to_string(recorrido->pos);
					count++;
					if (recorrido->siguiente != NULL){
						texto += ", ";
					}
					recorrido = recorrido->siguiente;
				}
				texto += " cantidad: " + to_string(count);
				return texto;
			}
			auxiliarNodo = auxiliarNodo->siguiente;
		}
	}
	else{
		if (patata[0] >= 'a' && patata[0] <= 'z'){
			if (patata[0] >= 'a' && patata[0] <= 'n'){
				nodoHash<T>* auxiliar = inicioLetra;
				for(int i=0; i<patata[0]-'a';i++){
					 auxiliar = auxiliar->siguiente;
				}
				Nodo<string>* auxiliarNodo = auxiliar->lista;
				while(auxiliarNodo != NULL){
					if (auxiliarNodo->dato == patata){
						texto += "posiciones: ";
						nodoNum<int>* recorrido = auxiliarNodo->pos;
						int count=0;
						while(recorrido!=NULL){
							texto += to_string(recorrido->pos);
							count++;
							if (recorrido->siguiente != NULL){
								texto += ", ";
							}
							recorrido = recorrido->siguiente;
						}
						texto += " cantidad: " + to_string(count);
						return texto;
					}
					auxiliarNodo = auxiliarNodo->siguiente;
				}
			}
			else{
				nodoHash<T>* auxiliar = ultimoLetra;
				for(int i=0; i< 'z' - patata[0];i++){
					 auxiliar = auxiliar->anterior;
				}
				Nodo<string>* auxiliarNodo = auxiliar->lista;
				while(auxiliarNodo != NULL){
					if (auxiliarNodo->dato == patata){
						texto += "posiciones: ";
						nodoNum<int>* recorrido = auxiliarNodo->pos;
						int count=0;
						while(recorrido!=NULL){
							texto += to_string(recorrido->pos);
							count++;
							if (recorrido->siguiente != NULL){
								texto += ", ";
							}
							recorrido = recorrido->siguiente;
						}
						texto += " cantidad: " + to_string(count);
						return texto;
					}
					auxiliarNodo = auxiliarNodo->siguiente;
				}
			}
		}
		else{
			if (patata[0] >= 'A' && patata[0] <= 'N'){
				nodoHash<T>* auxiliar = inicioLetraMayus;
				for(int i=0; i<patata[0]-'A';i++){
					 auxiliar = auxiliar->siguiente;
				}
				Nodo<string>* auxiliarNodo = auxiliar->lista;
				while(auxiliarNodo != NULL){
					if (auxiliarNodo->dato == patata){
						texto += "posiciones: ";
						nodoNum<int>* recorrido = auxiliarNodo->pos;
						int count=0;
						while(recorrido!=NULL){
							texto += to_string(recorrido->pos);
							count++;
							if (recorrido->siguiente != NULL){
								texto += ", ";
							}
							recorrido = recorrido->siguiente;
						}
						texto += " cantidad: " + to_string(count);
						return texto;
					}
					auxiliarNodo = auxiliarNodo->siguiente;
				}
			}
			else{
				nodoHash<T>* auxiliar = ultimoLetraMayus;
				for(int i=0; i<'Z'-patata[0];i++){
					 auxiliar = auxiliar->anterior;
				}
				Nodo<string>* auxiliarNodo = auxiliar->lista;
				while(auxiliarNodo != NULL){
					if (auxiliarNodo->dato == patata){
						texto += "posiciones: ";
						nodoNum<int>* recorrido = auxiliarNodo->pos;
						int count=0;
						while(recorrido!=NULL){
							texto += to_string(recorrido->pos);
							count++;
							if (recorrido->siguiente != NULL){
								texto += ", ";
							}
							recorrido = recorrido->siguiente;
						}
						texto += " cantidad: " + to_string(count);
						return texto;
					}
					auxiliarNodo = auxiliarNodo->siguiente;
				}
			}
		}
		
	}
	return "No se encuentra";
}
