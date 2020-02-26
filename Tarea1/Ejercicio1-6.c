#include <stdio.h>
/* copy input to output; 1st version */
void main()
{
    int c, value;
    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
        value = c != EOF;
        printf("\n%d\n", value);
    }
}
