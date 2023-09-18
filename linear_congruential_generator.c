/**
 * @file linear_congruential_generator.c
 * @brief This file implements a Linear Congruential Generator.
    A linear congruential generator (LCG) is an algorithm that yields a sequence
    of pseudo-randomized numbers calculed with a discontinuous picewise linear equation.
    (Wikipedia)
 * 
*/

#include <stdio.h>

unsigned long int a = 5;
unsigned long int c = 1;
unsigned long int m = 16;


unsigned long int seed = 5;


// Constantes Knurth & Lewis (Wikipedia)

/*
unsigned long int a = 1664525;
unsigned long int c = 1013904223;
unsigned long int m = 4294967296; // 2^32
*/

/**
 * @brief This function implements a LCG function using integer numbers.
 *
 * @return A pseudo-random number (seed)
*/
unsigned long int intRand()
{
    seed = (a * seed + c) % m;
    
    return seed;
}


/**
 * @brief This function implements a LCG function using real/float numbers.
 *
 * @return A pseudo-random number (seed)
*/
float floatRand()
{
    seed = (a * seed + c) % m;
    
    return (float) seed/16;  
}

int main()
{
    unsigned long int   res;
             float      resf;

    printf("\nintRand() \t \n");
    for (int i = 0; i < 32; i++)
    {
        res = intRand();
        printf("%d : %lu \n", i+1, res);
    }

    printf("\nfloatRand() \t \n");
    for (int i = 0; i < 32; i++)
    {
        resf = floatRand();
        printf("%d : %.4f \n", i+1, resf);
    }

    return 0;
}
