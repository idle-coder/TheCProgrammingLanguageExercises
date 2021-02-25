#include <stdio.h>

#define MAXLINE 1000    // Maximum input line size

int get_line(char line[], int maxline);
void reverse(char s[]);

// Remove empty lines and trailing blanks and tabs

int main()
{
    int len;            // Current line length
    char line[MAXLINE];     // Current input line
    int i;

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        reverse(line);
        printf("%s\n", line);
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


void reverse(char s[])
{
    int i, j;
    char tmp;

    for (i = 0; s[i] != '\0'; i++)
        ;
    i--;

    if (s[i] == '\n')
        i--;

    for (j = 0; j < i; j++, i--)
    {
        tmp = s[j];
        s[j] = s[i];
        s[i] = tmp;
    }
}
