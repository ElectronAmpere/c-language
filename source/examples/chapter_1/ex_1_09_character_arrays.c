/**
 * @file ex_1_09_character_arrays.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#define MAXLINE 1000 /** maximum input line length */

/** 
 * There is a function named getline in the standard c library,
 * hence the name is modified to exp_getline
*/
int exp_getline (char line[], int maxline);
void copy(char to[], char from[]);

/** Print the longest line */
int main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;

    while ((len = exp_getline(line, MAXLINE)) > 0)
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    if (max > 0)
        printf("%s", longest);

    return (0);
}

int exp_getline (char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c !='\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return (i);
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}