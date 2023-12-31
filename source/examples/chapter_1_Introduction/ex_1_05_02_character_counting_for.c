/**
 * @file ex_1_05_02_character_counting_for.c
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
    double nc;
    for (nc = 0; getchar() != EOF; ++nc)
        ; //Null statement
    printf("%.0f\n",nc);
    return (0);
}