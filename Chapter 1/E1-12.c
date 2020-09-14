#include <stdio.h>

#define IN      1       // Inside a word
#define OUT     2       // Outside a word

// Print one word per line

int main()
{
    int c, state;
    state = OUT;

    while ((c = getchar()) != EOF)
    {
        if (!(c == '\n' || c == ' ' || c == '\n' || c == '\t')){
            putchar (c);
            state = IN;
        }
        else if (state == IN)
        {
            printf("\n");
            state = OUT;
        }
    }
}
