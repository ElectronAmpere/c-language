/**
 * @file ex_1_11_word_counting_tests.c
 * @author your name (you@domain.com)
 * @brief Exercise 1-11. How would you test the word count program? What kinds of input are most
            likely to uncover bugs if there are any?
 * @version 0.1
 * @date 2023-12-17
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
    printf("\nLines: %d\nWords: %d\nCharacters: %d\n", nl, nw, nc);

    return (0);
}

/**
 * @brief Test Inputs:
 *  1.  jahsas jhsaas  kasas lkasashasas llaskasj
        xsasa 
        sdsd
        3 7 54
    2. hashas jhashajs jhasjahs k      q       kjsaahas

        Lines: 1
        Words: 6
        Characters: 38
    3. has hbashbas asask askas
        kjsask
        kjasjs jashjas kasjkas
        hasg kajsa

        Lines: 4
        Words: 10
        Characters: 66
 */