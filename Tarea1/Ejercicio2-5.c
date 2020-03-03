#include <stdio.h>
int any(char string1[], char string2[]){
	int numero = 1;
	for (int i=0;string1[i]!= '\0';i++){
		for (int ii=0; string2[ii] !='\0';ii++){
			if (string1[i] == string2[ii]){
				return numero;
			}
		}
		numero++;
	}
	return -1;
}
void main(){
	printf("%d\n",any("Hola\0", "anda\0"));
}
