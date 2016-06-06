#include "Card.h"

Card::Card() : suit(0), number(0) {}
Card::Card(const Card& other) : suit(other.suit), number(other.number), isOwn(other.isOwn) {}
Card::Card(int inputSuit, int inputNumber) : isOwn(false)
{
    if (inputSuit < MIN_SUIT || inputSuit > MAX_SUIT)
    {
        suit = 0;
    }

    if (inputNumber < MIN_NUMBER || inputNumber > MAX_NUMBER)
    {
        number = 0;
    }

    suit = inputSuit;
    number = inputNumber;
}

Card::~Card() {}

Card& Card::operator= (const Card& rhs)
{
    if (this == &rhs)
    {
        return *this; // handle self assignment
    }

    suit = rhs.suit;
    number = rhs.number;
    isOwn = rhs.isOwn;

    return *this;
}

int Card::GetSuit() const
{
    return suit;
}
void Card::SetSuit(int value)
{
    if (value < MIN_SUIT)
    {
        throw std::invalid_argument("We cannot set negative nominal");
        throw;
    }
    else if (value > MAX_SUIT)
    {
        throw std::invalid_argument("We cannot set nominal more than Ace nominal value (which equal 12)");
        throw;
    }

    suit = value;
}

int Card::GetNumber() const
{
    return number;
}
void Card::SetNumber(int value)
{
    if (value < MIN_NUMBER)
    {
        throw std::invalid_argument("We cannot set negative nominal");
        throw;
    }
    else if (value > MAX_NUMBER)
    {
        throw std::invalid_argument("We cannot set nominal more than Ace nominal value (which equal 12)");
        throw;
    }

    number = value;
}

bool Card::IsOwn() const
{
    return isOwn;
}
void Card::IsOwn(bool inputIsOwn)
{
    isOwn = inputIsOwn;
}
