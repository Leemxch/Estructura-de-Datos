#include <stdio.h>
/* Verifica el estado del EOF */
void main()
{
    int c;
    c = getchar();
    while (c != EOF) {
        c = getchar();
        printf("%d\n", EOF);
    }
}
