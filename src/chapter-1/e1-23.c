/*
 *    Considerations:
 *    - It is necessary to read multiple lines.
 *    - Remember to handle comment symbols inside double and simple quotes.
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXINPUT     1001    // Maximum input size

int get_input(char input[], int maxinput);
int uncomment(char *from, char to []);

// This code removes the comments of a code sample entered through the command line.

int main()
{
    int len;                // Current input length
    char code[MAXINPUT];     // Current input string
    char no_comments[MAXINPUT];	// String to store the uncommented code
    int i;

    while ((len = get_input(code, MAXINPUT)) > 0)
    {
        if(!uncomment(code, no_comments))
            printf("%s", no_comments);
    }

    return 0;
}

int uncomment(char *from, char *to)
{
    // Status: idle, inside quotes, and in_comment.
    //
    //
    //
    for(;(*to++ = *from++) != '\0';)
        ;
    return 0;
    
    // Initial state: outside quotes
    // Outside quotes state:
    // When /* or // is found, 
    
}

// get_input: read input into s, return length
int get_input(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar())!= EOF; i++)
        s[i] = c;

    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';

    return i;
}
