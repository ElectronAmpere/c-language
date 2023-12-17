/**
 * @file ex_1_7_eof_value.c
 * @author your name (you@domain.com)
 * @brief Exercise 1-7. Write a program to print the value of EOF.
 * @version 0.1
 * @date 2023-12-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

int main()
{
    /**
     * @brief 
     * 
     */
    //printf("EOF value: %d\n",EOF);
    printf("Press Ctrl+Z in Windows or Ctrl+D in Unix/Linux\n");
    printf("EOF Value: %d\n",getchar());
    return (0);
}