#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> 
#define MAXOP 100 
#define NUMBER '0' 
#define BUFSIZE 100
#define MAXVAL 100 

int sp = 0;
double variables[27];
char buf[BUFSIZE];
int bufp = 0;

typedef struct pila {
	double dato;
	int variable;
	struct pila *siguiente, *anterior;
} pila;

struct pila *inicio, *end;

double ato(char s[]){
	double valor, power;
	int i, sign;
	
	for (i = 0; isspace(s[i]); i++);
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (valor = 0.0; isdigit(s[i]); i++) {
		valor = 10.0 * valor + (s[i] - '0');
	}
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		valor = 10.0 * valor + (s[i] - '0');
		power *= 10;
	}
	return sign * valor / power;
}

int getch(void){
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c){
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

int getop(char s[])
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c; 
		i = 0;
	if (isdigit(c)) 
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') 
		while (isdigit(s[++i] = c = getch()));
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

void push(double f, int var) {
	struct pila *nuevoNodo = (struct pila *)malloc(sizeof(struct pila));
	if (nuevoNodo == NULL) {
		printf("No hay memoria disponible!\n");
	}
	else {
		if (end == NULL) {
			nuevoNodo->dato = f;
			nuevoNodo->variable = var;
			nuevoNodo->siguiente = NULL;
			nuevoNodo->anterior = NULL;
			inicio = nuevoNodo;
			end = nuevoNodo;
		}
		else {
			nuevoNodo->dato = f;
			nuevoNodo->variable = var;
			nuevoNodo->siguiente = NULL;
			nuevoNodo->anterior = end;
			end->siguiente = nuevoNodo;
			end = nuevoNodo;
		}
	}
}

double pop(void){
	if (end != NULL) {
		if (end->variable != 0) {
			int temp = variables[end->variable -65];
			if (inicio == end) {
				free(end);
				inicio = NULL;
				end = NULL;
				return temp;
			}
			else {
				struct pila *tempFree = end;
				end = end->anterior;
				end->siguiente = NULL;
				free(tempFree);
				return temp;
			}
		}
		else {
			int temp = end->dato;
			if (inicio == end) {
				free(end);
				inicio = NULL;
				end = NULL;
				return temp;
			}
			else {
				struct pila *tempFree = end;
				end = end->anterior;
				end->siguiente = NULL;
				free(tempFree);
				return temp;
			}
		}
	}
}

void top() {
	if (end->variable != 0) {
		printf("%c con valor %f", end->variable , variables[end->variable]);
	}
	else {
		printf("%f", end->dato);
	}
}

void duplicate() {
	struct pila *nuevoNodo = (struct pila *)malloc(sizeof(struct pila));
	if (nuevoNodo == NULL) {
		printf("No hay memoria disponible!\n");
	}
	else {
		if (end == NULL) {
			printf("Error! No hay datos\n");
			free(nuevoNodo);
		}
		else {
			nuevoNodo->dato = end->dato;
			nuevoNodo->variable = end->variable;
			nuevoNodo->siguiente = NULL;
			nuevoNodo->anterior = end;
			end->siguiente = nuevoNodo;
			end = nuevoNodo;
		}
	}
}

void swap() {
	if (inicio != end){
		struct pila *temp = end->anterior;
		double temp1 = end->dato, temp2 = temp->dato;
		int temp3 = end->variable, temp4 = temp->variable;
		
		temp->dato = temp1;
		temp->variable = temp3;
		end->dato = temp2;
		end->variable = temp4;
	}
	else{
		printf("No hay elementos");
	}
}

int main(){
	inicio = NULL;
	end = NULL;
	int type;
	double op2, a, b;
	char s[MAXOP], varOp;
	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(ato(s), 0);
			break;
		case '+':
			push(pop() + pop(), 0);
			break;
		case '*':
			push(pop() * pop(), 0);
			break;
		case '%':
			 b = pop(), a = pop();
			 while(a>b) {
				 a = a - b;
			 }
			 push(a, 0);
			break;
		case '-':
			op2 = pop();
			push(pop() - op2, 0);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2, 0);
			else
				printf("error: zero divisor\n");
			break;
		case '=':
			printf("\t%.8g\n", pop());
			break;
		case 't':
			top();
			break;
		case 'd':
			duplicate();
			break;
		case 's':
			swap();
			break;
		case 'v':
			printf("Inserte la letra de la variable (mayusculas): ");
			scanf(" %c", &varOp);
			push(0,varOp);
			break;
		case 'c':
			printf("Inserte la letra de la variable a cambiar (mayusculas): ");
			scanf(" %c", &varOp);
			if (varOp>=65 && varOp<90) {
				printf("Ingrese el valor de la variable: ");
				scanf("%lf", &variables[varOp - 65]);
			}
			else {
				printf("No es un caractere valido\n");
			}
			break;
		case '\n':
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}
