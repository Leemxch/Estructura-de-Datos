#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <list>
#include <iterator>
#include <bits/stdc++.h>
#include "tablaHash.h"
#include "cola.h"
using namespace std;
/*
Funcion para leer un archivo de texto
*/
string leer(){
	fstream archivo("texto.txt");
	string linea;
	string texto;
	if (archivo.is_open()){
		while(getline(archivo,linea)){
			texto += linea + "\n";
		}
		archivo.close();
	}
	return texto;
}

/*
Funcion sensible a mayusculas
*/
void tokenizadorSens(tablaHash<char>* tabla, list<char> lista, string texto, bool sensible){
	list<char>::iterator revisar;
	string guardar = "";
	int contador = 0; 
	int contadorPalabras = 0;
	int cantidadCaracter = 0;
	for (int i=0; i<texto.length();i++){
		if (texto[i] == ' ' or texto[i] == '\n' or texto[i] == '\t' or texto[i] == '.'){
			if (!sensible){
				transform(guardar.begin(),guardar.end(),guardar.begin(),::tolower);
			}
			tabla->insert(guardar,contador);
			cantidadCaracter++;
			contadorPalabras++;
			contador += i+1;
			guardar = "";
		}
		else{
			for (revisar = lista.begin(); revisar != lista.end(); revisar++){
				if (*revisar == texto[i]){
					tabla->insert(guardar,contador);
					cantidadCaracter++;
					contadorPalabras++;
					i++;
					contador += i+1;
					guardar = "";
					break;
				}											
			}
			guardar += texto[i];
			cantidadCaracter++;
		}
	}
	cout << "Se han leido un total de: " << cantidadCaracter-1 << " de caracteres" << endl;
	cout << "Cantidad de palabras contadas de entrada: " << contadorPalabras << endl << endl;
}

/*
Funcion para mostrar los datos de entrada ordenados
*/
void tokenizadorMostrar(tablaHash<char>* tabla){
	tabla->mostrarDatos();
}

/*
Funcion para mostrar los datos de entrada ordenados y sus posiciones
*/
void tokenizadorPosMostrar(tablaHash<char>* tabla){
	tabla->mostrarDatosPos();
}

/*
Funcion para meter delimitadores a la lista
*/
list<char> delimitar(list<char> lista){
	char texto[10];
	cin >> texto;
	cin.ignore();
	lista.push_back(*texto);
	return lista;
}

/*
Funcion para reivsar delimitadores en la lista
*/
void revisarDelimitar(list<char> lista){ 
	list<char>::iterator revisar;
	cout << "Delimitadores:" << endl;
	for (revisar = lista.begin(); revisar != lista.end(); revisar++){
		cout << *revisar << endl;
	}
}

/*
Funcion para ver un histograma sensible a mayusculas
*/
void mayusculas(string texto){
	Cola<char> colita;
	for (int i=0; i<texto.length()-1; i++){
		bool resultado = colita.revisar(texto[i]);
		if (!resultado){
			colita.queue(texto[i]);
		}
	}
	colita.showStack();
}

/*
Funcion para ver un histograma no sensible a mayusculas
*/
void minusculas(string texto){
	Cola<char> colita;
	for (int j=0; j<texto.length()-1; j++){
		if (texto[j]<96 && texto[j]>64){
			texto[j] = texto[j] + 32;
		}
	}
	for (int i=0; i<texto.length(); i++){
		bool resultado = colita.revisar(texto[i]);
		if (!resultado){
			colita.queue(texto[i]);
		}
	}
	colita.showStack();
}

/*
	Main
*/
int main(){
	tablaHash<char>* tablita = new tablaHash<char>();
	list<char> delimitadores; 
	int opcion;
	bool sensible = false;
	string texto;
	string encontrar;
	while (true){
		cout << "¿Desea que sea sensible a mayusculas?" << endl;
		cout << "1. Si" << endl;
		cout << "2. No" << endl;
		cin >> opcion;
		cin.ignore();
		if (opcion == 1 || opcion == 2){
			if (opcion == 1){
				sensible = true;
				break;
			}
			break;
		}
	}
	do{
		cout << "======================================" << endl;
		cout << "Elija una de las opciones: " << endl;
		cout << "1. Ingresar texto" << endl;
		cout << "2. Token" << endl;
		cout << "3. Delimitadores" << endl;
		cout << "4. Revisar Delimitadores" << endl;
		cout << "5. Histograma" << endl;
		cout << "6. Mostrar diccionario" << endl;
		cout << "7. Mostrar diccionario con posicion" << endl;
		cout << "8. Buscar palabra" << endl;
		cout << "9. Limpiar datos" << endl;
		cout << "10. Salir" << endl;
		cout << "======================================" << endl;
		cin >> opcion;
		cin.ignore();
		switch(opcion){
			case 1:
				do{
					cout << "1. Usar la terminal" << endl;
					cout << "2. Usar un archivo" << endl;
					cout << "3. Atras" << endl;
					cin >> opcion;
					cin.ignore();
					switch(opcion){
						case 1:
						cout << "Ingrese el texto: "; 
						getline(cin,texto);
						texto += "\n";
						opcion = 3;
						break;
						case 2:
						texto = leer();
						opcion = 3;
						break;
						default:
						break;
					}
				}while (opcion!=3);
				break;
			case 2:
				tokenizadorSens(tablita, delimitadores, texto, sensible);
				break;
			case 3:
				delimitadores = delimitar (delimitadores);
				break;
			case 4:
				revisarDelimitar (delimitadores);
				break;
			case 5:
				if (sensible){
					mayusculas(texto);
				}
				else{
					minusculas(texto);
				}
				break;
			case 6:
				tokenizadorMostrar(tablita);
				break;
			case 7:
				tokenizadorPosMostrar(tablita);
				break;
			case 8:
				getline(cin, encontrar);
				if (sensible){
					encontrar=tablita->buscar(encontrar);
					cout << encontrar << endl;
				}
				else{
					transform(encontrar.begin(),encontrar.end(),encontrar.begin(),::tolower);
					encontrar=tablita->buscar(encontrar);
					cout << encontrar << endl;
				}
				break;
			case 9:
				delete(tablita);
				tablita = new tablaHash<char>();
				cout << "Se limpio la memoria con exito" << endl;
				break;
			case 10:
				cout << "Saliendo..." << endl;
				break;
			default:
				break;
			}
	}while (opcion != 10);
	return 0;
}
