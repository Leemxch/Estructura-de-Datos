#include <stdio.h>

void main(){
	int c, max, count, before;
	count = 0;
	printf("Digite la cantidad maxima de letras por palabra: ");
	scanf("%d", &max); 
	int words[max];
	for (int a=0; a<max;a++){
		words[a]=0;		
	}
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (before == 0) {
				before = 1;
				words[count-1]++;
				count = 0;
			}
		} 
		else {
			before = 0;
			count++;
		}
	}	
	if (before == 0){
	    words[count-1]++;
	}
	for (int i=0; i<max; i++){
	    if (words[i] != 0){
		    printf("%d | ", i+1);
		    for (int ii=0; ii<words[i];ii++){
			    printf("X");
		    }
		    printf("\n");
	    }
	}
}
