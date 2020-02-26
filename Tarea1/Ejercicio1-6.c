#include <stdio.h>
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
