#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct mineral{
	int registro;
	char nombre[50];
	float pureza;
	int clase;
	char origen[50];
	char color[50];
	char transparente[50];
	struct mineral* siguiente, *anterior;
}mineral;
struct mineral* primero, * ultimo, *actual;
void mostrar_menu() {
    printf("\n\nMenú:\n=====\n\n");
    printf("1.- Añadir elemento\n");
    printf("2.- Borrar elemento\n");
    printf("3.- Mostrar lista\n");
	printf("4.- Consultar por nombre\n");
	printf("5.- Consultar por registro\n");
	printf("6.- Mover a la derecha\n");
	printf("7.- Mover a la izquierda\n");
    printf("8.- Salir\n\n");
    printf("Escoge una opción: ");
    fflush(stdout);
}
/* Con esta función añadimos un elemento al final de la lista */
void anadir_elemento() {
    struct mineral* nuevo;

    /* reservamos memoria para el nuevo elemento */
    nuevo = (struct mineral*) malloc(sizeof(struct mineral));

    if (nuevo == NULL) {
        printf("No hay memoria disponible!\n");
    }
    else {
        printf("\nNuevo elemento:\n");
        printf("Nombre: ");
        fflush(stdout);
        scanf(" %20[^\n]s",nuevo->nombre);
        printf("Color: ");
        fflush(stdout);
        scanf(" %12[^\n]s",nuevo->color);
		printf("Clase: ");
        fflush(stdout);
        scanf("%d",&(nuevo->clase));
		printf("Origen: ");
        fflush(stdout);
        scanf(" %20[^\n]s",nuevo->origen);
		printf("Pureza: ");
        fflush(stdout);
        scanf("%f",&(nuevo->pureza));
		printf("Transparencia: ");
        fflush(stdout);
        scanf(" %20[^\n]s",nuevo->transparente);

        /* el campo siguiente va a ser NULL por ser el último
        elemento de la lista */

        nuevo->siguiente = NULL;

        /* ahora metemos el nuevo elemento en la lista. lo situamos
        al final de la lista, se comprueba si la lista está vacía.
        si primero==NULL es que no hay ningún elemento en la lista.
        también vale ultimo==NULL */

        if (primero == NULL) {
            printf("Primer elemento\n");
			nuevo->registro=1;
            primero = nuevo;
            ultimo = nuevo;
			nuevo->anterior=NULL;
			actual = nuevo;
        }
        else {
			nuevo->registro = ultimo->registro+1;
			ultimo->siguiente = nuevo;
            /* el hasta ahora último apuntará al nuevo */
            ultimo->siguiente = nuevo;
            /* hacemos que el nuevo sea ahora el último */
            ultimo = nuevo;
        }
    }
}
void derecha(){
	if (actual==NULL){
		printf("La lista no tiene datos a la derecha, no se puede desplazar\n");
	}
	else{
		if(actual->siguiente==NULL){
			printf("No hay elementos a la derecha");
		}
		else{
			actual = actual->siguiente;
			printf("se ha movido a la derecha");
		}
	}
}
void izquierda(){
	if (actual==NULL){
		printf("La lista no tiene datos a la izquierda, no se puede desplazar\n");
	}
	else{
		if (actual->anterior=NULL){
			printf("No hay elementos a la izquierda");
		}
		else{
			actual=actual->anterior;
			printf("se ha movido a la izquierda");
		}
	}
}
int eliminar(){
	int elem;
	struct mineral* auxiliar, *anterior;
	auxiliar = primero; 
	printf("Digite el registro que desea eliminar: ");
	scanf(" %d",&elem);
	if (elem == primero->registro){
		primero = primero-> siguiente;
		if (primero == NULL){
			ultimo = NULL;
		}
		auxiliar->siguiente = NULL;
		free(auxiliar);	
		return 0;
	}
	anterior = auxiliar;
	auxiliar = auxiliar->siguiente;
	while(auxiliar!= NULL){
		if ((auxiliar->registro) == elem){
			anterior->siguiente = auxiliar->siguiente;
			auxiliar->siguiente = NULL;
			if (auxiliar == ultimo){
				ultimo=anterior;
			}
			free(auxiliar);
			return 0;	
		}
		auxiliar = auxiliar->siguiente;
		anterior = anterior->siguiente;
	}
}
void mostrar_lista() {
    struct mineral* auxiliar; /* para recorrer la lista */
    int i; i = 0;
    auxiliar = primero;
    printf("\nMostrando la lista completa:\n");
    while (auxiliar != NULL) {
        printf("Registro: %d, Nombre: %s, Color: %s, Pureza: %lf, Origen: %s, Clase: %d, Transparente: %s\n",auxiliar->registro, auxiliar->nombre,auxiliar->color, auxiliar->pureza,auxiliar->origen,auxiliar->clase,auxiliar->transparente);
        auxiliar = auxiliar->siguiente;
        i++;
    }
    if (i == 0) {
        printf("\nLa lista está vacía!!\n");
    }
}
int revisar(char elem1[100], struct mineral *point,int a){
	int res = 1;
	for (int i=0;i<a;i++){
		if (point->nombre[i]!= elem1[i]){
			return 0;
		}
	}
	return res;
}
int consultar_nombre(){
	char elem[50];
	int i=0;
	struct mineral* auxiliar;
	auxiliar = primero;
	printf("Digite el nombre a consultar: ");
	scanf(" %20[^\n]s", elem);
	while (auxiliar != NULL){
		if (revisar(elem,auxiliar,strlen(elem)) == 1){
			printf("Registo: %d, Nombre: %s, Color: %s, Pureza: %lf, Origen: %s, Clase: %d, Transparente: %s\n", auxiliar->registro, auxiliar->nombre,auxiliar->color, auxiliar->pureza,auxiliar->origen,auxiliar->clase,auxiliar->transparente);
			return 0;
		}
		auxiliar = auxiliar->siguiente;
        i++;
	}
	if (i==0){
		printf("No hay registros en la lista\n");
	}
	else{
		printf("\nNo se ha encontrado el registro\n");
	}
}
int consultar_registro(){
	int elem,i=0;
	struct mineral* auxiliar;
	auxiliar = primero;
	printf("Digite el registro a consultar: ");
	scanf(" %d",&elem);
	while(auxiliar!=NULL){
		if ((auxiliar->registro) == elem){
			printf("Registo: %d, Nombre: %s, Color: %s, Pureza: %lf, Origen: %s, Clase: %d, Transparente: %s\n", auxiliar->registro, auxiliar->nombre,auxiliar->color, auxiliar->pureza,auxiliar->origen,auxiliar->clase,auxiliar->transparente);
			return 0;
		}
		auxiliar = auxiliar->siguiente;
	}
	if (i==0){
		printf("\nNo hay datos en la lista");
	}
	else{
		printf("\nNo se ha encontrado el registro");
	}
}
void main() {
    char opcion;
    primero = (struct mineral*) NULL;
    ultimo = (struct mineral*) NULL;
	
    do {
        mostrar_menu();
        scanf(" %c",&opcion);
        switch (opcion) {
        case '1': anadir_elemento(); break;
        case '2': eliminar(); break;
        case '3': mostrar_lista(primero); break;
        case '4': consultar_nombre(); break;
		case '5': consultar_registro(); break;
		case '6': derecha();break;
		case '7': izquierda(); break; 
		case '8': exit(1);
        default:
            printf("Opción no válida\n");
            break;
        }
    } while (opcion != '8');
}
