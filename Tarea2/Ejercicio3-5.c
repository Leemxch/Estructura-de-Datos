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
void itob(int n, char s[], int b) {
    int i=0, sign;
    if ((sign = n) < 0) {
            n = -n;
    }
    do { 
        if (n % b > 9) {
            s[i++] = n % b - 10 + 'A';
        }
        else {
            s[i++] = n % b + '0';
        }
    } while ((n /= b) > 0); 
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
void main() {
    char a[10];
    itob(156, a, 16);
    printf("%s\n", a);
}
