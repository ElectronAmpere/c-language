/**
 * @file ex_1_09_reduce_blanks.c
 * @author your name (you@domain.com)
 * @brief Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or
          more blanks by a single blank
 * @version 0.1
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

int main()
{
    int c, blanks;

    blanks = 0;

    while((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++blanks;
        else
            blanks = 0;
        if (blanks > 1)
            c = '\0';

        putchar(c);
    }

    return (0);
}