/**
 * @file ex_1_08_count_lines.c
 * @author your name (you@domain.com)
 * @brief Exercise 1-8. Write a program to count blanks, tabs, and newlines. 
 * @version 0.1
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

int main()
{
    int c, lines, blanks, tabs;

    lines = 0, blanks = 0, tabs = 0;

    while((c = getchar()) != EOF)
    {
        if (c == '\n')
            ++lines;
        if (c == ' ')
            ++blanks;
        if (c == '\t')
            ++tabs;
    }

    printf("\nLines: %d\nBlanks: %d\nTabs: %d\n",lines, blanks, tabs);

    return (0);
}