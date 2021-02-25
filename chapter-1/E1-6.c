#include <stdio.h>

// getchar() != EOF value

int main ()
{
    int c;

    while (c = getchar() != EOF)
        printf("%d\n", c);
    printf("EOF = %d\n", c);
}
