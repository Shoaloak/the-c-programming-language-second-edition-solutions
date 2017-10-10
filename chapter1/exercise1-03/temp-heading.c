#include <stdio.h>

/* print Fahrenheit-Celsius table
   for Fahr = 0, 20, ..., 300; floating-point version */
main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("Fahrenheit \t Celsius\n");
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%6.0f \t\t %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
