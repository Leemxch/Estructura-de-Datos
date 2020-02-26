#include <stdio.h>
/* print Celsius-Fahrenheit table for celsius = 0, 20, ..., 300 */
void main(){
    int celsius, fahr;
    int lower, upper, step;
    lower = 0; /* lower limit of temperature scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    celsius = lower;
    printf("Celsius\t\tFahrenheit\n");
    while (celsius <= upper) {
        fahr = (9*celsius)/5+32;
        printf("%d\t\t%d\n", celsius, fahr);
        celsius = celsius + step;
    }
}
