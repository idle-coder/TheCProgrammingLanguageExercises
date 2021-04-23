#include <stdio.h>

// Visual tab, backspace and backslash

int main ()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        switch(c) {
            case '\\': putchar('\\'); putchar('\\'); break;
            case '\t': putchar('\\'); putchar('t'); break;
            case '\b': putchar('\\'); putchar('b'); break;
            default: putchar(c);
        }
    }
}

