/*
 *    Considerations:
 *    - It is necessary to read multiple lines.
 *    - Remember to handle comment symbols inside double quotes.
 */
#include <stdio.h>
#include <string.h>

#define MAX_STR_SIZE    4002    // Maximum string size in characters.
#define OUT             0
#define BLOCK_COMMENT   1
#define LINE_COMMENT    2
#define QUOTES          3

int get_str(char str[], int str_size);
int remove_comments(const char *from, char *to);

// This code removes the comments of a c code provided via standard input.

int main()
{
    char str[MAX_STR_SIZE] = "";           // The input is stored here.
    char no_comments[MAX_STR_SIZE] = "";   // The string without comments is stored here
    char *ptr = no_comments;
    if (get_str(str, MAX_STR_SIZE) > 0)
    {
        if(!remove_comments(str, ptr))
            printf("%s", no_comments);

    }

    return 0;
}

int remove_comments(const char *from, char *to)
{
    int state = OUT;

    do
    {
        switch(state)
        {
            case OUT:
                if (*from == '/' && *(from + 1) == '*')
                    state = BLOCK_COMMENT;
                else if (*from == '/' && *(from + 1) == '/')
                    state = LINE_COMMENT;
                else if (*from == '\"' && *(from - 1) != '\\')
                    state = QUOTES;
                else
                    *to++ = *from++;
                break;
            case BLOCK_COMMENT:
                while (!(*from == '*' && *(from + 1) == '/'))
                    from++;
                from = from + 2;
                state = OUT;
                break;
            case LINE_COMMENT:
                while (*from != '\n')
                    from++;
                *to++ = '\n';
                from++;
                state = OUT;
                break;
            case QUOTES:

                while(!(*(from - 1) != '\\' && *from == '\"'))
                    *to++ = *from++;
                *to++ = *from++;
                state = OUT;
                break;
        }
    } while (*from);

    /*
        Out of comments or quotes:
            if double quotes are found, write everything to output
            string, ignore \".

            if single quotes are found, ignore the following escape
            sequences: \" and \'

            if last char is '/' and current char is '*', enter block comment
            state

            if last char and current char are '/', enter line comment state

            else write to output string

        Inside block comment
            delete everything until you find '*' and '/'
            then get back to out state
        Inside line comment
            delete everything until \n




        Inside quotes
     */
/*
    for(;(*to++ = *from++) != '\0';)
        ;
        */
    *to++ = '\n';
    *to = '\0';

    return 0;

    // Initial state: outside quotes
    // Outside quotes state:
    // When /* or // is found,

}

// get_str: read input into s, return length
int get_str(char *s, int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar())!= EOF; i++)
        s[i] = c;

    s[i] = '\0';
    return i;
}
