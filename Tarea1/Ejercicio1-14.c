#include <stdio.h>
void main(){
	int c, characters[94][2], dec;
	for (int i=0; i<94;i++){
		characters[i][0]=i+32;
		characters[i][1]=0;
	}
	while ((c = getchar()) != EOF) {
		dec = c;
		dec -= 32;
		if (dec>=0 && dec<=94){
			characters[dec][1]++;
		}
	}
	for (int i=0; i<94; i++){
		if (characters[i][1] !=0 ){
			printf("%c | ", characters[i][0]);
			for (int ii=0; ii<characters[i][1];ii++){
				printf("X");
			}
			printf("\n");
		}
	}
}
