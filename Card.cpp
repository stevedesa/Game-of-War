/** *****************************************************************
* @file
*
* @brief Contains the function definitions of all the card overload
* operators.
*******************************************************************/
#include "Card.h"
#include "Queue.h"
#include "thpe14.h"

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function returns true if the 2 cards have the same faceValue.
 *
 * @param[in, out] card1 - contains data of card1.
 * @param[in, out] card2 - contains data of card2.
 *
 * @returns true if card1 and card2 have same faceValue
 *
 * @par Example
 * @verbatim
   Card p1, p2;
   p1.faceValue = 0;
   p2.faceValue = 0;

   if(p1 == p2)
   {
        cout << "Cards have same faceValue" << endl;
   }
   @endverbatim
 *****************************************************************************/
bool operator==(const card& card1, const card& card2)
{
    if (card1.faceValue == card2.faceValue)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function returns true if the 2 cards don't have the same faceValue.
 *
 * @param[in, out] card1 - contains data of card1.
 * @param[in, out] card2 - contains data of card2.
 *
 * @returns true if card1 and card2 dont have same faceValue
 *
 * @par Example
 * @verbatim
   Card p1, p2;
   p1.faceValue = 0;
   p2.faceValue = 10;

   if(p1 != p2)
   {
        cout << "Cards don't have same faceValue" << endl;
   }
   @endverbatim
 *****************************************************************************/
bool operator!=(const card& card1, const card& card2)
{
    if (card1.faceValue != card2.faceValue)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function returns true if the card2 has greater faceValue than card1.
 * Ace is the highest value.
 *
 * @param[in, out] card1 - contains data of card1.
 * @param[in, out] card2 - contains data of card2.
 *
 * @returns true if card2 is bigger than card1.
 *
 * @par Example
 * @verbatim
   Card p1, p2;
   p1.faceValue = 10;
   p2.faceValue = 0;

   if(p1 < p2)
   {
        cout << "Card2 is bigger than Card1" << endl;
   }
   @endverbatim
 *****************************************************************************/
bool operator< (const card& card1, const card& card2)
{
    card lhs = card1;
    card rhs = card2;

    if (lhs.faceValue == 0)
        lhs.faceValue += 13;

    if (rhs.faceValue == 0)
        rhs.faceValue += 13;

    return lhs.faceValue < rhs.faceValue;
}

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function returns true if the card2 has greater than equal to faceValue 
 * than card1. Ace is the highest value.
 *
 * @param[in, out] card1 - contains data of card1.
 * @param[in, out] card2 - contains data of card2.
 *
 * @returns true if card2 is greater than equal to card1.
 *
 * @par Example
 * @verbatim
   Card p1, p2;
   p1.faceValue = 10;
   p2.faceValue = 0;

   if(p1 =< p2)
   {
        cout << "Card2 is bigger than Card1" << endl;
   }
   @endverbatim
 *****************************************************************************/
bool operator<=(const card& card1, const card& card2)
{
    card lhs = card1;
    card rhs = card2;

    if (lhs.faceValue == 0)
        lhs.faceValue += 13;

    if (rhs.faceValue == 0)
        rhs.faceValue += 13;

    return lhs.faceValue <= rhs.faceValue;
}

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function returns true if the card1 has greater faceValue than card2.
 * Ace is the highest value.
 *
 * @param[in, out] card1 - contains data of card1.
 * @param[in, out] card2 - contains data of card2.
 *
 * @returns true if card1 is bigger than card2.
 *
 * @par Example
 * @verbatim
   Card p1, p2;
   p1.faceValue = 0;
   p2.faceValue = 10;

   if(p1 > p2)
   {
        cout << "Card1 is bigger than Card2" << endl;
   }
   @endverbatim
 *****************************************************************************/
bool operator> (const card& card1, const card& card2)
{
    card lhs = card1;
    card rhs = card2;

    if (lhs.faceValue == 0)
        lhs.faceValue += 13;

    if (rhs.faceValue == 0)
        rhs.faceValue += 13;

    return lhs.faceValue > rhs.faceValue;
}

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function returns true if the card1 has greater than equal to faceValue 
 * than card2. Ace is the highest value.
 *
 * @param[in, out] card1 - contains data of card1.
 * @param[in, out] card2 - contains data of card2.
 *
 * @returns true if card1 is greater than equal to card2.
 *
 * @par Example
 * @verbatim
   Card p1, p2;
   p1.faceValue = 0;
   p2.faceValue = 10;

   if(p1 >= p2)
   {
        cout << "Card1 is bigger than Card2" << endl;
   }
   @endverbatim
 *****************************************************************************/
bool operator>=(const card& card1, const card& card2)
{
    card lhs = card1;
    card rhs = card2;

    if (lhs.faceValue == 0)
        lhs.faceValue += 13;

    if (rhs.faceValue == 0)
        rhs.faceValue += 13;

    return lhs.faceValue >= rhs.faceValue;
}

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function stores the fin card read value's facevalue and suit into the 
 * card structure. It does this for each individual input number.
 *
 * @param[in, out] fin - contains input stream.
 * @param[in, out] data - contains data of card.
 *
 * @returns the input stream after performing file read.
 *
 * @par Example
 * @verbatim
   card temp;
   ifstream file;

   file << temp; //Stores facevalue and suit in card structure temp
   @endverbatim
 *****************************************************************************/
std::istream &operator<<(std::istream &fin, card& data)
{
    int cardValue;

    fin >> cardValue;

    data.faceValue = cardValue % 13;
    data.suit = cardValue / 13;

    return fin;
}

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function outputs the faceValue and suit of the respective card structure.
 * If the faceValue is a 0, 9, 10, 11 or 12 it outputs A,T,J,Q or k respectively.
 * It prints out the suit. 0, 1, 2, 3 = H,D,C,S respectively.
 *
 * @param[in, out] fout - contains output stream.
 * @param[in, out] data - contains data of card.
 *
 * @returns the output stream after performing file read.
 *
 * @par Example
 * @verbatim
   card temp;
   ofstream file;

   file >> temp; //prints facevalue and suit of card structure temp
   @endverbatim
 *****************************************************************************/
std::ostream& operator>>(std::ostream& fout, card& data)
{
    //Print FaceValue
    if (data.faceValue == 0)
    {
        fout << "A"; //Ace
    }
    else if (data.faceValue == 9)
    {
        fout << "T"; //Ten
    }
    else if (data.faceValue == 10)
    {
        fout << "J"; //Jack
    }
    else if (data.faceValue == 11)
    {
        fout << "Q"; //Queen
    }
    else if (data.faceValue == 12)
    {
        fout << "K"; //King
    }
    else
    {
        fout << int(data.faceValue + 1); //Number
    }

    //Print Suit
    if (data.suit == 0)
    {
        fout << "H"; //Hearts
    }
    else if (data.suit == 1)
    {
        fout << "D"; //Diamonds
    }
    else if (data.suit == 2)
    {
        fout << "C"; //Clubs
    }
    else
    {
        fout << "S"; //Spades
    }

    return fout;
}