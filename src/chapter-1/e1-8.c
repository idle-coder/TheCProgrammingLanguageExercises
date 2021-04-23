#include <stdio.h>

// Blanks, tabs, and newlines counter

int main ()
{
    int c, nl = 0, tab = 0, blank = 0;

    while ((c = getchar()) != EOF)
        {
            if (c == '\n')
                nl++;
            else if (c == '\t')
                tab++;
            else if (c == ' ')
                blank++;
        }
    printf("# of newlines: %d\n", nl);
    printf("# of tabs: %d\n", tab);
    printf("# of blanks: %d\n", blank);
}

