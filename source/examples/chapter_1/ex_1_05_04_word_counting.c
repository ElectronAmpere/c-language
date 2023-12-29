/**
 * @file ex_1_05_04_word_counting.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

#define IN  0 /* Inside a word */
#define OUT 1 /* Outside a word */

/* counts lines, words and characters in input */
int main()
{
    int c, nw, nl, nc, state;

    state = OUT;
    nl = nc = nw = 0;

    while((c = getchar()) != EOF){
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT){
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);

    return (0);
}