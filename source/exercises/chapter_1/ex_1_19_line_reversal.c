/**
 * @file ex_1_18_remove_trailing_blanks.c
 * @author your name (you@domain.com)
 * @brief Exercise 1-19. Write a function reverse(s) that reverses the character string s.
 *         Use it to write a program that reverses its input a line at a time.
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
void reverse(char s[]);

int main()
{
    int len; /* current line length */
    char line[MAXLINE + MAXLINE_ENDINGS]; /* current input line */

    while ((len = exp_getline(line, MAXLINE)) > 0)
        printf("original (len: %d:%s)\n", len, line),
        printf("reversed (len: %d:", len),
        reverse(line),
        printf(")\n");

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

void reverse(char s[])
{
    int length, s_length;
    char s_rev[MAXLINE + MAXLINE_ENDINGS]; /** string reversed */
    
    length = s_length = 0;

    while(length < MAXLINE + MAXLINE_ENDINGS)
        s_rev[length] = '\0',
        ++length;

    length = 0;

    while(s[s_length] != '\0')
        ++s_length;

    while(s[length] != '\n')
        s_rev[s_length - length - MAXLINE_ENDINGS] = s[length],
        ++length;

    s_rev[length] = '\n';

    printf("%s", s_rev);
}