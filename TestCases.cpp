#include "Card.h"
#include "Queue.h"
#include "thpe14.h"
#include "..\\catch.hpp"

TEST_CASE("Enque")
{
    SECTION("Single element")
    {
        card c1;
        c1.faceValue = 10;
        c1.suit = 20;

        Queue<card> q1;

        CHECK(q1.size() == 0);

        q1.enque(c1);

        CHECK(q1.size() == 1);
    }

    SECTION("Two elements")
    {
        card c1, c2;
        c1.faceValue = 1;
        c1.suit = 2;
        c2.faceValue = 3;
        c2.suit = 4;

        Queue<card> q1;

        CHECK(q1.isEmpty() == true);

        q1.enque(c1);
        q1.enque(c2);

        CHECK(q1.size() == 2);
    }

    SECTION("Multiple")
    {
        Queue<card> q1;
        int seed = 2345;
        int i = 0;
        card aCard;
        int cardValue = 0;
        ostringstream sout;

        default_random_engine generator(seed);
        uniform_int_distribution<int> distribution(0, 51);

        for (i = 0; i < 5; i++)
        {
            cardValue = distribution(generator);
            aCard.faceValue = i;
            aCard.suit = 0;

            q1.enque(aCard);
        }

        CHECK(q1.size() == 5);
        q1.print(sout);

        REQUIRE(sout.str() == "AH 2H 3H 4H 5H");

    }
}

TEST_CASE("Deque")
{
    SECTION("Single element")
    {
        Queue<card> q1;
        card c1;
        card item;
        ostringstream sout1, sout2;

        c1.faceValue = 10;
        c1.suit = 1;

        q1.enque(c1);

        sout1 << q1;
        REQUIRE(sout1.str() == "JD");

        q1.deque(item);

        sout2 << q1;
        REQUIRE(sout2.str() == "");

    }

    SECTION("Multiple elements")
    {
        Queue<card> q1;
        card c1;
        card item;
        ostringstream sout1, sout2;
        int i = 0;

        for (i = 0; i < 5; i++)
        {
            c1.faceValue = i;
            c1.suit = 1;
            q1.enque(c1);
        }

        sout1 << q1;
        REQUIRE(sout1.str() == "AD 2D 3D 4D 5D");

        q1.deque(item);

        sout2 << q1;
        REQUIRE(sout2.str() == "2D 3D 4D 5D");

        CHECK(q1.size() == 4);
    }

}

TEST_CASE("Front")
{
    SECTION("empty queue")
    {
        Queue<card> q1;
        card item;

        q1.front(item);
        CHECK(q1.front(item) == false);

    }

    SECTION("Single element")
    {
        Queue<card> q1;
        card item;
        card c1;

        q1.front(item);
        CHECK(q1.front(item) == false);

        c1.faceValue = 2;
        c1.suit = 0;

        q1.enque(c1);
        CHECK(q1.front(item) == true);

        CHECK(item.faceValue == 2);
        CHECK(item.suit == 0);

    }


    SECTION("Multiple elements")
    {
        Queue<card> q1;
        card item;
        card c1, c2;

        q1.front(item);
        CHECK(q1.front(item) == false);

        c1.faceValue = 2;
        c1.suit = 0;

        q1.enque(c1);
        CHECK(q1.front(item) == true);

        CHECK(item.faceValue == 2);
        CHECK(item.suit == 0);

        c2.faceValue = 3;
        c2.suit = 2;

        q1.enque(c2);
        CHECK(q1.front(item) == true);

        CHECK(item.faceValue == 2);
        CHECK(item.suit == 0);
    }
}

TEST_CASE("Size")
{
    SECTION("No elements")
    {
        Queue<int> q1;
        CHECK(q1.size() == 0);
    }

    SECTION("Single element")
    {
        Queue<card> q2;
        card aCard;
        int i = 0;

        aCard.faceValue = 18;
        aCard.suit = 3;

        q2.enque(aCard);

        CHECK(q2.size() == 1);
    }

    SECTION("Multiple elements")
    {
        Queue<card> q3;
        card aCard;
        int i = 0;

        for (i = 0; i < 5; i++)
        {
            aCard.faceValue = i;
            aCard.suit = 2;
            q3.enque(aCard);
        }

        REQUIRE(q3.size() == 5);
    }
}

TEST_CASE("Print")
{
    SECTION("No elements")
    {
        Queue<card> q1;
        ostringstream sout;

        q1.print(sout);
        CHECK(sout.str() == "");

    }

    SECTION("Single element")
    {
        Queue<card> q2;
        card aCard;
        int i = 0;
        ostringstream sout;

        aCard.faceValue = 18 % 13;
        aCard.suit = 3;

        q2.enque(aCard);
        q2.print(sout);

        CHECK(sout.str() == "6S");
    }

    SECTION("Multiple elements")
    {
        Queue<card> q3;
        card aCard;
        int i = 0;
        ostringstream sout;

        for (i = 0; i < 5; i++)
        {
            aCard.faceValue = i;
            aCard.suit = 2;
            q3.enque(aCard);
        }

        q3.print(sout);

        REQUIRE(sout.str() == "AC 2C 3C 4C 5C");
    }
}

TEST_CASE("isEmpty and clear")
{
    SECTION("Inserting single element")
    {
        card c1;
        c1.faceValue = 10;
        c1.suit = 20;

        Queue<card> q1;

        CHECK(q1.isEmpty() == true);

        q1.enque(c1);

        CHECK(q1.isEmpty() == false);
    }

    SECTION("Inserting two elements")
    {
        card c1, c2;
        c1.faceValue = 1;
        c1.suit = 2;
        c2.faceValue = 3;
        c2.suit = 4;

        Queue<card> q1;

        CHECK(q1.isEmpty() == true);

        q1.enque(c1);
        q1.enque(c2);

        q1.clear();
        CHECK(q1.isEmpty() == true);

    }

    SECTION("Inserting multiple")
    {
        Queue<card> q1;
        int seed = 2345;
        int i = 0;
        card aCard;
        int cardValue = 0;
        ostringstream sout;

        default_random_engine generator(seed);
        uniform_int_distribution<int> distribution(0, 51);

        for (i = 0; i < 5; i++)
        {
            cardValue = distribution(generator);
            aCard.faceValue = i;
            aCard.suit = 0;

            q1.enque(aCard);
        }

        CHECK(q1.isEmpty() == false);
        q1.clear();
        CHECK(q1.isEmpty() == true);
    }
}

TEST_CASE("playRound - Single card wins")
{
    card aCard;
    int i;
    ostringstream sout1, sout2;
    Queue<card> p1, p2;
    int p1cards[2] = { 4, 8 };
    int p2cards[2] = { 2, 7 };

    for (i = 0; i < 2; i++)
    {
        aCard.faceValue = p1cards[i];
        aCard.suit = 0;
        p1.enque(aCard);

    }

    for (i = 0; i < 2; i++)
    {
        aCard.faceValue = p2cards[i];
        aCard.suit = 0;
        p2.enque(aCard);
    }

    SECTION("Single card wins")
    {
        playRound(p1, p2);

        sout1 << p1;
        sout2 << p2;
        REQUIRE(sout1.str() == "9H 3H 5H");
        REQUIRE(sout2.str() == "8H");
    }

    SECTION("Second round")
    {
        playRound(p1, p2);
        playRound(p1, p2);

        sout1 << p1;
        sout2 << p2;

        REQUIRE(sout1.str() == "3H 5H 8H 9H");
        REQUIRE(sout2.str() == "");
    }
}

TEST_CASE("playRound - Cards are equal")
{
    card aCard;
    int i;
    ostringstream sout1, sout2;
    Queue<card> p1, p2;
    int p1cards[10] = { 6, 5, 7, 2, 8, 3, 6, 2, 4, 1 };
    int p2cards[10] = { 6, 3, 4, 2, 3, 7, 11, 12, 2, 1 };

    default_random_engine generator(2432);
    uniform_int_distribution<int> distribution(0, 3);


    for (i = 0; i < 10; i++)
    {
        aCard.faceValue = p1cards[i];
        aCard.suit = 1;
        p1.enque(aCard);

    }

    for (i = 0; i < 10; i++)
    {
        aCard.faceValue = p2cards[i];
        aCard.suit = 1;
        p2.enque(aCard);
    }


    SECTION("check output")
    {
        playRound(p1, p2);

        sout1 << p1;
        sout2 << p2;

        REQUIRE(sout1.str() == "3D 5D 2D");
        REQUIRE(sout2.str() == "KD 3D 2D 7D 4D 9D 3D 8D 6D 7D QD 8D 4D 3D 5D 4D 7D");
    }
}

TEST_CASE("Errors")
{
    /*Queue<card> P1, P2;
    
    card one;
    one.faceValue = 12;
    one.suit = 2;

    card two;
    two.faceValue = 0;
    two.suit = 1;

    P1.enque(one);
    P2.enque(two);

    playWar(P1, P2);

    one.faceValue = 8;
    one.suit = 3;

    two.faceValue = 0;
    two.suit = 1;

    P1.enque(one);
    P2.enque(two);

    playWar(P1, P2);

    one.faceValue = 11;
    one.suit = 0;

    two.faceValue = 0;
    two.suit = 1;

    P1.enque(one);
    P2.enque(two);

    playWar(P1, P2);*/
}

TEST_CASE("Tie - no cards left")
{
    //card aCard;

    //Queue<card> p1, p2;
    //int p1cards[3] = { 9, 3, 6 };
    //int p2cards[3] = { 8, 3, 6 };
    //for (int i = 0; i < 3; i++)
    //{
    //    aCard.faceValue = p1cards[i];
    //    aCard.suit = 0; // gave it a suit of hearts
    //    p1.enque(aCard);
    //}
    //for (int i = 0; i < 3; i++)
    //{
    //    aCard.faceValue = p2cards[i];
    //    aCard.suit = 0; // gave it a suit of hearts
    //    p2.enque(aCard);
    //}

    //playWar(p1, p2);
}