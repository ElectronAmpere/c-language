/**
 * @file ex_1_4_temperature_celc_float.c
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
    float lower, upper, step;
    float celcius, fahr;
    char *ptr_title = "Celcius-Fahrenheit Table\n";

    lower = 0.0,
    upper = 300.0,
    step = 20.0;

    celcius = lower;
    printf("%s", ptr_title);

    while(celcius <= upper){
        fahr = (9.0 * celcius) / 5.0 + 32.0;
        printf("%3.1f %6.1f\n", celcius, fahr);
        celcius += step;
    }

    return (0);
}