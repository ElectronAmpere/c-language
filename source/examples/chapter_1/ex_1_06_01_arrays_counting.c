/**
 * @file ex_1_06_01_arrays_counting.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

int main()
{
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;

    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;
    
    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    
    printf("digits =");
    for (i = 0; i < 10; ++i)
        printf(" %d",ndigit[i]);
    printf(", white space = %d,  other = %d\n",nwhite, nother);

    return (0);
}

/**
 * @brief Input
 *  sdsgh jsdksjds jhsa12 112819282637267312812918300012010212023823712
    723872 827326739 9821nnsdklavb2 32912   ksdlsd  skds
    sjsdns9824372
    digits = 6 13 23 10 1 0 3 8 9 6, white space = 12,  other = 42
 * 
 */