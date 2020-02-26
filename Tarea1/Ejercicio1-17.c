#include <stdio.h>
#define MAXLINE 1000 
int gline(char line[], int maxline);
void copy(char to[], char from[]);
 
void main(){
  	int len; 
 	int max; 
 	char line[MAXLINE]; 
 	char longest[MAXLINE]; 
 	max = 0;
 	while ((len = gline(line, MAXLINE)) > 0)
 		if (len > max) {
 			max = len;
 			copy(longest, line);
 		}
 	if (max >= 80){
		printf("%s\n", "La linea mas larga es:");
 		printf("%s", longest);
	}
	else{
		printf("%s\n", "No hay lineas mas de 80 caracteres");
	}
 }
 
 int gline(char s[],int lim){
 	int c, i;
 	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
 		s[i] = c;
 	if (c == '\n') {
 		s[i] = c;
 		++i;
 	}
 	s[i] = '\0';
 	return i;
 }
 
 void copy(char to[], char from[]){
 	int i;
 	i = 0;
 	while ((to[i] = from[i]) != '\0'){
 		++i;
	}
 }
