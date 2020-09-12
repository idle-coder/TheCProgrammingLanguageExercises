#include <stdio.h>

// Single blank

int main ()
{
    int c, blank = 0;

    while ((c = getchar()) != EOF)
        {
            if (c == ' ') {
                putchar(c);
                while ((c = getchar()) == ' ');
            }
            putchar(c);
        }
}

