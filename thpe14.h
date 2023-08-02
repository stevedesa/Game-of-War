/** *****************************************************************
* @file
*
* @brief Contains function prototypes of the program.
*******************************************************************/
/** **************************************************************************
 * @mainpage Take Home Programming Exam 4 - Game of War
 *
 * @section course_section Course Information
 *
 * @author Steve Nathan de Sa
 *
 * @par Professor:
 *         Roger Schrader
 *
 * @par Course:
 *         CSC215 - M002 - Programming Techniques
 *
 * @par Location:
 *         Classroom Building CB327
 *
 * @date Due May 3, 2023
 *
 * @section program_section Program Information
 *
 * @details
 * The purpose of this program is to conduct the Card Game of War!
 * 
 * The game begins with 2 options. Either the user provides 2 seeds which
 * generates 2 52 card hands for the respective players or the user 
 * provides 2 files filled with 52 integers mimicing cards to be placed in
 * the hand. The program then takes the hands provided and converts them
 * into cards with facevalues and suits for each respective hand. Then the
 * Game of War begins!
 * 
 * The program conducts multiple rounds until one player wins by emptying
 * the other players hand. Each round involves placing the topmost card 
 * of the players stack. In case of a draw, a war is declared and each 
 * player places down 3 cards. Then the top most card is compared. If there 
 * is another tie, another war is declared until there is a difference in 
 * cards. In case of a tie and one player has less than 3 cards, both
 * players put down cards till the player runs out. If there is again a tie,
 * each player picks up each other's respective stack and this ends the round.
 * 
 * Hence, like this the program conducts multiple rounds till a winner is 
 * found. Then, the winner is declared and the hands of both players are
 * displayed to the screen. This ends the program!!!
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      none - a straight compile and link with no external libraries.
 *
 * @par Usage:
   @verbatim
    thpe14.exe [type] player1 player2
    Type
        -s cards retrieved using random number generator
        -f cards retrieved using files

    player1 - seed or file to use for player1
    player2 - seed or file to use for player2
   @endverbatim
*
* @section todo_bugs_modification_section Todo, Bugs, and Modifications
*
* @bug No Bugs!
*
* @todo Project Complete!
*
* @par Modifications and Development Timeline:
* Link to my Gitlab commits. To view <a target="_blank"
* href="https://gitlab.cse.sdsmt.edu/101124071/csc215s23programs/-/commits/main?ref_type=heads">click here</a>
 *****************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <stack>
#include <iomanip>
#include <sstream>

using namespace std;

void DealHand(unsigned int seed, Queue<card>& hand); 

void playWar(Queue<card>& player1, Queue<card>& player2);

void playRound(Queue<card>& player1, Queue<card>& player2);

void LoadP1Queue(stack<card>& P1, stack<card>& P2, Queue<card>& hand1);

void LoadP2Queue(stack<card>& P1, stack<card>& P2, Queue<card>& hand2);

void LoadToOwnQueue(stack<card>& P1, stack<card>& P2, Queue<card>& hand1, Queue<card>& hand2);