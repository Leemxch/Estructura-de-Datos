#include <stdio.h>
#include <math.h>
#include <string.h>
#define word 8
void reverse(char s[]){
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
void itoa(int n, char s[]) {
    int max = pow(2, word-1);
    int i=0, sign;
    if ((sign = n) < 0) {
        if (n == -max) {
            n++;
            n = -n;
            s[0] = n % 10 + 1 + '0';
            n /= 10;
            i = 1;
        }
        else {
            n = -n;
        }
    }
    do { 
        printf("%c", n % 10+'0');
        s[i++] = n % 10 + '0';

    } while ((n /= 10) > 0); 
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void main() {
    char a[10];
    itoa(-128, a);
    printf("\n%s\n", a);
}
