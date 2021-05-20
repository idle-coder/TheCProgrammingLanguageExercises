/*
 * This is a simple syntax test for C programs.
 *
 * It checks for:
 * - Unbalanced parentheses
 * - Unbalanced brackets
 * - Unbalanced braces
 * - Unbalanced double quotes
 * - Unbalanced single quotes
 * - No nested comments
 * 
 * It tells you the line where the unbalance might be for:
 * - double quotes
 * - single quotes
 * - nested comments
 * - and unbalanced brackets
 * 
 */

#include <stdio.h>
#include <stdint.h>

#define MAX_STR_SIZE    8001

enum states{
        LOGIC,
        LINE_COMMENT,
        BLOCK_COMMENT,
        SINGLE_QUOTES,
        DOUBLE_QUOTES
}state = LOGIC;

enum syntax_errors{
        OK,
        UNBALANCED_PARENTHESIS,
        UNBALANCED_BRACKETS,
        UNBALANCED_BRACES,
        UNBALANCED_DOUBLE_QUOTES,
        UNBALANCED_SINGLE_QUOTES,
        NESTED_COMMENTS
};

typedef struct{
        enum syntax_errors syntax_error;
        uint32_t error_line;
}SYNTAX_t;


uint32_t get_stdin(uint8_t string[], uint32_t const str_size);
SYNTAX_t verify_syntax(uint8_t const str[], uint32_t str_size);

int main ()
{
        const char *syntax_arr[] = {
                                    "OK",
                                    "UNBALANCED_PARENTHESIS",
                                    "UNBALANCED_BRACKETS",
                                    "UNBALANCED_BRACES",
                                    "UNBALANCED_DOUBLE_QUOTES",
                                    "UNBALANCED_SINGLE_QUOTES",
                                    "NESTED_COMMENT",
                                   };
        uint8_t input[MAX_STR_SIZE];
        
        if(get_stdin(input, MAX_STR_SIZE)){
                SYNTAX_t result = verify_syntax(input, MAX_STR_SIZE);
                if (result.syntax_error == OK)
                        printf("I'm ok.\n");
                else
                        printf("%s maybe at line %u\n", 
                               syntax_arr[result.syntax_error],
                               result.error_line
                              );
        }
        return 0;
}

SYNTAX_t verify_syntax(uint8_t const str[], uint32_t str_size){
        SYNTAX_t Syntax = {.syntax_error = OK, .error_line = 0};
        uint32_t i = 0;
        int8_t brace_count = 0;
        int8_t bracket_count = 0;
        int8_t parenthesis_count = 0;
        uint32_t line = 0;
        
        do
        {
                if (str[i] == '\n')
                        line++;
                switch(state){
                case LOGIC:
                        if((str[i] == '/') && (str[i + 1] == '/')){
                                state = LINE_COMMENT;
                        }
                        else if((str[i] == '/') && (str[i + 1] == '*')){
                                state = BLOCK_COMMENT;
                        }
                        else if (str[i] == '\n' && bracket_count != 0){
                                Syntax.syntax_error = UNBALANCED_BRACKETS;
                                Syntax.error_line = line;
                                return Syntax;
                        }
                        else if(str[i] == '\"'){
                                state = DOUBLE_QUOTES;
                        }
                        else if (str[i] == '\''){
                                state = SINGLE_QUOTES;
                        }
                        else if (str[i] == '{'){
                                brace_count++;
                        }                        
                        else if (str[i] == '['){
                                bracket_count++;
                        }
                        else if (str[i] == '('){
                                parenthesis_count++;
                        }
                        else if (str[i] == '}'){
                                brace_count--;
                        }
                        else if (str[i] == ']'){
                                bracket_count--;
                        }
                        else if (str[i] == ')'){
                                parenthesis_count--;
                        }
                break;
                case LINE_COMMENT:
                        if(str[i] == '\n')
                                state = LOGIC;
                break;
                case BLOCK_COMMENT:
                        if((str[i] == '/') && (str[i + 1] == '*')){
                                Syntax.syntax_error = NESTED_COMMENTS;
                                Syntax.error_line = line;
                                return Syntax;
                        }
                        else if ((str[i] == '*') && (str[i + 1] == '/')){
                                state = LOGIC;
                        }
                break;
                case SINGLE_QUOTES:
                        if(str[i] == '\n'){
                                Syntax.syntax_error = UNBALANCED_SINGLE_QUOTES;
                                Syntax.error_line = line;
                                return Syntax;
                        }
                        else if((str[i] == '\'') &&
                                (
                                 (str[i - 1] != '\\') ||
                                 ((str[i - 1] == '\\') && (str[i - 2] == '\\'))
                                )
                               ){
                                state = LOGIC;
                        }
                break;
                case DOUBLE_QUOTES:
                        if(str[i] == '\n'){
                                Syntax.syntax_error = UNBALANCED_DOUBLE_QUOTES;
                                Syntax.error_line = line;
                                return Syntax;
                        }
                        else if((str[i] == '\"') && 
                                (
                                 (str[i - 1] != '\\') ||
                                 ((str[i - 1] == '\\') && (str[i - 2] == '\\'))
                                )
                               ){
                                state = LOGIC;
                        }
                break;
                }
                i++;
        }while (str[i] != '\0');

        if (parenthesis_count != 0){
                Syntax.syntax_error = UNBALANCED_PARENTHESIS;
        }
        if (brace_count != 0){
                Syntax.syntax_error = UNBALANCED_BRACES;
        }
        if (bracket_count != 0){
                Syntax.syntax_error = UNBALANCED_BRACKETS;
        }
        return Syntax;
}


// get_str: read input into s, return length
uint32_t get_stdin(uint8_t string[], uint32_t const str_size){
        int c, i;

        for(i = 0; i < str_size - 1 && (c = getchar()) != EOF; i++)
                string[i] = c;

        string[i] = '\0';
        if(c != EOF){
                while(getchar() != EOF)
                        ;
        }
        return i;
}
