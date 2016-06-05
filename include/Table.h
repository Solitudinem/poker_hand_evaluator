#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <stdexcept>
#include <functional>
#include <vector>

#include "Card.h"

namespace sizes
{
    enum Sizes
    {
        TableWidth = 80,
        TableHeight = 15,
        CardWidth = 8,
        CardHeight = 10
    };
}

namespace numbers
{
    enum Nominals
    {
        Jack = 9,
        Queen = 10,
        King = 11,
        Ace = 12,
    };
}

namespace suites
{
    enum Suites
    {
        Spades = 0,
        Clubs = 1,
        Hearts = 2,
        Diamonds = 3
    };
}

namespace table_symbols
{
    enum CardSymbols
    {
        BlackSpade = 'S',
        RedHeart = 'H',
        RedDiamond = 'D',
        BlackClub = 'C',
        Zero = '0',
        One = '1',
        Two = '2',
        Three = '3',
        Four = '4',
        Five = '5',
        Six = '6',
        Seven = '7',
        Eight = '8',
        Nine = '9',
        Jack = 'J',
        Queen = 'Q',
        King = 'K',
        Ace = 'A'
    };

    enum TableSymbols
    {
        VerticalBorder = '|',
        HorizontalBorder = '-',
        EmptyCell = ' '
    };
}

class Table
{
    public:
        Table();
        virtual ~Table();

        void DrawCard(int x, int y, const Card& card, int index = 0);

        void PrintTable();

    private:

    const int DRAW_CARD_FUNCTION_QUANTITY;

    std::vector<std::function<void(int, int, const Card&, int)>> drawCardFunctions;

    char table[sizes::TableWidth][sizes::TableHeight];

    void CheckCoordinates(int x, int y);

//int x and int y - coordinates of left top corner of card image
    void DrawBorder(int x, int y);
    void DrawCorners(int x, int y, const Card& card);
    void DrawIndex(int x, int y, int index = 0);

//int x and int y - coordinates of left top corner of the card image, int index - index of card in correspunding container
    void DrawTwo(int x, int y, const Card& card, int index = 0);
    void DrawThree(int x, int y, const Card& card, int index = 0);
    void DrawFour(int x, int y, const Card& card, int index = 0);
    void DrawFive(int x, int y, const Card& card, int index = 0);
    void DrawSix(int x, int y, const Card& card, int index = 0);
    void DrawSeven(int x, int y, const Card& card, int index = 0);
    void DrawEight(int x, int y, const Card& card, int index = 0);
    void DrawNine(int x, int y, const Card& card, int index = 0);
    void DrawTen(int x, int y, const Card& card, int index = 0);
    void DrawJack(int x, int y, const Card& card, int index = 0);
    void DrawQueen(int x, int y, const Card& card, int index = 0);
    void DrawKing(int x, int y, const Card& card, int index = 0);
    void DrawAce(int x, int y, const Card& card, int index = 0);


/*
method returnes char represetation of suit
S = spades
C = clubs
D = diamonds
H = hearts
*/
    char GetCharSuit(const Card& card);
};

#endif // TABLE_H
