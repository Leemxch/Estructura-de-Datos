#include <stdio.h>
void squeeze(char string1[], char string2[]){
	int validacion = 0;
	for (int i=0;string1[i]!= '\0';i++){
		for (int ii=0; string2[ii] !='\0';ii++){
			if (string1[i] == string2[ii]){
				validacion = 1;
				break;
			}
		}
		if (validacion == 0){
			putchar(string1[i]);
		}
		else{
			validacion = 0;
		}
	}
	putchar('\n');
}
void main(){
	squeeze("Hola\0", "anda\0");
}
