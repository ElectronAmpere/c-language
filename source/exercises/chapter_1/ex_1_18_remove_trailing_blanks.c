/**
 * @file ex_1_18_remove_trailing_blanks.c
 * @author your name (you@domain.com)
 * @brief Exercise 1-18. Write a program to remove trailing blanks 
 *          and tabs from each line of input, and to delete entirely blank lines.
 * @version 0.1
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#define MAXLINE 1000 /** maximum input line length */
#define MAXLINE_ENDINGS (2) /** Line endings to be added (\n\0) */

int exp_getline(char line[], int maxline);
int remove_trailing_blanks(char line[], int maxline);

int main()
{
    int len; /* current line length */
    char line[MAXLINE + MAXLINE_ENDINGS]; /* current input line */

    while ((len = exp_getline(line, MAXLINE)) > 0)
        printf("original (len: %d:%s)\n", len, line),
        len = remove_trailing_blanks(line, len),
        printf("removed (len: %d:%s)\n", len, line);

    return 0;
}

int exp_getline(char line[], int maxline)
{
    int length, c;

    for(length = 0; length < maxline && (c = getchar()) != EOF && c != '\n'; ++length)
        line[length] = c;
    
    if(c == '\n')
        line[length] = c,
        ++length;
    
    line[length] = '\0';
    ++length;

    return (length - MAXLINE_ENDINGS);
}

int remove_trailing_blanks(char line[], int maxline)
{
    int length;
    
    length = 0;

    while(maxline > 0)
    {
        if(line[maxline + 1] == '\n' && line[maxline + 2] == '\0')
        {
            if (line[maxline] == ' ' || line[maxline] == '\t')
                line[maxline] = '\n',
                line[maxline + 1] = '\0',
                --maxline;
            else
                --maxline,
                ++length;
        }
        else
            --maxline,
            ++length;
    }

    return length;
}