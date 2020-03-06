#include <stdio.h>
#include <math.h>

double seno(int c){
	return sin(c);/*sen(c)*/
}
int potencia(int x,int y){
	return pow(x,y);/*x^y*/
}
double exponencial(int c){
	return exp(c);/*e^c*/
}
void main(){
	printf("%.8g\n%d\n%.8g\n",seno(9),potencia(5,5),exponencial(3));
}
