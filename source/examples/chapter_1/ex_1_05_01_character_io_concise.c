/**
 * @file ex_1_05_01_character_io_concise.c
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
    int c;
    
    while((c = getchar()) != EOF)
        putchar(c);
    
    return(0);
}