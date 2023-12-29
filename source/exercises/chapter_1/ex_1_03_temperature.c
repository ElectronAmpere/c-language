/**
 * @file ex_1_03_temperature.c
 * @author your name (you@domain.com)
 * @brief Exercise 1-3. Modify the temperature conversion program to print a heading above the table. 
 * @version 0.1
 * @date 2023-11-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

int main()
{
    int fahr, celcius;
    int lower, upper, step;

    /**
     * @brief C=(5/9)(F-32)
     * Prints the Celcius conversion for the Fahrenheit input,
     * range is from lower to upper value configured
     * the increment of the fahrenheit is based on the step size 
     */
    lower = 0;  // Starts here
    upper = 300; // Ends here
    step = 20; // Increments with

    fahr = lower;   //Set to start value

    /* Title of the program */
    printf("Fahrenheit-Celcius Table\n");
    while (fahr <= upper) // Checked till the end
    {
        celcius = 5 * (fahr - 32) / 9; // Conversion formula C=(5/9)(F-32) 
        // Due to BODMAS rule it has refactored in this order
        printf("%3d %6d\n",fahr, celcius);
        fahr = fahr + step;
    }
    return (0);
}