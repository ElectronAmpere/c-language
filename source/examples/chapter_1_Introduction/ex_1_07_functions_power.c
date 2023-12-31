/**
 * @file ex_1_07_functions_power.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

/** Function Prototype */
int power (int m, int n);


int main()
{
    int i;

    for(i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2, i), power(-3,i));

    return (0);
}

/* power: raise the base to the n-th power; n > 0 */
int power (int base, int m)
{
    int i, p;

    p = 1;

    for (i = 1; i <= m; ++i)
        p = p * base;
    
    return (p);
}