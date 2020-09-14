#include <stdio.h>

#define TAB_WIDTH   7   // One tab replaced by 7 blanks

// Detab, replace tabs with blanks

int main ()
{
    int c, i;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
            for(i = 0; i < TAB_WIDTH; i++)
                putchar(' ');
        else
            putchar(c);
    }

}
