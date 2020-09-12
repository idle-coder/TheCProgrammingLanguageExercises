#include <stdio.h>

//Print Celsius-Fahrenheit Table
//  for celsius = -20, 0, ..., 300; floating-point version

int main ()
{
    float fahr, celsius;
    int lower, upper, step;
    lower = -20;      // Lower limit of temperature table
    upper = 300;    // Upper limit
    step = 20;      // Step size

    celsius = lower;
    printf("Celsius Fahrenheit\n");
    while (celsius <= upper){
        fahr = (9.0/5.0)*celsius + 32.0;
        printf("   %3.0f     %6.1f\n", celsius, fahr);
        celsius += step;
    }
}
