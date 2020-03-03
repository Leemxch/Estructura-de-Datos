#include <stdio.h>
void htoi(char phrase[]){
	int a, i=0;
	while (phrase[i]!= '\0'){
		if (65<=phrase[i]&&phrase[i]<=70){
			a = phrase [i];
			printf("%d",a);
		}
		if (97<=phrase[i]&&phrase[i]<=102){
			a = phrase[i];
			printf("%d",a);
		}
		if (48<=phrase[i]&&phrase[i]<=57){
			a = phrase[i];
			printf("%d",a);
		}
		i++;
	}
	printf("\n");
}
void main(){
	htoi("Pruebita\0");
}
