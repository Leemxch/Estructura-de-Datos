#include <stdio.h>
#include <string.h>
void reverse(char s[],char res[],int count,int actual){
    if (count>=0){
		res[actual]=s[count];
		printf("%c",res[actual]);
		actual++;
		count--;
		reverse(s,res,count,actual);
	}
}
void reverse_aux(char s[],char res[]){
	int cantidad=0,i=0;
	while(s[i]!='\0'){
		cantidad++;
		i++;
	}
	reverse(s,res,cantidad,0);
}
void main(){
	char s[10];
	reverse_aux("hola\0",s);
	printf("%s\n",s);
}
