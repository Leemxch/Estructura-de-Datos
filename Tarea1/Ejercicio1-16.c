#include<stdio.h>

void main() {
	int sizeMax=0, size=0;
	char maxLine[500], line[500], c;
	
	for (int i=0; i<500; i++){
		maxLine[i] = ' ';
		line[i] = ' ';
	}
	
	while ((c = getchar()) != EOF) {
       		if (c == '\n') {
            		if (size>sizeMax){
				sizeMax=size;
				for (int j=0; j<sizeMax; j++){
					maxLine[j]=line[j];
				}
				size=0;
			}
			else{
				size=0;
			}
        	} 
		else {
            		line[size]=c;
			size++;
        	}
    	}
	
	if (size>sizeMax){
		printf("\n");
		sizeMax = size;
		for (int j=0; j<sizeMax; j++){
			maxLine[j]=line[j];
		}
	}

	printf("La linea con la mayor cantidad de caracteres es: \n");
	for(int k=0; k<sizeMax; k++){
		putchar(maxLine[k]);
	}
	printf("\n");
}
