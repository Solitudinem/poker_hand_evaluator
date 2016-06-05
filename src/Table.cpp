#include "Table.h"

using namespace sizes;
using namespace table_symbols;

Table::Table() : DRAW_CARD_FUNCTION_QUANTITY(13)
{
    for (int j = 0; j < TableHeight; j++)
    {
        for (int i = 0; i < TableWidth; i++)
        {
            table[i][j] = EmptyCell;
        }
    }

//pushing draw methods in vector to be able to call them from one method DrawCard(int x, int y, const Card& card, int index = 0)
    drawCardFunctions.reserve(DRAW_CARD_FUNCTION_QUANTITY);
    drawCardFunctions.push_back(std::bind(&Table::DrawTwo, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    drawCardFunctions.push_back(std::bind(&Table::DrawThree, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    drawCardFunctions.push_back(std::bind(&Table::DrawFour, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    drawCardFunctions.push_back(std::bind(&Table::DrawFive, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    drawCardFunctions.push_back(std::bind(&Table::DrawSix, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    drawCardFunctions.push_back(std::bind(&Table::DrawSeven, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    drawCardFunctions.push_back(std::bind(&Table::DrawEight, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    drawCardFunctions.push_back(std::bind(&Table::DrawNine, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    drawCardFunctions.push_back(std::bind(&Table::DrawTen, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    drawCardFunctions.push_back(std::bind(&Table::DrawJack, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    drawCardFunctions.push_back(std::bind(&Table::DrawQueen, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    drawCardFunctions.push_back(std::bind(&Table::DrawKing, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    drawCardFunctions.push_back(std::bind(&Table::DrawAce, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
}

Table::~Table() {}
//x and y is a coordinates of top left corner of the card
void Table::DrawTwo(int x, int y, const Card& card, int index)
{
    try
    {
        CheckCoordinates(x, y);
    }
    catch(const std::out_of_range& exc)
    {
        std::cout << exc.what() << std::endl;
        return;
    }
//defining coordinates for number and for symbol of suit
    int shiftXY = 3;
    int coordY = y + 6;
    int leftNumberX = x + 1;
    int leftNumberY = y + 1;
    int rightNumberX = x + CardWidth - 2;
    int rightNumberY = y + CardHeight - 2;

    DrawBorder(x, y);

//draw the symbol of suit on card as is customary in a real cards
    switch(card.GetSuit())
    {
        case suites::Spades:
            table[x + shiftXY][y + shiftXY] = BlackSpade;
            table[x + shiftXY][y + coordY] = BlackSpade;
            break;
        case suites::Clubs:
            table[x + shiftXY][y + shiftXY] = BlackClub;
            table[x + shiftXY][y + coordY] = BlackClub;
            break;
        case suites::Hearts:
            table[x + shiftXY][y + shiftXY] = RedHeart;
            table[x + shiftXY][y + coordY] = RedHeart;
            break;
        case suites::Diamonds:
            table[x + shiftXY][y + shiftXY] = RedDiamond;
            table[x + shiftXY][y + coordY] = RedDiamond;
        break;
    }

//draw the number of card (number means face value)
    table[leftNumberX][leftNumberY] = Two;
    table[rightNumberX][rightNumberY] = Two;

    DrawIndex(x, y, index);
}

//x and y is a coordinates of top left corner of the card
void Table::DrawThree(int x, int y, const Card& card, int index)
{
    try
    {
        CheckCoordinates(x, y);
    }
    catch(const std::out_of_range& exc)
    {
        std::cout << exc.what() << std::endl;
        return;
    }
//defining coordinates for number and for symbol of suit
    int xCoord = x + 3;
    int firstY = y + 2;
    int secondY = y + 4;
    int thirdY = y + 6;
    int leftNominalX = x + 1;
    int leftNominalY = y + 1;
    int rightNominalX = x + CardWidth - 2;
    int rightNominalY = y + CardHeight - 2;

    DrawBorder(x, y);

//draw the symbol of suit on card as is customary in a real cards
    switch(card.GetSuit())
    {
        case suites::Spades:
            table[xCoord][firstY] = BlackSpade;
            table[xCoord][secondY] = BlackSpade;
            table[xCoord][thirdY] = BlackSpade;
            break;
        case suites::Clubs:
            table[xCoord][firstY] = BlackClub;
            table[xCoord][secondY] = BlackClub;
            table[xCoord][thirdY] = BlackClub;
            break;
        case suites::Hearts:
            table[xCoord][firstY] = RedHeart;
            table[xCoord][secondY] = RedHeart;
            table[xCoord][thirdY] = RedHeart;
            break;
        case suites::Diamonds:
            table[xCoord][firstY] = RedDiamond;
            table[xCoord][secondY] = RedDiamond;
            table[xCoord][thirdY] = RedDiamond;
            break;
    }

//draw the number of card (number means face value)
    table[leftNominalX][leftNominalY] = Three;
    table[rightNominalX][rightNominalY] = Three;

    DrawIndex(x, y, index);
}

//x and y is a coordinates of top left corner of the card
void Table::DrawFour(int x, int y, const Card& card, int index)
{
    try
    {
        CheckCoordinates(x, y);
    }
    catch(const std::out_of_range& exc)
    {
        std::cout << exc.what() << std::endl;
        return;
    }
//defining coordinates for number and for symbol of suit
    int firstX = x + 3;
    int firstY = y + 2;
    int secondX = x + 4;
    int secondY = y + 7;
    int leftNominalX = x + 1;
    int leftNominalY = y + 1;
    int rightNominalX = x + CardWidth - 2;
    int rightNominalY = y + CardHeight - 2;

    DrawBorder(x, y);

//draw the symbol of suit on card as is customary in a real cards
    switch(card.GetSuit())
    {
        case suites::Spades:
            table[firstX][firstY] = BlackSpade;
            table[secondX][firstY] = BlackSpade;
            table[firstX][secondY] = BlackSpade;
            table[secondX][secondY] = BlackSpade;
            break;
        case suites::Clubs:
            table[firstX][firstY] = BlackClub;
            table[secondX][firstY] = BlackClub;
            table[firstX][secondY] = BlackClub;
            table[secondX][secondY] = BlackClub;
            break;
        case suites::Hearts:
            table[firstX][firstY] = RedHeart;
            table[secondX][firstY] = RedHeart;
            table[firstX][secondY] = RedHeart;
            table[secondX][secondY] = RedHeart;
            break;
        case suites::Diamonds:
            table[firstX][firstY] = RedDiamond;
            table[secondX][firstY] = RedDiamond;
            table[firstX][secondY] = RedDiamond;
            table[secondX][secondY] = RedDiamond;
            break;
    }

//draw the number of card (number means face value)
    table[leftNominalX][leftNominalY] = Four;
    table[rightNominalX][rightNominalY] = Four;

    DrawIndex(x, y, index);
}

//x and y is a coordinates of top left corner of the card
void Table::DrawFive(int x, int y, const Card& card, int index)
{
    try
    {
        CheckCoordinates(x, y);
    }
    catch(const std::out_of_range& exc)
    {
        std::cout << exc.what() << std::endl;
        return;
    }

    int firstY = y + 3;
    int secondY = y + 4;
    int thirdY = y + 5;
    int firstX = x + 2;
    int secondX = x + 3;
    int thirdX = x + 4;
    int leftNominalX = x + 1;
    int leftNominalY = y + 1;
    int rightNominalX = x + CardWidth - 2;
    int rightNominalY = y + CardHeight - 2;

    char suit = GetCharSuit(card);

    for (int i = x; i < CardWidth + x; i++)
    {
        table[i][y] = HorizontalBorder;
        table[i][y + CardHeight - 1] = HorizontalBorder;
    }

    for (int j = y; j < CardHeight + y; j++)
    {
        table[x][j] = VerticalBorder;
        table[x + CardWidth - 1][j] = VerticalBorder;

        if (j == firstY || j == thirdY)
        {
            table[firstX][j] = suit;
            table[thirdX][j] = suit;
        }
        else if (j == secondY)
        {
            table[secondX][j] = suit;
        }
    }

    table[leftNominalX][leftNominalY] = Five;
    table[rightNominalX][rightNominalY] = Five;

    DrawIndex(x, y, index);
}

//x and y is a coordinates of top left corner of the card
void Table::DrawSix(int x, int y, const Card& card, int index)
{
    try
    {
        CheckCoordinates(x, y);
    }
    catch(const std::out_of_range& exc)
    {
        std::cout << exc.what() << std::endl;
        return;
    }

//defining coordinates for number and for symbol of suit
    int firstY = y + 2;
    int secondY = y + 4;
    int thirdY = y + 6;
    int firstX = x + 3;
    int secondX = x + 5;
    int leftNominalX = x + 1;
    int leftNominalY = y + 1;
    int rightNominalX = x + CardWidth - 2;
    int rightNominalY = y + CardHeight - 2;

    char suit = GetCharSuit(card);

    for (int i = x; i < CardWidth + x; i++)
    {
        table[i][y] = HorizontalBorder;
        table[i][y + CardHeight - 1] = HorizontalBorder;
    }

    for (int j = y; j < CardHeight + y; j++)
    {
        table[x][j] = VerticalBorder;
        table[x + CardWidth - 1][j] = VerticalBorder;

        if (j == firstY || j == secondY || j == thirdY)
        {
            table[firstX][j] = suit;
            table[secondX][j] = suit;
        }
    }

//draw the number of card (number means face value)
    table[leftNominalX][leftNominalY] = Six;
    table[rightNominalX][rightNominalY] = Six;

    DrawIndex(x, y, index);
}

//x and y is a coordinates of top left corner of the card
void Table::DrawSeven(int x, int y, const Card& card, int index)
{
    try
    {
        CheckCoordinates(x, y);
    }
    catch(const std::out_of_range& exc)
    {
        std::cout << exc.what() << std::endl;
        return;
    }

//defining coordinates for number and for symbol of suit
    int xCoord = x + 4;
    int yCoord = y + 3;
    int leftNominalX = x + 1;
    int leftNominalY = y + 1;
    int rightNominalX = x + CardWidth - 2;
    int rightNominalY = y + CardHeight - 2;

    char suit = GetCharSuit(card);

    DrawSix(x, y, card);

    table[xCoord][yCoord] = suit;

//draw the number of card (number means face value)
    table[leftNominalX][leftNominalY] = Seven;
    table[rightNominalX][rightNominalY] = Seven;

    DrawIndex(x, y, index);
}

//x and y is a coordinates of top left corner of the card
void Table::DrawEight(int x, int y, const Card& card, int index)
{
    try
    {
        CheckCoordinates(x, y);
    }
    catch(const std::out_of_range& exc)
    {
        std::cout << exc.what() << std::endl;
        return;
    }

//defining coordinates for number and for symbol of suit
    int xCoord = x + 4;
    int yCoord = y + 5;
    int leftNominalX = x + 1;
    int leftNominalY = y + 1;
    int rightNominalX = x + CardWidth - 2;
    int rightNominalY = y + CardHeight - 2;

    char suit = GetCharSuit(card);

    DrawSeven(x, y, card);

    table[xCoord][yCoord] = suit;

//draw the number of card (number means face value)
    table[leftNominalX][leftNominalY] = Eight;
    table[rightNominalX][rightNominalY] = Eight;

    DrawIndex(x, y, index);
}

//x and y is a coordinates of top left corner of the card
void Table::DrawNine(int x, int y, const Card& card, int index)
{
    try
    {
        CheckCoordinates(x, y);
    }
    catch(const std::out_of_range& exc)
    {
        std::cout << exc.what() << std::endl;
        return;
    }

//defining coordinates for number and for symbol of suit
    int firstY = y + 1;
    int secondY = y + 2;
    int thirdY = y + 3;
    int fourthY = y + 5;
    int fifthY = y + 7;
    int firstX = x + 3;
    int secondX = x + 4;
    int thirdX = x + 5;
    int leftNominalX = x + 1;
    int leftNominalY = y + 1;
    int rightNominalX = x + CardWidth - 2;
    int rightNominalY = y + CardHeight - 2;

    char suit = GetCharSuit(card);

    for (int i = x; i < CardWidth + x; i++)
    {
        table[i][y] = HorizontalBorder;
        table[i][y + CardHeight - 1] = HorizontalBorder;
    }

    for (int j = y; j < CardHeight + y; j++)
    {
        table[x][j] = VerticalBorder;
        table[x + CardWidth - 1][j] = VerticalBorder;

        if (j == firstY || j == thirdY || j == fourthY || j == fifthY)
        {
            table[firstX][j] = suit;
            table[thirdX][j] = suit;
        }
        else if (j == secondY)
        {
            table[secondX][j] = suit;
        }
    }

//draw the number of card (number means face value)
    table[leftNominalX][leftNominalY] = Nine;
    table[rightNominalX][rightNominalY] = Nine;

    DrawIndex(x, y, index);
}

//x and y is a coordinates of top left corner of the card
void Table::DrawTen(int x, int y, const Card& card, int index)
{
    try
    {
        CheckCoordinates(x, y);
    }
    catch(const std::out_of_range& exc)
    {
        std::cout << exc.what() << std::endl;
        return;
    }

//defining coordinates for number and for symbol of suit
    int coordX = x + 4;
    int coordY = y + 6;
    int leftOneX = x + 1;
    int leftOneY = y + 1;
    int leftZeroX = x + 2;
    int leftZeroY = y + 1;
    int rightZeroX = x + CardWidth - 2;
    int rightZeroY = y + CardHeight - 2;
    int rightOneX = x + CardWidth - 3;
    int rightOneY = y + CardHeight - 2;

    char suit = GetCharSuit(card);

    DrawNine(x, y, card);

    table[coordX][coordY] = suit;

//draw the number of card (number means face value)
    table[leftOneX][leftOneY] = One;
    table[leftZeroX][leftZeroY] = Zero;
    table[rightZeroX][rightZeroY] = Zero;
    table[rightOneX][rightOneY] = One;

    DrawIndex(x, y, index);
}

//x and y is a coordinates of top left corner of the card
void Table::DrawJack(int x, int y, const Card& card, int index)
{
    try
    {
        CheckCoordinates(x, y);
    }
    catch(const std::out_of_range& exc)
    {
        std::cout << exc.what() << std::endl;
        return;
    }

    DrawBorder(x, y);

    DrawCorners(x, y, card);

    DrawIndex(x, y, index);
}

//x and y is a coordinates of top left corner of the card
void Table::DrawQueen(int x, int y, const Card& card, int index)
{
    try
    {
        CheckCoordinates(x, y);
    }
    catch(const std::out_of_range& exc)
    {
        std::cout << exc.what() << std::endl;
        return;
    }

    DrawBorder(x, y);

    DrawCorners(x, y, card);

    DrawIndex(x, y, index);
}

//x and y is a coordinates of top left corner of the card
void Table::DrawKing(int x, int y, const Card& card, int index)
{
    try
    {
        CheckCoordinates(x, y);
    }
    catch(const std::out_of_range& exc)
    {
        std::cout << exc.what() << std::endl;
        return;
    }

    DrawBorder(x, y);

    DrawCorners(x, y, card);

    DrawIndex(x, y, index);
}

//x and y is a coordinates of top left corner of the card
void Table::DrawAce(int x, int y, const Card& card, int index)
{
    try
    {
        CheckCoordinates(x, y);
    }
    catch(const std::out_of_range& exc)
    {
        std::cout << exc.what() << std::endl;
        return;
    }

    DrawBorder(x, y);

    DrawCorners(x, y, card);

    DrawIndex(x, y, index);
}

//x and y is a coordinates of top left corner of the card
void Table::DrawCard(int x, int y, const Card& card, int index)
{
    try
    {
        drawCardFunctions[card.GetNumber()](x, y, card, index);
    }
    catch(const std::out_of_range& exc)
    {
        std::cout << exc.what() <<std::endl;
        return;
    }
}

//draw the strength and suit of card in the right top and left bottom corners of card
//'J' for Jack
//'Q' for Queen
//'K' for King
//'A' for Ace
//and suites
//'S' for spades
//'H' for hearts
//'D' for diamonds
//'C' for clubs
void Table::DrawCorners(int x, int y, const Card& card)
{
    char suit = GetCharSuit(card);
    char number = ' ';

    switch(card.GetNumber())
    {
        case numbers::Jack:
            number = Jack;
            break;
        case numbers::Queen:
            number = Queen;
            break;
        case numbers::King:
            number = King;
            break;
        case numbers::Ace:
            number = Ace;
            break;
    }
//defining of left top and right bottom coordinates of card with shift for printing
//symbols of strength and suit
//x and y is left top corner of card
    int leftSuitX = x + 2;
    int leftSuitY = y + 1;
    int rightSuitX = x + CardWidth - 2;
    int rightSuitY = y + CardHeight - 2;
    int leftNumberX = x + 1;
    int leftNumberY = y + 1;
    int rightNumberX = x + CardWidth - 3;
    int rightNumberY = y + CardHeight - 2;

    table[leftSuitX][leftSuitY] = suit;
    table[rightSuitX][rightSuitY] = suit;

    table[leftNumberX][leftNumberY] = number;
    table[rightNumberX][rightNumberY] = number;
}

//draw outer boundary of card
void Table::DrawBorder(int x, int y)
{
//draw top (point (i, y)) and bottom (point (i, y + CardHeight - 1)) border of card
    for (int i = x; i < CardWidth + x; i++)
    {
        table[i][y] = HorizontalBorder;
        table[i][y + CardHeight - 1] = HorizontalBorder;
    }
//draw left(point (x, j)) and right (point (x + CardWidth - 1, j)) border of card
    for (int j = y; j < CardHeight + y; j++)
    {
        table[x][j] = VerticalBorder;
        table[x + CardWidth - 1][j] = VerticalBorder;
    }
}

//draws the index of card for user
//player have two cards and five cards lie on the table, so it's seven
void Table::DrawIndex(int x, int y, int index)
{
    char number = ' ';
//number is index of card in container + 1 to make counting starts from 1 and not from zero
    switch(index)
    {
        case 0:
            number = One;
            break;
        case 1:
            number = Two;
            break;
        case 2:
            number = Three;
            break;
        case 3:
            number = Four;
            break;
        case 4:
            number = Five;
            break;
        case 5:
            number = Six;
            break;
        case 6:
            number = Seven;
            break;
    }
//point (x + CardWidth / 2, y + CardHeight + 1) lies right below card in the middle of its width
    table[x + CardWidth / 2][y + CardHeight + 1] = number;
}

void Table::PrintTable()
{
    for (int j = 0; j < TableHeight; j++)
    {
        for (int i = 0; i < TableWidth; i++)
        {
            std::cout << table[i][j];
        }
        std::cout << std::endl;
    }
}

void Table::CheckCoordinates(int x, int y)
{
    if (x + CardWidth >= TableWidth)
    {
        throw std::out_of_range("There is trouble with width of table. Try to paint this card in other place.");
    }

    if (y + CardHeight + 1 >= TableHeight)
    {
        throw std::out_of_range("There is trouble with height of table. Try to paint this card in other place.");
    }
}

/*
method returnes char represetation of suit
S = spades
C = clubs
D = diamonds
H = hearts
*/
char Table::GetCharSuit(const Card& card)
{
    char suit = ' ';
    switch(card.GetSuit())
    {
        case suites::Spades:
            suit = BlackSpade;
            break;
        case suites::Clubs:
            suit = BlackClub;
            break;
        case suites::Hearts:
            suit = RedHeart;
            break;
        case suites::Diamonds:
            suit = RedDiamond;
            break;
    }

    return suit;
}
