/**
 * @file ex_1_5_character_counting.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

int main()
{
    long nc;

    nc = 0;

    while(getchar() != EOF)
        ++nc;
    
    printf("%ld\n",nc);

    return (0);
}