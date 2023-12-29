/**
 * @file ex_1_02_temperature_float.c
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
    float lower, upper, step;
    float fahr, celcius;

    lower = 0.0,
    upper = 300.0,
    step = 20.0;

    fahr = lower;
    while (fahr <= upper){
        celcius = (5.0/9.0) * (fahr - 32.0);
        /**
         * @brief printf recognises the following
         * %o = octal
         * %x = hexadecimal
         * %c = character
         * %s = string
         * %% = for percentage
         * 
         */
        printf("%3.0f %6.1f\n", fahr, celcius);
        fahr += step;
    }

    return (0);
}