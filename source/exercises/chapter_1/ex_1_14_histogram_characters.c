/**
 * @file ex_1_14_histogram_characters.c
 * @author your name (you@domain.com)
 * @brief Exercise 1-14. Write a program to print a histogram 
 * of the frequencies of different characters in its input.
 * @version 0.1
 * @date 2023-12-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

#define MAX_CHARACTERS (26)

int main()
{
    int i, j, c, characters[MAX_CHARACTERS + MAX_CHARACTERS], char_length[MAX_CHARACTERS];

    for (i = 0; i < MAX_CHARACTERS + MAX_CHARACTERS; ++i)
        if (i < MAX_CHARACTERS)  
            char_length[i] = 0, 
            characters[i] = i + 'A';
        else
            characters[i] = i - MAX_CHARACTERS + 'a';
    
    while ((c = getchar()) != EOF)
        for(i = 0; i < MAX_CHARACTERS + MAX_CHARACTERS; ++i)
            if (c == characters[i])
                if (i < MAX_CHARACTERS)
                    ++char_length[i];
                else
                    ++char_length[i - MAX_CHARACTERS];
            else
                ;
    
    printf("Character Frequency Histogram \n");
    printf("-----------------------------------\n");
    for(i = 0; i < MAX_CHARACTERS; ++i)
    {
        printf("%c, %c: ",characters[i], characters[i + MAX_CHARACTERS]);
        for (j = 0; j < char_length[i]; ++j)
            printf("*");
        
        printf("\n");
    }
    printf("-----------------------------------\n");

    return (0);
}