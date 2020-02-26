#include <stdio.h>

void main(){
    int c;
    int before, numWords;
	numWords = 0;

    before = 1;
    while ((c = getchar()) != EOF) {
  	if (c == ' ' || c == '\t' || c == '\n') {
       		if (before == 0) {
         		before = 1;
			numWords++;
		}
        } 
	else {
    		before = 0;
    	}
    }
    if (before == 0){
        numWords++;
    }
	printf("\nEl numero de palabras es: %d \n", numWords);
}
