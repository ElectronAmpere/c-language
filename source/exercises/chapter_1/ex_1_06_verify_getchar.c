/**
 * @file ex_1_06_verify_getchar.c
 * @author your name (you@domain.com)
 * @brief Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1.
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
     * @brief The condition will return the following
     * for the specified input
     * 
     * Input : Output
     * Any character other than EOF : 1
     * EOF : 0 
     * 
     * In Windows, EOF is entered in terminal as Ctrl+z
     * In Linux and Unix, EOF is entered in terminal as Ctrl+D
     * 
     */
    printf("Value of \'getchar() != EOF\': %d\n",(getchar() != EOF));
    return (0);
}