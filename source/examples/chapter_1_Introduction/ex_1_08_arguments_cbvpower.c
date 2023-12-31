/**
 * @file ex_1_08_arguments_cbvpower.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

/** power: raise base to n-th power; n >=0; version 2 */
int power (int base, int n)
{
    int p;

    for (p = 1; n > 0; --n)
        p = p * base;

    return (p);
}


int main()
{
    int i;

    for(i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2, i), power(-3,i));

    return (0);
}