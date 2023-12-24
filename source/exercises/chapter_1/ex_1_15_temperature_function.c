/**
 * @file ex_1_15_temperature_function.c
 * @author your name (you@domain.com)
 * @brief Exercise 1.15. Rewrite the temperature conversion program of 
 *         Section 1.2 to use a function for conversion.
 * @version 0.1
 * @date 2023-12-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

int convert_fahr_to_celcius(int fahr)
{
    int celcius;

    celcius = 0;

    celcius = 5 * (fahr - 32) / 9;

    return (celcius);
}

int main()
{
    int fahr, lower, upper, step;

    lower = 0,
    upper = 300,
    step = 20;

    fahr = lower;

    while (fahr <= upper)
    {   
        printf("%d %d\n",fahr, convert_fahr_to_celcius(fahr));
        fahr = fahr + step;
    }

    return (0);
}