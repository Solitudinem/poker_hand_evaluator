#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include <string>

#include "CardDeck.h"
#include "Table.h"
#include "CombinationIdentifier.h"

class Identifier
{
    public:
        Identifier();
        virtual ~Identifier();

    private:

    const std::string ROYAL_FLUSH = "Royal Flush";
    const std::string STRAIGHT_FLUSH = "Straight Flush";
    const std::string FOUR_OF_A_KIND = "Four of a Kind";
    const std::string FULL_HOUSE = "Full House";
    const std::string FLUSH = "Flush";
    const std::string STRAIGHT = "Straight";
    const std::string THREE_OF_A_KIND = "Three of a Kind";
    const std::string TWO_PAIRS = "Two Pairs";
    const std::string PAIR = "Pair";
    const std::string NOTHING = "nothing";

    CardDeck deck;

    std::vector<Card> playerCards;

    Table table;

    CombinationIdentifier ci;

    void ShowResult(int combination, int firstOwnCardNumber, int secondOwnCardNumber);
};

#endif // IDENTIFIER_H
