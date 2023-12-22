/**
 * @file ex_1_13_histogram_words.c
 * @author your name (you@domain.com)
 * @brief Exercise 1-13_s. Write a program to print a histogram of the lengths of spaces, digits and others in its input. It is
            easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
 * @version 0.1
 * @date 2023-12-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

#define DIGITS_ARRAY_LENGTH (10)
#define BLANKS_OTHERS_LENGTH (2)
#define HISTOGRAM_LENGTH (BLANKS_OTHERS_LENGTH + DIGITS_ARRAY_LENGTH)

int main()
{
    int c, i, j, k, nwhites, nothers, ndigits[10], max;

    nwhites = nothers = max = 0;

    for (i = 0; i < DIGITS_ARRAY_LENGTH; ++i)
        ndigits[i] = 0;
    
    while((c = getchar()) != EOF)
        if ( c >= '0' && c <= '9')
            ++ndigits[c - '0'];
        else if ( c == ' ' || c == '\t' || c == '\n')
            ++nwhites;
        else
            ++nothers;

    /** Printing Histograms */
    printf("\n\tHistogram - Horizontal Left\n\n");
    printf("-----------------------------------\n");
    printf("Blanks\t|");
    for (i = 0; i < nwhites; ++i)
        printf("*");
    printf("\n");
    
    printf("Others\t|");
    for (i = 0; i < nothers; ++i)
        printf("*");
    printf("\n");
    
    for (i = 0; i < DIGITS_ARRAY_LENGTH; ++i)
    {
        printf("%d\t|",i);
        for (j = 0; j < ndigits[i]; ++j)
            printf("*");
        printf("\n");
    }
    printf("-----------------------------------\n");

    printf("\n\tHistogram - Horizontal Right\n\n");
    printf("-----------------------------------\n");
    for (i = 0; i < DIGITS_ARRAY_LENGTH; ++i)
        if (max < ndigits[i])
            max = ndigits[i];
    
    if (max < nothers)
        max = nothers;
    if (max < nwhites)
        max = nwhites;

    for (i = 0; i < max - nwhites; ++i)
        printf(" "); 
    for (i = 0; i < nwhites; ++i)
        printf("*");
    printf("| Blanks\n");
    
    for (i = 0; i < max - nothers; ++i)
        printf(" ");
    for (i = 0; i < nothers; ++i)
        printf("*");
    printf("| Others\n");
    
    for (i = 0; i < DIGITS_ARRAY_LENGTH; ++i)
    {
        for (j = 0; j < max - ndigits[i]; ++j)
            printf(" ");
        for (j = 0; j < ndigits[i]; ++j)
            printf("*");
        printf("| %d\n",i);
    }
    printf("-----------------------------------\n");

    printf("\n\n");
    /** Vertical Histogram */
    for (i = 0; i < max; ++i)
    {
        if (nwhites + 1 >= max - i + 1)
            printf("    * ");
        else
            printf("      ");
        
        if (nothers + 1 >= max - i + 1)
            printf("      *   ");
        else
            printf("          ");

        for (j = 0; j < DIGITS_ARRAY_LENGTH; ++j)
            if (ndigits[j] + 1 >= max - i + 1)
                printf("  * ");
            else
                printf("    ");
        printf("\n");
    }

    printf("\n");
    printf(" Blanks ");
    printf(" Others ");
    for (i = 0; i < DIGITS_ARRAY_LENGTH; ++i)
        printf(" %2d ", i);

    printf("\n\n");
        
    return (0);
}