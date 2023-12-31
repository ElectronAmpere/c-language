/**
 * @file ex_2_01_value_ranges.c
 * @author your name (you@domain.com)
 * @brief Exercise 2-1. Write a program to determine the ranges of char, short, int, and long 
 * variables, both signed and unsigned, by printing appropriate values from standard headers 
 * and by direct computation. Harder if you compute them: determine the ranges of the various 
 * floating-point types.
 * @version 0.1
 * @date 2023-12-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <float.h>
#include <limits.h>

// For range calculations
#define UN_CHAR_MAX ((unsigned char)~0) // this evaluates to 255
#define UN_CHAR_MIN ((unsigned char)0)

#define SI_CHAR_MAX ((char)(UN_CHAR_MAX >> 1)) // UN_CHAR_MAX >> 1 (255 >> 1) = 127
#define SI_CHAR_MIN (-(char)(UN_CHAR_MAX >> 1) - 1) // 127

#define UN_SHORT_MIN ((unsigned short)0)
#define UN_SHORT_MAX ((unsigned short)~0)

#define SI_SHORT_MAX ((short)(UN_SHORT_MAX >> 1))
#define SI_SHORT_MIN (-(short)(UN_SHORT_MAX >> 1) - 1)

#define UN_INT_MIN ((unsigned int)0)
#define UN_INT_MAX ((unsigned int)~0)

#define SI_INT_MAX ((int)(UN_INT_MAX >> 1))
#define SI_INT_MIN (-(int)(UN_INT_MAX >> 1) - 1)

#define UN_LONG_MIN ((unsigned long)0)
#define UN_LONG_MAX ((unsigned long)~0)

#define SI_LONG_MAX ((long)(UN_LONG_MAX >> 1))
#define SI_LONG_MIN (-(long)(UN_LONG_MAX >> 1) - 1)

int main()
{
    printf("Finding the ranges of the datatypes using calculations..\n");

    // Print the value ranges of char datatype
    printf("Max of signed char  : %d\n",SI_CHAR_MAX);
    printf("Min of signed char  : %d\n",SI_CHAR_MIN);
    printf("Min of unsigned char: %d\n",UN_CHAR_MAX);
    printf("Max of unsigned char: %d\n\n",UN_CHAR_MIN);

    // Print the value ranges of short datatype
    printf("Max of signed short  : %d\n",SI_SHORT_MAX);
    printf("Min of signed short  : %d\n",SI_SHORT_MIN);
    printf("Min of unsigned short: %d\n",UN_SHORT_MAX);
    printf("Max of unsigned short: %d\n\n",UN_SHORT_MIN);

    // Print the value ranges of int datatype
    printf("Max of signed int  : %d\n",SI_INT_MAX);
    printf("Min of signed int  : %d\n",SI_INT_MIN);
    printf("Min of unsigned int: %u\n",UN_INT_MAX);
    printf("Max of unsigned int: %u\n\n",UN_INT_MIN);

    // Print the value ranges of long datatype
    printf("Max of signed long  : %ld\n",SI_LONG_MAX);
    printf("Min of signed long  : %ld\n",SI_LONG_MIN);
    printf("Min of unsigned long: %lu\n",UN_LONG_MAX);
    printf("Max of unsigned long: %lu\n\n",UN_LONG_MIN);

    printf("---------------------------------------------\n\n");
    printf("Finding the ranges of the datatypes using standard limits library..\n");

    // Print the value ranges of char datatype
    printf("Max of signed char  : %d\n",SCHAR_MAX);
    printf("Min of signed char  : %d\n",SCHAR_MIN);
    printf("Min of unsigned char: %d\n",UCHAR_MAX);
    printf("Max of unsigned char: %d\n\n",CHAR_MIN);

    // Print the value ranges of short datatype
    printf("Max of signed short  : %d\n",SHRT_MAX);
    printf("Min of signed short  : %d\n",SHRT_MIN);
    printf("Min of unsigned short: %d\n",USHRT_MAX);
    printf("Max of unsigned short: %d\n\n",UN_SHORT_MIN);

    // Print the value ranges of int datatype
    printf("Max of signed int  : %d\n",INT_MAX);
    printf("Min of signed int  : %d\n",INT_MIN);
    printf("Min of unsigned int: %u\n",UINT_MAX);
    printf("Max of unsigned int: %u\n\n",UN_INT_MIN);

    // Print the value ranges of long datatype
    printf("Max of signed long  : %ld\n",LONG_MAX);
    printf("Min of signed long  : %ld\n",LONG_MIN);
    printf("Min of unsigned long: %lu\n",ULONG_MAX);
    printf("Max of unsigned long: %lu\n\n",UN_LONG_MIN);

    printf("Max of float    :%f\n",FLT_MAX);
    printf("Min of float    :%f\n",FLT_MIN);

    printf("---------------------------------------------\n\n");

    return (0);
}