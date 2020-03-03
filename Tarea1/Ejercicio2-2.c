#include<stdio.h>
void main(){
	int i = 0, lim = 100;
	char s[lim], c;
	for (int ii=0;ii<100;ii++){
		s[ii] = 0;
	}
	while (i<(lim-1)){
		c=getchar();
		if (c==EOF){
			break;
		}
		if (c == '\n'){
			break;
		}
		s[i++] = c;
	}
	printf("\n%s\n", s);
}
