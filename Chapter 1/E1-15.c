#include <stdio.h>

#define LOW_LIM     0       // Lower limit of temperature table
#define UPP_LIM     300     // Upper limit
#define STEP        20      // Step size

//Print Fahrenheit-Celsius Table
//  for fahr = 0, 20, ..., 300; floating-point version
float fahr_to_celsius (int);

int main ()
{
    int fahr;
    fahr = LOW_LIM;

    printf("Fahrenheit Celsius\n");

    while (fahr <= UPP_LIM){
        printf("   %3d     %6.1f\n", fahr, fahr_to_celsius(fahr));
        fahr += STEP;
    }
}

float fahr_to_celsius (int fahr)
{
    return (5.0/9.0)*(fahr - 32.0);
}
