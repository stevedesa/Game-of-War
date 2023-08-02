/** *****************************************************************
* @file
*
* @brief Contains the playRound Function. Contains pertaining
* functions that conduct a round of the game.
*******************************************************************/
#include "Card.h"
#include "Queue.h"
#include "thpe14.h"

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function conducts a round of the game of war. If the top card in both 
 * the players hand are equal, a war is declared and each player puts down 3
 * cards. If incase there is a tie again, both players will continue to put down
 * cards till there is no tie. If there is a tie and one of the players have less
 * than 3 cards, the both players put down cards till the player will less than 3 
 * cards runs out of cards. If there is a draw in such a case, each player will 
 * pick up it's respective discard stack. Whichever player wins the war will get 
 * the oponents cards followed by it's cards enqueued to its hand.
 *
 * @param[in, out]  player1 - contains the hand of the player1.
 * @param[in, out]  player2 - contains the hand of the player2.
 *
 * @par Example
 * @verbatim
   Queue<card> player1;
   Queue<card> player2;

   playRound(player1, player2); //Plays a round of War.
   @endverbatim
 *****************************************************************************/
void playRound(Queue<card>& player1, Queue<card>& player2)
{
    int i = 0;

    stack<card> stack1;
    stack<card> stack2;

    card card1, card2;

    //Place top Card
    player1.deque(card1);
    player2.deque(card2);

    //Add Card to Stack
    stack1.push(card1);
    stack2.push(card2);

    //Assign Value to Top Card
    card1 = stack1.top();
    card2 = stack2.top();

    //If there is a tie, Deque 3 cards and add them to the stacks
    //When card 1 and card 2 don't match, the while loop exits
    //This sets the stack ready for comparison
    while ((card1 == card2) && ((player1.size() >= 3) && (player2.size() >= 3)))
    {
        for (i = 0; i < 3; i++)
        {
            player1.deque(card1);
            player2.deque(card2);

            stack1.push(card1);
            stack2.push(card2);
        }
    }

    //If there is a tie, but player 1 one doesn't have 3 cards to put down
    if ((card1 == card2) && (player1.size() < 3))
    {
        size_t size = player1.size();

        //Both players will deqeue till player1 reaches it's last card
        for (i = 0; i < size; i++)
        {
            player1.deque(card1);
            player2.deque(card2);

            stack1.push(card1);
            stack2.push(card2);
        }

        //In case of another tie, return cards back to queue
        //After doing so, comparison cards will be popped to the stack
        if (stack1.top() == stack2.top())
        {
            LoadToOwnQueue(stack1, stack2, player1, player2);

            /*player1.deque(card1);
            player2.deque(card2);

            stack1.push(card1);
            stack2.push(card2);*/
        }
    }

    //If there is a tie, but player 2 one doesn't have 3 cards to put down
    if ((card1 == card2) && (player2.size() < 3))
    {
        size_t size = player2.size();

        //Both players will deqeue till player2 reaches it's last card
        for (i = 0; i < size; i++)
        {
            player1.deque(card1);
            player2.deque(card2);

            stack1.push(card1);
            stack2.push(card2);
        }

        //In case of another tie, return cards back to queue
        if (stack1.top() == stack2.top())
        {
            LoadToOwnQueue(stack1, stack2, player1, player2);
        }
    }

    //If Player1 > Player2
    if (card1 > card2)
    {
        LoadP1Queue(stack1, stack2, player1);
    }

    //If Player2 > Player1
    else if (card2 > card1)
    {
        LoadP2Queue(stack1, stack2, player2);
    }
}

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function adds P2s cards to the P1 queue and then adds the P1 cards to
 * the P1 queue. This function is called when a round is complete and P1 wins.
 *
 * @param[in, out]  P1 - contains the discard stack of the player1.
 * @param[in, out]  P2 - contains the discard stack of the player2.
 * @param[in, out]  hand1 - contains the hand of player1.
 *
 * @par Example
 * @verbatim
   stack<card> discard1;
   stack<card> discard2;
   Queue<card> hand1;
   
   LoadP1Queue(discard1, discard2, hand1); //Adds discard cards to player1s hand.
   @endverbatim
 *****************************************************************************/
void LoadP1Queue(stack<card>& P1, stack<card>& P2, Queue<card>& hand1)
{
    int i = 0;
    card temp;
    size_t size = P2.size();

    //Add P2s cards to queue first
    for (i = 0; i < size; i++)
    {
        temp = P2.top();
        P2.pop();
        hand1.enque(temp);
    }

    size = P1.size();
    //Then add P1s cards to queue
    for (i = 0; i < size; i++)
    {
        temp = P1.top();
        P1.pop();
        hand1.enque(temp);
    }
}

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function adds P1s cards to the P2 queue and then adds the P2 cards to
 * the P2 queue. This function is called when a round is complete and P2 wins.
 *
 * @param[in, out]  P1 - contains the discard stack of the player1.
 * @param[in, out]  P2 - contains the discard stack of the player2.
 * @param[in, out]  hand2 - contains the hand of player2.
 *
 * @par Example
 * @verbatim
   stack<card> discard1;
   stack<card> discard2;
   Queue<card> hand2;

   LoadP2Queue(discard1, discard2, hand2); //Adds discard cards to player1s hand.
   @endverbatim
 *****************************************************************************/
void LoadP2Queue(stack<card>& P1, stack<card>& P2, Queue<card>& hand2)
{
    int i = 0;
    card temp;
    size_t size = 0;

    size = P1.size();
    //Add P1s cards to queue first
    for (i = 0; i < size; i++)
    {
        temp = P1.top();
        P1.pop();
        hand2.enque(temp);
    }

    size = P2.size();
    //Then add P2s cards to queue
    for (i = 0; i < size; i++)
    {
        temp = P2.top();
        P2.pop();
        hand2.enque(temp);
    }
}

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function adds P1s and P2s cards to their respective queues in case of
 * a tie and one of the players has less than 3 cards.
 *
 * @param[in, out]  P1 - contains the discard stack of the player1.
 * @param[in, out]  P2 - contains the discard stack of the player2.
 * @param[in, out]  hand1 - contains the hand of player1.
 * @param[in, out]  hand2 - contains the hand of player2.
 *
 * @par Example
 * @verbatim
   stack<card> discard1;
   stack<card> discard2;
   Queue<card> hand1;
   Queue<card> hand2;

   LoadToOwnQueue(discard1, discard2, hand1, hand2); 
   //Adds respective discard cards to player1s and players2s hand.
   @endverbatim
 *****************************************************************************/
void LoadToOwnQueue(stack<card>& P1, stack<card>& P2, Queue<card>& hand1, Queue<card>& hand2)
{
    int i = 0;
    card temp;
    size_t size = 0;

    size = P1.size();
    //Add P1s cards to queue first
    for (i = 0; i < size; i++)
    {
        temp = P1.top();
        P1.pop();
        hand1.enque(temp);
    }

    size = P2.size();
    //Then add P2s cards to queue
    for (i = 0; i < size; i++)
    {
        temp = P2.top();
        P2.pop();
        hand2.enque(temp);
    }
}