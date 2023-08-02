/** *****************************************************************
* @file
*
* @brief Contains main function of the program. It handles the command
* line arguments and assigns further instructions based on them.
*******************************************************************/
#define CATCH_CONFIG_RUNNER
#include "..\\catch.hpp"
#include "Card.h"
#include "Queue.h"
#include "thpe14.h"

/** **********************************************************************
* @author Steve Nathan de Sa
*
* @par Description
* Constant belonging to the Catch Config Library, to run test cases.
************************************************************************/
const bool RUNCATCH = false;

/** **********************************************************************
 *  @author Steve Nathan de Sa
 *
 *  @par Description
 *  It handles the command line arguments and assigns further instructions
 *  based on them.
 *
 *  @param[in] argc Number of command line arguments from user.
 *  @param[in] argv String values of command line arguments
 *
 * @returns Returns a 0 upon correct runtime, returns error message and usage
 *          statement upon error in files or command line arguments.
 *
 *  @par Example
 *  @verbatim
    Usage: thpe14.exe [type] player1 player2
    Type
        -s cards retrieved using random number generator
        -f cards retrieved using files

    player1 - seed or file to use for player1
    player2 - seed or file to use for player2
    @endverbatim
 ************************************************************************/
int main(int argc, char** argv)
{
    card data1[100];
    card data2[100];
    int i = 0, x = 0, y = 0;

    Queue<card> hand1;
    Queue<card> hand2;

    ifstream p1, p2;

    //TEST CASE RUNCATCH
    if (RUNCATCH)
    {
        Catch::Session session;
        int result;

        result = session.run();
        if (result != 0)
        {
            cout << "Test cases didn't pass." << endl;
            return 0;
        }
    }

    //ARGUMENT CHECK
    if (argc == 4)
    {
        if (strcmp(argv[1], "-s") == 0)
        {
            unsigned int p1seed = stoi(argv[2]);
            unsigned int p2seed = stoi(argv[3]);

            DealHand(p1seed, hand1);
            DealHand(p2seed, hand2);

            playWar(hand1, hand2);
        }

        else if (strcmp(argv[1], "-f") == 0)
        {
            string p1file = argv[2];
            string p2file = argv[3];

            p1.open(p1file);
            p2.open(p2file);

            if (!p1.is_open())
            {
                cout << "Unable to open the file: " << p1file << endl;
                exit(0);
            }
            else if (!p2.is_open())
            {
                cout << "Unable to open the file: " << p2file << endl;
                exit(0);
            }
            else
            {
                //Read Player 1s Hand
                while (p1 << data1[x])
                {
                    x++;
                }

                //Read Player 2s Hand
                while (p2 << data2[y])
                {
                    y++;
                }

                //Add Player1s Hand to Queue
                for (i = 0; i < x; i++)
                {
                    hand1.enque(data1[i]);
                }

                //Add Player2s Hand to Queue
                for (i = 0; i < y; i++)
                {
                    hand2.enque(data2[i]);
                }

                playWar(hand1, hand2);

                p1.close();
                p2.close();
            }
        }

        else
        {
            cout << "Invalid game type" << endl;
            exit(0);
        }
    }
    else
    {
        cout << "Usage: thpe14.exe [type] player1 player2" << endl;
        cout << "       Type" << endl;
        cout << "           -s cards retrieved using random number generator" << endl;
        cout << "           -f cards retrieved using files" << endl;
        cout << endl;
        cout << "       player1 - seed or file to use for player1" << endl;
        cout << "       player2 - seed or file to use for player2" << endl;
        exit(0);
    }

    return 0;
}