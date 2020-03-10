#include <stdio.h>
/*Programa que retorna los datos ingresados por el usuario*/
void hotel(){
	int c,i=0,count=0;
	char piso[1000];
	char puntaje[1000];
	char nombre[100];
	char clase[100];
	char cuarto[1000];
	printf("\tIngrese los datos del hotel en orden:\n");
	printf("Nombre del hotel:\n");
	printf("Pisos totales:\n");
	printf("Clase:\n\te=Economico\n\tm=Medio\n\tc=Calidad\n");
	printf("Cantidad de cuartos:\n");
	printf("Puntaje entre 1 y 10\n");
	while((c=getchar())!=EOF){
		if (count == 0){
			nombre[i]=c;
			i++;
		}
		if (count == 1){
			piso[i] = c;
			i++;
		}
		if (count == 2){
			clase[i] = c;	
			i++;
		}
		if (count == 3){
			cuarto[i] = c;
			i++;
		}
		if (count == 4){
			puntaje[i] = c;
			i++;
		}
		if (c == '\n'){
			count++;
			i = 0;
		}
	}
	printf("\nNombre: %s\n",nombre);
	printf("Pisos: %s\n",piso);
	printf("Clase: %s\n",clase);
	printf("Cantidad de cuartos: %s\n",cuarto);
	printf("Puntaje: %s\n",puntaje);
}
void main(){
	hotel();
}
