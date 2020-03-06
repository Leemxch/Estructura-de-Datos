#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> 
#define MAXOP 100 
#define NUMBER '0' 
#define BUFSIZE 100
#define MAXVAL 100 

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

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

void push(double f) {
	if (sp < MAXVAL) {
		val[sp++] = f;
	}
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

double top() {
	return val[sp-1];
}

void duplicate() {
	push(val[sp-1]);
}

void swap() {
	double temp1=pop(), temp2=pop();
	push(temp1);
	push(temp2);
}

int main(){
	int type;
	double op2, a, b;
	char s[MAXOP];
	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(ato(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '%':
			 b = pop(), a = pop();
			 while(a>=b) {
				 a = a - b;
			 }
			 push(a);
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '=':
			printf("\t%.8g\n", pop());
			break;
		case 't':
			printf("%f", top());
			break;
		case 'd':
			duplicate();
			break;
		case 's':
			swap();
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
