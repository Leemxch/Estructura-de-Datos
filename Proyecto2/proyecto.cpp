#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main(){
	int opcion;
	string nombre;
	getline(cin,nombre);
	while(true){
		cout << "Seleccione una dificultad" << endl;
		cout << "1. Starter" << endl;
		cout << "2. Junior" << endl;
		cout << "3. Expert" << endl;
		cout << "4. Master" << endl;
		cin>>opcion;
		cin.ignore();
		if (opcion == 1 || opcion == 2){
			if (opcion == 1){
				cout << "starter"<< endl;
				break;
			}
			else{
				if (opcion == 2){
					cout << "junior" << endl;
					break;
				}
			}
		}
		else{
			if (opcion == 3){
				cout << "expert" << endl;
				break;
			}
			else{
				if (opcion == 4){
					cout << "master" << endl;
					break;
				}
			}
		}
	}
	system("clear");
	cout << nombre << endl;
	return 0;
}
