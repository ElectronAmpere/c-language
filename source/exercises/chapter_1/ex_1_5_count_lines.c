/**
 * @file ex_1_5_count_lines.c
 * @author your name (you@domain.com)
 * @brief Ex.1.5 Write a program to count blanks, tabs, and newlines.
 * @version 0.1
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

int main()
{
    int c, nl, blanks, tabs;

    while((c = getchar()) != EOF)
    {
        if (c == '\n')
            ++nl;
        if (c == ' ')
            ++blanks;
        if (c == '\t')
            ++tabs;
    }

    printf("Lines: %d\nBlanks: %d\nTabs = %d\n",nl, blanks, tabs);

    return (0);
}