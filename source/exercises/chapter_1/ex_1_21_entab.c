/**
 * @file ex_1_21_entab.c
 * @author your name (you@domain.com)
 * @brief Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum 
 * number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. 
 * When either a tab or a single blank would suffice to reach a tab stop, which should be given 
 * preference?
 * @version 0.1
 * @date 2023-12-26
 * @note Need to implement
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

#define TAB_STOPS       (4) /** Spaces to be replaced for Tabs */
#define SPACES_TO_TAB   (3) /** Minimum number of spaces to be replaced as a tab */
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
    int c, length, tabstops, spaces;

    tabstops = TAB_STOPS;
    spaces = 0;

    for (length = 0; length < maxline && (c = getchar()) != EOF && c != '\n'; ++length)
    {
        --tabstops;
        
        if (c == ' ')
            ++spaces;
        else
            line[length] = c,
            spaces = 0;

        if (spaces >= TAB_STOPS && tabstops >= SPACES_TO_TAB)
            line[length] = '\t',
            spaces = spaces - TAB_STOPS,
            tabstops = 0;
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