#include <stdio.h>

#define MAXLINE 1000    // Maximum input line size

int get_line(char line[], int maxline);

// Print all lines longer than 80 characters

int main()
{
    int len;            // Current line length
    char line[MAXLINE];     // Current input line

    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > 80)
        {
            printf("%s", line);
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
