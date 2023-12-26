/**
 * @file ex_1_10_longest_lines.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

#define MAXLINE (1000)

int max; /** maximum length of the line */
char line[MAXLINE]; /** current input line */
char longest[MAXLINE]; /** longest line seen so far */

int exp_getline(void);
void copy(void);

int main()
{
    int len;
    extern int max;
    extern char line[], longest[];

    max = 0;

    while((len = exp_getline()) > 0)
        if(max < len)
            max = len,
            copy();
        
    if (max > 0)
        printf("%s", longest);

    return 0;
}

/** getline ; specialised version */
int exp_getline()
{
    int i, c;
    extern char line[];

    for(i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    
    if(c == '\n')
        line[i] = c,
        ++i;
    line[i] = '\0';

    return i;
}

void copy()
{
    int i;
    extern char line[], longest[];

    i = 0;

    while((longest[i] = line[i]) != '\0')
        ++i;
}