/*
 *  Case 1. The line has no spaces; Add a dash in the last possible char of the
 *  line , then a newline and then the following characters on the line.
 *
 *  Case 2. There is a space at most ten characters away from the line limit; 
 *  Replace space with newline.
 *
 *  Case 3. There is a space eleven or more positions away from the line limit.
 *  Add newline at the line limit and continue working with the rest of the
 *  string.
 *
 *  Ideas: Is there a function to split string in two? With that we can print
 *  the first part and keep working with the other one.
 *
 *  Change the pointer to your current position.
 *  Print part of a string with fwrite(str, 1, len, stdout)
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE     1001    // Maximum input line size
#define LINE_WIDTH   101    // Maximum columns in a line

int get_line(char line[], int maxline);
int fold(char *from, char to []);

// Break long lines in shorter lines

int main()
{
    int len;                // Current line length
    char line[MAXLINE];     // Current input line
    char foldedLine[MAXLINE];
    char *line_ptr = line;
    int i;

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        fold(line, foldedLine);
        printf("%s", foldedLine);
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


int fold(char *from, char to [])
{
    to[0] = '\0';
    int space_pos = 0;
    int to_index = 0, from_index = 0, i = 0;
    while (strlen(from) > LINE_WIDTH)
    {
        for (i = LINE_WIDTH - 1; i >= LINE_WIDTH - 11; i--)
            if(from[i] == ' ')
            {
                space_pos = i;
                break;
            }

        if (space_pos)
        {
            for(i = 0; i < space_pos; i++)
                to[to_index++] = *from++;
            from++;
            to[to_index++] = '\n';
        }    
    } 
    if (!strlen(to))
    {
        printf("The line is too short to be folded.\n");
        return 1;
    }
    else {
        for(; *from != '\0'; from++)
            to[to_index++] = *from;
        to[to_index] = '\0';
        return 1;
    }
}
/*
    Notes:
    Keep in mind:
        No blanks
        All blanks
        Tabs

*/
