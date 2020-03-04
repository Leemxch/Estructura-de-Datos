#include <stdio.h>
#define MAXLINE 1000
int strindex(char frase[MAXLINE], char text[1]){
	int pos=0,tem=0;
	for (int i=0;frase[i] != '\0';i++){
		if (frase[i] == text[0]){
			tem = pos;
		}
		pos++;	
	}
	if (pos>0){
		return tem;
	}
	else{
		return -1;
	}
}
void main(){
	printf("%d\n",strindex("Hola, que tal\0","l"));
	printf("%d\n",strindex("Hola, que tal\0","a"));
	printf("%d\n",strindex("Hola, que tal\0","u"));
}
