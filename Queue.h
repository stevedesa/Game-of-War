/** *****************************************************************
* @file
*
* @brief Contains the Queue class declaration and function definitions.
*******************************************************************/
#include <fstream>
#include <iostream>

using std::ostream;
using std::string;
using std::nothrow;

using namespace std;

/** *****************************************************************
* @brief Contains the template Queue class.
*******************************************************************/
template <class TY>
class Queue
{
public:
    Queue();   //constructor for the class
    ~Queue();  //destructor for the class

    bool enque(TY item);      //adds element to the queue
    bool deque(TY &item);     //removes front element from the queue
    bool front(TY &item);       //returns element at the front of the queue
    bool isEmpty();             //checks if queue is empty
    void clear();               //cleares the queue
    int size();                 //returns the size of the queue
    void print(ostream& out);   //outputs elements of queue to relevant stream

    template <class TY>
    friend ostream& operator << (ostream& xout, Queue<TY>& hand);

private:
    /** *****************************************************************
    * @brief Structure holds the data of a node.
    *******************************************************************/
    struct node
    {
        /** *****************************************************************
        * @brief Stores card data in the queue.
        *******************************************************************/
        TY card_data;  
        /** *****************************************************************
        * @brief Points to the next item in the queue.
        *******************************************************************/
        node* next;         
    };
    /** *****************************************************************
    * @brief Points to head node in the queue.
    *******************************************************************/
    node* headptr;   
    /** *****************************************************************
    * @brief Points to tail node in the queue.
    *******************************************************************/
    node* tailptr;          
};

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * The constructor of the Queue function that initializes data.

 * @par Example
 * @verbatim
   Queue<card> player1; //Calls the constructor
   @endverbatim
 *****************************************************************************/
template <class TY>
Queue<TY>::Queue()
{
    headptr = nullptr;
    tailptr = nullptr;
}

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * The destructor of the Queue function that clears the data of the linked list.

 * @par Example
 * @verbatim
   Queue<card> player1; //Calls the destructor when the Queue goes out of scope.
   @endverbatim
 *****************************************************************************/
template <class TY>
Queue<TY>::~Queue()
{
    node* temp = headptr;

    while (temp != nullptr)
    {
        headptr = headptr->next;
        delete temp;
        temp = headptr; //next headptr
    }

    tailptr = nullptr;
}

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function adds an item to the queue.
 * 
 * @param[in] item - contains data of the item to be inserted
 * 
 * @returns true if the data is added successfully
 * 
 * @par Example
 * @verbatim
   Queue<int> player1;
   int card = 0;
   player1.enque(item);
   @endverbatim
 *****************************************************************************/
template <class TY>
bool Queue<TY>::enque(TY item)
{
    node* newNode = new (nothrow) node;

    if (newNode == nullptr)
    {
        cout << "Unable to allocate memory" << endl;
        return false;
    }

    newNode->card_data = item;
    newNode->next = nullptr;

    if (headptr == nullptr)
    {
        headptr = newNode;
        tailptr = newNode;
        return true;
    }
    else
    {
        tailptr->next = newNode;
        newNode->next = nullptr;
        tailptr = newNode;
        return true;
    }
}

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function removes the first item from the queue.
 *
 * @param[in] item - contains data of the item that will be removed
 *
 * @returns true if the data is removed successfully
 *
 * @par Example
 * @verbatim
   Queue<int> player1;
   int card = 0;
   player1.enque(item);
   player2.deque(item); //removes item from the queue
   @endverbatim
 *****************************************************************************/
template <class TY>
bool Queue<TY>::deque(TY &item)
{
    node* temp = headptr;

    item = temp->card_data;

    headptr = headptr->next;

    delete temp; //Delete node

    return true;
}

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function returns the item at the front of the queue.
 *
 * @param[in] item - contains data of the item at the front of the queue
 *
 * @returns true if the data is found successfully
 *
 * @par Example
 * @verbatim
   Queue<int> player1;
   int card = 0;
   player1.enque(item);
   player2.front(item); //Item = 0 at the front of the queue
   @endverbatim
 *****************************************************************************/
template <class TY>
bool Queue<TY>::front(TY &item)
{
    if (headptr == nullptr)
    {
        return false;
    }
    else
    {
        item = headptr->card_data;
        return true;
    }
}

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function checks if the queue is empty or not.
 *
 * @returns true if the queue is empty.
 *
 * @par Example
 * @verbatim
   Queue<int> player1;
   int card = 0;
   player1.enque(item);

   bool value = isEmpty(); //this will be false as queue is not empty
   @endverbatim
 *****************************************************************************/
template <class TY>
bool Queue<TY>::isEmpty()
{
    if (headptr == nullptr)
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
 * This function clears the queue.
 *

 * @par Example
 * @verbatim
   Queue<int> player1;
   int card = 0;
   player1.enque(item);
   player1.clear(); //Empties the queue
   @endverbatim
 *****************************************************************************/
template <class TY>
void Queue<TY>::clear()
{
    node* temp = headptr;

    while (temp != nullptr)
    {
        headptr = headptr->next;

        delete temp;

        temp = headptr; //next headptr
    }
}

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function returns the number of items in the queue.

 * @returns the size of the queue.
 *
 * @par Example
 * @verbatim
   Queue<int> player1;
   int card = 0;
   player1.enque(item);

   int size = player1.size(); //size = 1
   @endverbatim
 *****************************************************************************/
template <class TY>
int Queue<TY>::size()
{
    node* temp = headptr;
    int size = 0;

    while (temp != nullptr)
    {
        size++;
        temp = temp->next;
    }

    return size;
}

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function prints all the elements in the queue with the respective suit
 * and faceValue the card belongs to.
 *
 * @param[in, out] out - contains the appropriate output stream.
 *
 * @par Example
 * @verbatim
   Queue<card> player1;
   card.faceValue = 0;
   card.suit = 0;
   player1.enque(item);

   player1.print(cout); //Output: 0H
   @endverbatim
 *****************************************************************************/
template <class TY>
void Queue<TY>::print(ostream& out)
{
    node* temp = headptr;

    while (temp != nullptr)
    {
        out >> temp->card_data;
        
        //Separator
        if (temp->next != nullptr)
        {
            out << " "; //Space
        }

        temp = temp->next;
    }
}

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function calls the print function. It is an extension of the overload
 * function to print out a queue.
 *
 * @param[in, out] xout - contains the appropriate output stream.
 * @param[in, out] hand - contains the data of the hand.
 *
 * @returns the output stream
 *
 * @par Example
 * @verbatim
   Queue<int> player1;
   int card = 0;
   player1.enque(item);

   cout << player1; //Output: 1
   @endverbatim
 *****************************************************************************/
template <class TY>
ostream& operator << (ostream& xout, Queue<TY>& hand)
{
    //print the queue
    hand.print(xout);

    //return the ostream
    return xout;
}