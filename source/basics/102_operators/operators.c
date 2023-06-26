/**
 * @file operators.c
 * @author ElectronAmpere (learningthiruvalluvar@gmail.com)
 * @brief This will deal with all the operators available in c
 * @version 0.1
 * @date 2023-06-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

/**
 * @brief The main function of the program supposedly runs at the start of the
 *        program
 * 
 * @return int by default the value is zero, when it ran successfully
 */
int main()
{
    /* Variable initialisation */
    int var_a   = 0, 
        var_b   = 0, 
        var_sum = 0,
        var_multi = 0,
        var_divide = 0,
        var_sub = 0,
        var_reminder = 0;

    /* Get input from the user for var_a & var_b */
    printf("Enter value for var_a:");
    scanf("%d",&var_a);
    printf("Enter value for var_b:");
    scanf("%d",&var_b);

    /* Summing of the variables */
    var_sum     = var_a + var_b;
    var_multi   = var_a * var_b;
    var_divide  = var_a / var_b;
    var_sub     = var_a - var_b;
    var_reminder = var_a % var_b;

    /* Print the sum of the input values */
    printf("Sum:%d\n",var_sum);
    printf("Multiply:%d\n",var_multi);
    printf("Division:%d\n",var_divide);
    printf("Subtract:%d\n",var_sub);
    printf("Reminder:%d\n",var_reminder);

    /* Exit the main funtion */
    return (0);
}