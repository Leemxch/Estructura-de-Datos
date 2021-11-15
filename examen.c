#include <stdio.h>
#include <stdlib.h>

void mostrar(char gato[3][3]){
	char var0 = gato[0][0]!='X'&& gato[0][0]!='0'? ' ': gato[0][0];
	char var1 = gato[0][1]!='X'&& gato[0][1]!='0'? ' ': gato[0][1];
	char var2 = gato[0][2]!='X'&& gato[0][2]!='0'? ' ': gato[0][2];
	char var3 = gato[1][0]!='X'&& gato[1][0]!='0'? ' ': gato[1][0];
	char var4 = gato[1][1]!='X'&& gato[1][1]!='0'? ' ': gato[1][1];
	char var5 = gato[1][2]!='X'&& gato[1][2]!='0'? ' ': gato[1][2];
	char var6 = gato[2][0]!='X'&& gato[2][0]!='0'? ' ': gato[2][0];
	char var7 = gato[2][1]!='X'&& gato[2][1]!='0'? ' ': gato[2][1];
	char var8 = gato[2][2]!='X'&& gato[2][2]!='0'? ' ': gato[2][2];
	printf("Tabla:\n");
	printf("\t1\t2\t3\n");
	printf("\t     |     |     \n");
    	printf("1\t  %c  |  %c  |  %c \n", var0, var1, var2);
    	printf("\t_____|_____|_____\n");
	printf("\t     |     |     \n");
	printf("2\t  %c  |  %c  |  %c \n", var3, var4, var5);
	printf("\t_____|_____|_____\n");
    	printf("\t     |     |     \n");
	printf("3\t  %c  |  %c  |  %c \n", var6, var7, var8);
    	printf("\t     |     |     \n\n");
}

int modificar(int jugador, char opcion, char gato[3][3]){
	int fila;
	int columna;
	printf("Ingrese la fila: \n");
	scanf("%d", &fila);
	printf("Ingrese la columna: \n");
	scanf("%d", &columna);
	if (0 <= fila-1 && fila-1 <= 2 && 0 <= columna-1 && columna-1 <= 2){
		if (gato [fila-1][columna-1] != 'X' && gato [fila-1][columna-1] != '0'){
			gato[fila-1][columna-1] = opcion;
			return 1;
		}
		else{
			return 2;
		}
	}
	return 2;
}

int victoria(char gato[3][3]){
	if (gato[0][0] == gato[0][1] && gato[0][1] == gato[0][2])
        return 1;
    else if (gato[1][0] == gato[1][1] && gato[1][1] == gato[1][2])
        return 1;
    else if (gato[2][0] == gato[2][1] && gato[2][1] == gato[2][2])
        return 1; 
    else if (gato[0][0] == gato[1][0] && gato[1][0] == gato[2][0])
        return 1;
    else if (gato[0][1] == gato[1][1] && gato[1][1] == gato[2][1])
        return 1;
    else if (gato[0][2] == gato[1][2] && gato[1][2] == gato[2][2])
        return 1;
    else if (gato[0][0] == gato[1][1] && gato[1][1] == gato[2][2])
        return 1;
    else if (gato[0][2] == gato[1][1] && gato[1][1] == gato[2][0])
        return 1;
    else
        return 0;
}

void main(){
	int jugadas = 0;
	int jugador;
	char opcion;
	int revisar = 1;
	char gato[3][3] = {{'1', '2', '3'},{'4', '5', '6'},{'7', '8', '9'}};
	printf ("===Bienvenido al tres en linea===\n");
	while (1){
		printf ("Seleccione el primer jugador: \n");
		printf ("1. Don Gato\n");
		printf ("2. Benito\n");
		printf ("Jugador: ");
		scanf("%d", &jugador);
		if (jugador == 1){
			opcion = 'X';
			break;
		}
		else{
			if (jugador == 2){
				opcion = '0';
				break;
			}
			printf("Jugador no disponible\n\n");
		}
	}
	while(jugadas < 9){
		system("clear");
		mostrar(gato);
		if (jugador == 1){
			printf("\n\nTurno de Don Gato: \n");
			revisar = modificar(jugador, opcion, gato);
			if (revisar == 1){
				if (victoria(gato) == 1){
					system("clear");
					printf("\n\n=========================\n");
					printf("Ha ganado Don Gato!\n");
					printf("=========================\n");
					break;
				}
				else{
					jugador = 2;
					opcion = '0';
					jugadas++;
				}
			}
		}
		else{
			printf("\n\nTurno de Benito: \n");
			revisar = modificar(jugador, opcion, gato);
			if (revisar == 1){
				if (victoria(gato) == 1){
						system("clear");
						printf("\n\n=========================\n");
						printf("Ha ganado Benito!\n");
						printf("=========================\n");
						break;
				}
				else{
					jugador = 1;
					opcion = 'X';
					jugadas++;
				}
			}
		}
	}
	if (jugadas == 9){
		system("clear");
		printf("\n\n=========================\n");
		printf("Empate!\n");
		printf("=========================\n");
	}
	mostrar(gato);
}
