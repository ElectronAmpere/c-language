/**
 * @file ex_1_4_temperature_symbols.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

int main()
{
    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%3d %6.1f\n",fahr, (5.0/9.0)*(fahr - 32));
    return (0);
}