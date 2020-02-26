#include<stdio.h>
void main() {
	char palabra[100]="", c;
	int count=0;
	while ((c = getchar()) != EOF) {
       		if (c == ' ' || c == '\t' || c == '\n') {
            		reverse(palabra, count);
			count = 0;
			putchar(c);
        	} 
		else {
			palabra[count]=c;
            		count++;
        	}
    	}
}
char reverse(char palabra[], int num){
	for(int i=0; i<num; i++){
		printf("%c", palabra[num-1-i]);
	}
	
}
