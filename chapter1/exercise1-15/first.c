#include <stdio.h>

/* print Fahrenheit-Celsius table
   for Fahr = 0, 20, ..., 300; floating-point version */
/* now with functions! */

float fahr2cel(int fahrenheit);

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("Fahrenheit \t Celsius\n");
    while (fahr <= upper) {
        printf("%6.0f \t\t %6.1f\n", fahr, fahr2cel(fahr));
        fahr = fahr + step;
    }
    return 0;
}

float fahr2cel(int n)
{
    return (5.0/9.0) * (n-32.0);
}
