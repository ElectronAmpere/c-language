#include <stdio.h>

int main()
{
    // Declaring and initialising variables
    int var_a   = 0, 
        var_b   = 0, 
        var_sum = 0;

    // Get input from the user for var_a, var_b
    printf("Enter value for var_a:");
    scanf("%d",&var_a);
    printf("Enter value for var_b:");
    scanf("%d",&var_b);

    // Summing of the variables
    var_sum = var_a + var_b;

    // Print the sum of the input values
    printf("Sum :%d\n",var_sum);

    // Exit the main funtion
    return (0);
}