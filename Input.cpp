/** *****************************************************************
* @file
*
* @brief Includes the DealHand and PlayWar functions. This file is 
* an extension of the thpe14.cpp file.
*******************************************************************/
#include "Card.h"
#include "Queue.h"
#include "thpe14.h"

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This functions enters 52 cards into the hand using a random number generator
 * from 0 to 51. the input is a unsigned integer seed provided by the command 
 * line arguments. It ses a lookup array to make sure no 2 same numbers are added
 * to the hand.
 * 
 * @param[in]       seed - contains seed number for number generator.
 * @param[in, out]  hand - contains queue of players hand.
 * 
 * @par Example
 * @verbatim
   Queue<card> hand;
   DealHand(123, hand); //Allocates 52 cards to hand.
   @endverbatim
 *****************************************************************************/
void DealHand(unsigned int seed, Queue<card>& hand)
{
    int count = 0;
    int value = 0;
    int lookup[52] = { 0 };
    card temp;

    default_random_engine generator(seed); 
    uniform_int_distribution<int> distribution(0, 51);

    while (count <= 51) 
    {
        value = distribution(generator); //generate temp card

        if (lookup[value] == 0) //unused
        {
            lookup[value]++;
            count++;

            temp.faceValue = int(value % 13); //face
            temp.suit = int(value / 13); //suit

            hand.enque(temp); //add to queue
        }
    }
}

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function is used to play the game War. If one of the player runs out of 
 * cards the hands of both players are printed to the screen along with how
 * many rounds it took for the player to win the game.
 *
 * @param[in, out]  player1 - contains the hand of the player1.
 * @param[in, out]  player2 - contains the hand of the player2.
 *
 * @par Example
 * @verbatim
   Queue<card> hand;
   DealHand(123, hand); //Allocates 52 cards to hand.
   @endverbatim
 *****************************************************************************/
void playWar(Queue<card>& player1, Queue<card>& player2)
{
    int rounds = 0;
    bool cont = true;

    while (cont)
    {
        if (player1.isEmpty()) //End war if player1 wins
        {
            cout << "Player 2 wins after " << rounds << " rounds." << endl;
            cout << "Player 1 hand: " << player1 << endl;
            cout << "Player 2 hand: " << player2 << endl;
            cont = false;
            player1.clear();
            player2.clear();
        }

        else if (player2.isEmpty()) //End war if player2 wins
        {
            cout << "Player 1 wins after " << rounds << " rounds." << endl;
            cout << "Player 1 hand: " << player1 << endl;
            cout << "Player 2 hand: " << player2 << endl;
            cont = false;
            player1.clear();
            player2.clear();
        }

        else //Continue playing
        {
            rounds++;
            playRound(player1, player2);
            cont = true;
        }
    }
}