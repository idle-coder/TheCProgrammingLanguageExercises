#include <stdio.h>

#define UPPER_LIM   0x7E
#define LOWER_LIM   0x21
#define RANGE       UPPER_LIM + 1 - LOWER_LIM     // Allowed characters range

// Histogram of character frequency
// ASCII from 0x21 to 0x7E

int main ()
{
    int c, i;
    int char_freq[RANGE];

    for (i = 0; i < RANGE; i++){
        char_freq[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c <= UPPER_LIM && c >= LOWER_LIM)
            char_freq[c - LOWER_LIM]++;
    }

    for (c = LOWER_LIM; c <= UPPER_LIM; c++)
    {
        printf("%c ", c);
        for (i = 0; i < char_freq[c - LOWER_LIM]; i++)
            putchar('#');
        putchar('\n');
    }
}
