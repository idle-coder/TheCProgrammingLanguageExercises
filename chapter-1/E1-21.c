#include <stdio.h>

#define MAXLINE     1000    // Maximum input line size
#define TAB_WIDTH   8       // Eight blanks equals one tab

int get_line(char line[], int maxline);
void entab(char from[], char to[]);

// Entab, replace blanks with tabs and blanks.
// I'll give preference to tabs because a tab
// is just one character, so we save some cycles.

int main()
{
    int len;                // Current line length
    char line[MAXLINE];     // Current input line
    char entabed[MAXLINE];  // Entabed string
    int i;

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        entab(line, entabed);
        printf("%s\n", entabed);
    }

    return 0;
}

// getline: read a line into s, return length
int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar())!= EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';

    return i;
}


void entab(char from[], char to[])
{
    int i, j, blanks;
    i = j = blanks = 0;

    for (j = 0; from[j] != '\0'; j++)
    {
        if (from[j] != ' ')
            to[i++] = from[j];
        else
        {
            if (++blanks == TAB_WIDTH)
            {
                to[i++] = '\t';
                blanks = 0;
            }
            else if (from[j + 1] != ' ')
            {
                blanks += i;
                while (i < blanks)
                    to[i++] = ' ';
                blanks = 0;
            }
        }
    }
    to[i] = '\0';
}
