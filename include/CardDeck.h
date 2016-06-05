#ifndef CARDDECK_H
#define CARDDECK_H

#include <algorithm>
#include <random>

#include "Card.h"

class CardDeck
{
    public:
        CardDeck();
        virtual ~CardDeck();

        std::vector<Card> GetCardsToPlay();

    private:

    const int CARDS_QUANTITY = 52;
    const int PLAYER_CARDS_QUANTITY = 7;

    std::vector<Card> deck;

//set isOwn property of card to true to randomly choosed two cards
    void SetIsOwn(std::vector<Card>& cards);
};

#endif // CARDDECK_H
