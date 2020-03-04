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
void itoa(int n, char s[],int remember,int count) {
    int i, sign;
    if (sign = n < 0) {
    	remember = n;
    	n = -n;
	}
    if (n > 0){
        s[count++] = n % 10 + '0';
        itoa(n/10,s,remember,count);
    }
	else{
		while ((n /= 10) > 0);
		if (remember < 0){
			s[count++] = '-';
			}
		s[count++] = '\0';
		reverse(s);	
	}
}
void main(){
	char a[10];
	itoa(-141,a,0,0);
	printf("%s\n",a);
}
