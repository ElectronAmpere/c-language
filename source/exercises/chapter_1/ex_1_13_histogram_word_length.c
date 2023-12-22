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

#define MAX_WORDS (10)
#define IN (0)
#define OUT (1)

int main()
{
    int c, i, nw, j, state, max, word_length[MAX_WORDS];

    state = OUT;
    for (i = 0; i < MAX_WORDS; ++i)
        word_length[i] = 0;
    i = nw = max = 0;

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
        for (j = 0; j < word_length[i] + 1; ++j)
            if (word_length[i] != 0)
                printf("*");
            else
                ;
        printf("\n");
    }
    printf("-----------------------------------\n");

    printf("\n\n");

    /** Get max length */
    for (i = 0; i < MAX_WORDS; ++i)
        if (max < word_length[i])
            max = word_length[i];
        else
            ;

    /** Print Vertical Histogram */
    for (i = 0; i < max; ++i)
    {
        for (j = 0; j < MAX_WORDS; ++j)
            if (word_length[j] + 1 >= max - i && word_length[j] != 0)
                printf("  * ");
            else
                printf("    ");
        printf("\n");
    }
    
    for (i = 0; i < MAX_WORDS; ++i)
        printf(" %2d ", i + 1);
    printf("\n\n");

    return(0);
}