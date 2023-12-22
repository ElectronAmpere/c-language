/**
 * @file ex_1_13_histogram_word_length.c
 * @author your name (you@domain.com)
 * @brief Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
            easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
 * @version 0.1
 * @date 2023-12-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

#define MAX_WORDS (100)
#define IN (0)
#define OUT (1)

int main()
{
    int c, i, nw, j, state, word_length[MAX_WORDS];

    state = OUT;
    for (i = 0; i < MAX_WORDS; ++i)
        word_length[i] = 0;
    i = nw = 0;

    while((c = getchar()) != EOF)
    {
        if (c == '\n' || c == ' ' || c == '\t')
            state = OUT;
        else if (state == OUT)
            state = IN,
            ++nw;
        else
            ++word_length[nw-1];
    }

    /** Print Histogram */
    printf("-----------------------------------\n");
    for (i = 0; i < MAX_WORDS; ++i)
    { 
        printf("%d: ", i+1);
        for (j = 0; j < word_length[i]; ++j)
            printf("*");
        printf("\n");
    }
    printf("-----------------------------------\n");

    return(0);
}