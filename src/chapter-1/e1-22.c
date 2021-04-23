#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXLINE     1001    // Maximum input line size
#define LINE_WIDTH   101    // Maximum columns in a line

int get_line(char line[], int maxline);
int fold(char *from, char to []);

// This code breaks long lines in shorter lines.
//
// It replaces the closest blank with a newline if it is positioned at most ten
// columns away from the line width.
//
// If there is no blank close enough or the whole line has no blanks, then a 
// dash is added on the last possible character on the line and a newline after
// it.
//
// If the input is longer than MAXLINE, the rest is discarded.

int main()
{
    int len;                // Current line length
    char line[MAXLINE];     // Current input line
    char foldedLine[MAXLINE];
    char *line_ptr = line;
    int i;

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        if(!fold(line_ptr, foldedLine))
            printf("%s", foldedLine);
        line[0] = '\0';
        line_ptr = line;
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

    if (i >= lim - 1)
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    return i;
}


int fold(char *from, char to [])
{
    to[0] = '\0';
    int space_pos = 0;
    int to_index = 0, i = 0;
    while (strlen(from) > LINE_WIDTH)
    {
        for (i = LINE_WIDTH - 1; i >= LINE_WIDTH - 11; i--)
            if (from[i] == ' ')
            {
                space_pos = i;
                break;
            }

        if (space_pos)
        {
            for (i = 0; i < space_pos; i++)
                to[to_index++] = *from++;

            from++;
            to[to_index++] = '\n';
        }
        else 
        {
            for(i = 0; i < LINE_WIDTH - 2; i++)
                to[to_index++] = *from++;

            to[to_index++] = '-';
            to[to_index++] = '\n';
        }
        space_pos = 0;
    } 
    if (to_index == 0)
    {
        printf("The line is too short to be folded.\n");
        return 1;
    }
    else 
    {
        for(; *from != '\0'; from++)
            to[to_index++] = *from;
        to[to_index] = '\0';
        return 0;
    }
}
/*
    Notes:
    Keep in mind:
        No blanks
        All blanks
        Tabs

*/
