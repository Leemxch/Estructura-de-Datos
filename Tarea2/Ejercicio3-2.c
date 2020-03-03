#include <stdio.h>
void escape(char s[100], char t[100]){
	for(int i=0;s[i]!='\0';i++){
		switch(s[i]){
		case ' ':
			putchar('\\');
			putchar('b');
			break;
		case '\n':
			putchar('\\');
			putchar('n');
			break;
		case '\t':
			putchar('\\');
			putchar('t');
			break;
		default:
			printf("%c",s[i]);
			break; 
		}	
	}
	putchar('\n');
}
void main(){
	char copia[100];
	escape("Hola que tal",copia);
}
