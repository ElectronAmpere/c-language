/**
 * @file ex_1_20_detab.c
 * @author your name (you@domain.com)
 * @brief Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number 
 * of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. 
 * Should n be a variable or a symbolic parameter?
 * @ref https://stackoverflow.com/questions/7178201/kr-exercise-1-20-need-some-clarification#7178297
 * @version 0.1
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

/**TODO: Need to check why the standard length of tab stops is 8 */
#define TAB_STOPS       (8) /** Spaces to be replaced for Tabs, Also this size 8 seems to be the standard. */
#define MAXLINE         (1000) /** Maximum line length */
#define MAXLINE_ENDINGS (2) /** Appended line endings length */
#define MAXLINE_TOTAL   (MAXLINE + MAXLINE_ENDINGS) /** Actual maximum line length */

int exp_getline(char line[], int maxline);

int main()
{
    char line[MAXLINE_TOTAL]; /** current input line */
    int length; /** length of the line */

    while((length = exp_getline(line, MAXLINE)) > 0)
        printf("%s", line);

    return 0;
}

int exp_getline(char line[], int maxline)
{
    int c, length, tabstops;

    tabstops = TAB_STOPS;

    for (length = 0; length < maxline && (c = getchar()) != EOF && c != '\n'; ++length)
    {
        --tabstops;
        
        if (c == '\t')
        {
            while(tabstops >= 0 && length < maxline)        
                line[length] = '-',
                --tabstops,
                ++length;
            
            --length;
        }
        else
            line[length] = c;
        
        if (tabstops < 1)
            tabstops = TAB_STOPS;
    }

    if (c == '\n')
        line[length] = c,
        ++length;

    line[length] = '\0';
    ++length;

    return (length - MAXLINE_ENDINGS);
}