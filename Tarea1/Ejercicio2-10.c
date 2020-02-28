#include <stdio.h>
void lower(char string1[100]){
	int i=0;
	int tem;
	char string2[100];
	while (string1[i] != '\0'){
		we = string1[i];
		if (string1[i] <= 90 && string1[i]>=65){
			tem = string1[i]+32;
		}
		string2[i]=tem;
		i++;
	}
	printf("%s",string2);
	putchar('\n');
		
}

void main(){
	lower("AAAaBZz\0");
}
