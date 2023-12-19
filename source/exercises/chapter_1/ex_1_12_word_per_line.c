/**
 * @file ex_1_12_word_per_line.c
 * @author your name (you@domain.com)
 * @brief Exercise 1-12. Write a program that prints its input one word per line.
 * @version 0.1
 * @date 2023-12-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

#define IN  0 /* Inside a word */
#define OUT 1 /* Outside a word */

/* counts lines, words and characters in input */
int main()
{
    int c, word_ends;

    word_ends = 0;

    while((c = getchar()) != EOF){
        /* Checks whether the word has ended or not */
        if (c == ' ' || c == '\n' || c == '\t')
        {   
            /* If multiple endings are received, counter is incremented */
            ++word_ends;
            /* All the word endings are replaced with newline ending */
            c = '\n';
        }
        else
            word_ends = 0;
        
        /* If the word endings are more than one they are replaced with '\0' */
        if (word_ends > 1)
            c = '\0';
        putchar(c);
    }

    return (0);
}