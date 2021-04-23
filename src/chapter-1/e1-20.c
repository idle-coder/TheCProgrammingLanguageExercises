#include <stdio.h>

#define TAB_WIDTH   8   // One tab replaced by 8 blanks

// Detab, replace tabs with blanks

int main ()
{
    int c, i, n;

    while ((c = getchar()) != EOF)
    {
        n++;
        switch(c)
        {
            case '\t':
                for(i = 0; i <= 8 - n%8; i++)
                    putchar(' ');
                n = 0;
                break;
            case '\n':
                n = 0;
                putchar('\n');
                break;
            default: putchar(c);
        }
    }
}
