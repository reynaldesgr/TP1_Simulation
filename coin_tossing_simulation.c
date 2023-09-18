/**
 * @file coin_tossing_simulation.c
 * @brief This file contains tossing simulation using rand() and
    test the equidistribution of these experiments (runs)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX6  6
#define MAX10 10 

#define LIMIT_RUNS 100

/**
 * @brief Simulates flipping a coin.
 * This function simulates flipping a coin.
 *
 * @return 0 for tails, 1 for heads
*/
unsigned int doAFlipCoin()
{
    return rand() % 2;
}


/**
 * @brief Simulate rolling a 6-sided dice
 * This function simulates rolling a 6-sided dice.
 *
 * @return A random number between 1 and 6
*/
unsigned int doAFlipDice6()
{
    return rand() % 7;
}

/**
 * @brief Simulate rolling a 10-sided dice
 * This function simulates rolling a 10-sided dice.
 *
 * @return A random number between 1 and 10
*/
unsigned int doAFlipDice10()
{
    return rand() % 11;
}

/**
 * @brief Display an array of dice results.
 * This function displays the results of a dice simulation.
 *
 * @param dice An array containing a instance of a dice rolling simulation. 
 * Indices represent the faces of a dice. The frequency of appearance corresponding to the index i/face i is contained in dice[i]
 * @param max The maximum value for a dice
*/
void displayDiceArray(unsigned int * dice, int max)
{
    printf("\n--- Simulation ---\n");

    for (int i = 0; i < max; i++)
    {
        printf(" Face %d \t : \t %d \n", i+1, dice[i]);
    }
}


int main()
{
    unsigned int coin;
    unsigned int heads;
    unsigned int tails;
    unsigned int face;

    unsigned int dice6[7]   = {0};
    unsigned int dice10[11] = {0};
    
    // tails = 0 / heads = 1
    tails = 0;
    heads = 0;

    printf("\n--- Flip Coin Simulation ---\n");
    // Flip Coin Simulation
    for (int i = 0; i < LIMIT_RUNS; i++)
    {
        coin = doAFlipCoin();
        if (coin)
        {
            heads++;
        }else{
            tails++;
        }
    }

    printf("Heads : %d | Tails : %d \n", heads, tails);

    printf("\n--- 6-Dice Simulation ---\n");
    // 6-Dice Simulation
    for (int i = 0; i < LIMIT_RUNS; i++)
    {
        face = doAFlipDice6();
        dice6[face]++;
    } 
    displayDiceArray(dice6, MAX6);

    printf("\n--- 10-Dice Simulation ---\n");
    // 10-Dice Simulation
    for (int i = 0; i < LIMIT_RUNS; i++)
    {
        face = doAFlipDice10();
        dice10[face]++;
    } 
    displayDiceArray(dice10, MAX10);

    return 0;
}