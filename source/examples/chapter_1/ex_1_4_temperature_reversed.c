/**
 * @file ex_1_4_temperature_reversed.c
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
    int lower, upper, step;
    int fahr, celcius;

    lower = 0,
    upper = 300,
    step = 20;

    celcius = lower;

    printf("Celcius-Fahrenheit Table\n");
    while(celcius <= upper){
        fahr = (9 * celcius)/ 5 + 32;
        printf("%d\t %d\n",celcius, fahr);
        celcius += step;       
    }
    return (0);
}