#include <stdio.h>
#include <stdlib.h>
struct _agenda {
    int registro;
    char nombre[20];
    char telefono[12];
    struct _agenda* siguiente;
};
struct _agenda* primero, * ultimo;

void mostrar_menu() {
    printf("\n\nMenú:\n=====\n\n");
    printf("1.- Añadir elementos\n");
    printf("2.- Borrar elementos\n");
    printf("3.- Mostrar lista\n");
    printf("4.- Consultar por registro\n");
    printf("5.- Salir\n\n");
    printf("Escoge una opción: ");
    fflush(stdout);
}
/* Con esta función añadimos un elemento al final de la lista */
void anadir_elemento() {
    struct _agenda* nuevo;

    /* reservamos memoria para el nuevo elemento */
    nuevo = (struct _agenda*) malloc(sizeof(struct _agenda));

    if (nuevo == NULL) {
        printf("No hay memoria disponible!\n");
    }
    else {
        printf("\nNuevo elemento:\n");
        printf("Nombre: ");
        fflush(stdout);
        scanf(" %20[^\n]s", nuevo->nombre);
        printf("Teléfono: ");
        fflush(stdout);
        scanf(" %12[^\n]s", nuevo->telefono);

        /* el campo siguiente va a ser NULL por ser el último
        elemento de la lista */

        nuevo->siguiente = NULL;

        /* ahora metemos el nuevo elemento en la lista. lo situamos
        al final de la lista, se comprueba si la lista está vacía.
        si primero==NULL es que no hay ningún elemento en la lista.
        también vale ultimo==NULL */

        if (primero == NULL) {
            printf("Primer elemento\n");
            nuevo->registro = 1; /* se le asume el primer registro*/
            primero = nuevo;
            ultimo = nuevo;
        }
        else {
            /* el registro del dato creado, usa el dato el ultimo para sumarle 1 */
                nuevo->registro = (ultimo->registro) + 1;
            /* el hasta ahora último apuntará al nuevo */
            ultimo->siguiente = nuevo;
            /* hacemos que el nuevo sea ahora el último */
            ultimo = nuevo;
        }
    }
}
/*void eliminar(){
    struct _agenda auxiliar, *primero;
    primero = *auxiliar;
    auxiliar = auxiliar->siguiente;
    while(auxiliar!=NULL){
        if (encontrado==0){
            anterior = auxiliar;
            auxiliar = auxiliar->siguiente;

    }
    if (auxiliar == NULL){
        if (auxiliar == *_agenda){
            *_agenda = auxiliar->siguiente;
        }
        else{
            anterior->siguiente = actual->siguiente;
        }
        free(auxiliar);
    }
}*/
void mostrar_lista() {
    struct _agenda* auxiliar; /* para recorrer la lista */
    int i; i = 0;
    auxiliar = primero;
    printf("\nMostrando la lista completa:\n");
    while (auxiliar != NULL) {
        printf("Registro: %d, Nombre: %s, Telefono: %s\n", auxiliar->registro, auxiliar->nombre, auxiliar->telefono);
        auxiliar = auxiliar->siguiente;
        i++;
    }
    if (i == 0) {
        printf("\nLa lista está vacía!!\n");
    }
}
void consultar() {
    int elem;
    int i = 0;
    struct _agenda* auxiliar;
    printf("Digite el registro a consultar: ");
    scanf(" %d", &elem);
    printf("holiwis piwis");
    printf("%d", elem);
    printf("odio esto");
    while (auxiliar != NULL) {
        printf("%d", i);
        if (auxiliar->registro == elem) {
            printf("Registro: %d, Nombre: %s, Telefono: %s\n", auxiliar->registro, auxiliar->nombre, auxiliar->telefono);
        }
        auxiliar = auxiliar->siguiente;
        i++;
    }
    if (i == 0) {
        printf("No hay registros en la lista\n");
    }
    else {
        printf("No se ha encontrado el registro\n");
    }
}
void main() {
    char opcion;
    primero = (struct _agenda*) NULL;
    ultimo = (struct _agenda*) NULL;
    do {
        mostrar_menu();
        scanf(" %c", &opcion);
        switch (opcion) {
        case '1': anadir_elemento(); break;
        case '2': printf("aun no") /* eliminar() */ ; break;
        case '3': mostrar_lista(primero); break;
        case '4': consultar(); break;
        case '5': exit(1);
        default:
            printf("Opción no válida\n");
            break;
        }
    } while (opcion != '5');
}