#include <stdio.h>
void expand(char s1[], char s2[]){
	int x = s1[0];
	int y = s2[0];
	for (x;x<=y;x++){
		printf("%c",x);
	}
	printf("\n");
}
void main(){
	expand("a","z");
	expand("a","j");
}
