/**
 * @file ex_1_05_01_character_io.c
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

    c = getchar();

    /**
     * @brief EOF is end of line
     * 
     */
    while (c != EOF){
        putchar(c);
        c = getchar();
    }

    return (0);
}