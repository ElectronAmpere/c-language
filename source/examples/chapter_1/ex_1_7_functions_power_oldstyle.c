/**
 * @file ex_1_7_functions_power_oldstyle.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

/**
 * @brief   ex_1_7_functions_power_oldstyle.c:13:5: warning: a function definition 
 *          without a prototype is deprecated in all versions of C and is not 
 *          supported in C2x [-Wdeprecated-non-prototype]
 *          int power(base, n)
 *          ^
 *          1 warning generated.
 * 
 * @return int 
 */
int power(base, n)
int base, n;
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}

int main()
{
    int i;

    for(i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2, i), power(-3,i));

    return 0;
}