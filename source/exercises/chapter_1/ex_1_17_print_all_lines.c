/**
 * @file ex_1_17_print_all_lines.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#define MAXLINE 1000 /** maximum input line length */
#define MAXLINE_ENDINGS (2) /** Line endings to be added (\n\0) */
#define MIN_PRINT_LINE (80) /** Minimum length of the lines that can be printed */

/** 
 * There is a function named getline in the standard c library,
 * hence the name is modified to exp_getline
*/
int exp_getline (char line[], int maxline);

/** Print the line that are greater than MIN_PRINT_LINE */
int main()
{
    int len; /* current line length */
    char line[MAXLINE + MAXLINE_ENDINGS]; /* current input line */

    while ((len = exp_getline(line, MAXLINE)) > 0)
        if (len > MIN_PRINT_LINE)
        {
            printf("%d:%s\n", len, line);
        }

    return (0);
}

int exp_getline (char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim && (c = getchar()) != EOF && c !='\n'; ++i)
        s[i] = c;

    s[i] = '\n';
    ++i;
    s[i] = '\0';
    ++i;
    
    return (i - MAXLINE_ENDINGS);
}