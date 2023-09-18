/**
 * @file tausworthe.c
 * @brief This files implements the Tausworthe method for generating pseudo-random numbers.
    The Tausworthe Generator is a multiplicative recursive generator which produces
    random bits. The theory behind the Tausworthe Generators is related to irreducible polynomials.

*/

#include <stdio.h>
#include <stdint.h>

#define MAX 100

uint8_t seed = 0b0110;

/**
 * @brief This function display a decimal number into its binary form.
*/
void printBinary(uint8_t decimalNumber)
{
    int i;
    int bit;

    for (i = 3; i >= 0; i--) {
        bit = (decimalNumber >> i) & 1;
        printf("%d ", bit);
    }
    printf("\n");
}

/**
 * @brief This function apply the Tausworthe's algorithm to a given seed.
 * It is based on a linear feedback shift register (4 bits registers).
 * In this case : this function applied a XOR between 2^1 and 2^0 that will be injected in 
 * the left position after a right shift.
 *
 * @param seed Number (seed) given to apply the Tausworthe's algorithm
 * 
 * @return A generated pseudo-random number
*/
uint8_t tausworthe (uint8_t seed)
{
    uint8_t bit1;
    uint8_t bit2;
    uint8_t xorbit;

    bit1        = seed & 1;
    bit2        = (seed >> 1) & 1;
    xorbit      = bit1 ^ bit2;
    seed        = seed >> 1;

    if (xorbit)
    {
        seed = seed | 0b1000;
    }

    return seed;
}


int main()
{
    int i;

    for (i = 0; i < MAX; i++)
    {
        seed = tausworthe(seed);
        printf("N%d \t : \t %d\n", i, seed);
        printBinary(seed);
        printf("\n");

    }
    return 0;
}