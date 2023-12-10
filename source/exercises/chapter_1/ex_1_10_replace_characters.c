/**
 * @file ex_1_10_replace_characters.c
 * @author your name (you@domain.com)
 * @brief Exercise 1-10. Write a program to copy its input to its output, 
 *        replacing each tab by \t, each backspace by \b, and each backslash 
 *        by \\. This makes tabs and backspaces visible in an unambiguous way.
 * @version 0.1
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t'){
            putchar('\\');
            putchar('t');
        }
        else if (c == '\\'){
            putchar('\\');
            putchar('\\');
        }
        else if (c == '\b'){
            putchar('\\');
            putchar('b');
        }
        else
            putchar(c);
    }

    return (0);
}