#include <stdio.h>
#include <string.h>

#define MAXLINE     1001    // Maximum input line size
#define LINE_WIDTH   100    // Maximum columns in a line

#define FAILURE         0
#define SUCCESS         1

int get_line(char line[], int maxline);
char fold(char from[], char to []);

// Break long lines in shorter lines

int main()
{
    int len;                // Current line length
    char line[MAXLINE];     // Current input line
    char foldedLine[MAXLINE];
    int i;

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        if (fold(line, foldedLine))
            printf("%s\n", foldedLine);
        else
            printf("The line is too short to be folded.\n");
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


char fold(char from[], char to [])
{
    int i = 100;
    if (strlen(from))
    {
        while (from[i] != ' ' && from[i] != '\t' && i > 0)
            i--;
        if (!i)
            printf("  ");
    }
    else
    {
        return FAILURE;
    }
}
/*
    Notes:
    Keep in mind:
        No blanks
        All blanks
        Tabs

*/
