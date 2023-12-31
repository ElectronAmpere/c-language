/**
 * @file ex_1_05_03_line_counting.c
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
    int c, nl;

    nl = 0;

    while((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    
    printf("%d\n", nl);

    return (0);
}