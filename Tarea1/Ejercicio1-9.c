#include <stdio.h>
/* Reescribe la entrada con varios espacios en uno solo */
void main(){
    int input, count;
    count = 0;
    while ((input = getchar()) != EOF) {
        if (input == ' ') {
            if (count < 1) {
                printf("%c", input);
                ++count;
            }

        }
        else {
            printf("%c", input);
                count = 0;
        }
    }
}
