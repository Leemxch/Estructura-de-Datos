#include <stdio.h>
#include <string.h>
void reverse(char s[]){
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
char* extend(char s[], int lim,int ini){
	int i;
	for (i= ini;i<=lim;i++){
		s[i] = '~';
	}
	return s;
}
void itoa(int n, char s[],int lim) {
    int i, sign, count=0;
    if ((sign = n) < 0) {
		n = -n;
	}
	i = 0;
    do { 
        s[i++] = n % 10 + '0';
		count++;
	}
	while ((n /= 10) > 0);
	if (sign < 0){
		s[i++] = '-';
		count++;
		}
	if (lim > count){
		s = extend(s,lim,count);
	}
	s[lim++] = '\0';
    reverse(s);
}
void main(){
	char a[10];
	itoa(-129,a,5);
	printf("%s\n",a);
}
