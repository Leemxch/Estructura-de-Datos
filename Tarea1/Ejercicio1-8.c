#include <stdio.h>
/* Cuenta los caracteres y saltos de linea de la entrada */
void main(){
    int input, count;
    count = 0;
    while ((input = getchar()) != EOF) {
        if (input == '\n'){
            ++count;
        }
        else{
            (++count);
        }
        printf("%d\n", count);
    }      
}
