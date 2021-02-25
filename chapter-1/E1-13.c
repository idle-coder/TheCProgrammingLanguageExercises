#include <stdio.h>
#include <ctype.h>

#define IN      1       // Inside a word
#define OUT     2       // Outside a word

// Histogram of words' length
// Maximum length of 10 characters

int main ()
{
    printf(
        "This code works for words with maximum length of 10 characters.\n");
    int c, i, state;
    int word_len[10];

    state = OUT;
    for (i = 0; i < 10; i++)
        word_len[i] = 0;
    i = 0;

    while ((c = getchar()) != EOF)
    {
        if (isalpha(c)){
            state = IN;
            i++;
        }
        else if (state == IN)
        {
            word_len[i - 1]++;
            state = OUT;
            i = 0;
        }
    }

    for (c = 0; c < 10; c++)
    {
        printf("%2.0d ", c + 1);
        for (i = 0; i < word_len[c]; i++)
            putchar('#');
        putchar('\n');
    }
}
