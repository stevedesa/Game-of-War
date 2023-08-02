/** *****************************************************************
* @file
*
* @brief Contains the Card function prototypes.
*******************************************************************/
#include <fstream>

/** *****************************************************************
* @brief Contains the data of the card structure.
*******************************************************************/
struct card
{
    /** *****************************************************************
    * @brief Contains the faceValue of the card.
    *******************************************************************/
    int faceValue;
    /** *****************************************************************
    * @brief Contains the suit value of the card.
    *******************************************************************/
    int suit;
};

bool operator==(const card& card1, const card& card2);

bool operator!=(const card& card1, const card& card2);

bool operator< (const card& card1, const card& card2);

bool operator<=(const card& card1, const card& card2);

bool operator> (const card& card1, const card& card2);

bool operator>=(const card& card1, const card& card2);

std::istream& operator<<(std::istream& fin, card& data);

std::ostream& operator>>(std::ostream& fout, card& data);