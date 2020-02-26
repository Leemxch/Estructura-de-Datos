#include <stdio.h>
/* print Fahrenheit-Celsius table for fahr = 300, 280, ..., 0 */
void main(){
    int fahr, celsius;
    int lower, upper, step;
    lower = 0; /* lower limit of temperature scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    fahr = upper;
    printf("Fahrenheit\t\tCelsius\n");
    while (fahr >= lower) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t\t\t%d\n", fahr, celsius);
        fahr = fahr - step;
    }
}
