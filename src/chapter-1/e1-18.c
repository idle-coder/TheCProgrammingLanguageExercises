#include <stdio.h>

#define MAXLINE 1000    // Maximum input line size

int get_line(char line[], int maxline);

// Remove empty lines and trailing blanks and tabs

int main()
{
    int len;            // Current line length
    char line[MAXLINE];     // Current input line

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        len -= 2;       // Minus 1 to skip the newline and minus 1 for the array index starting at 0
        while((line[len] == ' ' || line[len] == '\t'))
            len--;
        if (len > 0)
        {
            line[len + 2] = '\n';
            line[len + 3] = '\0';
            printf("%s", line);
        }
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
