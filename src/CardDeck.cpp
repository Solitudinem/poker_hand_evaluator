#include "CardDeck.h"

CardDeck::CardDeck()
{
    deck.reserve(CARDS_QUANTITY);
    for (int i = 0; i < CARDS_QUANTITY; i++)
    {
        deck.push_back(Card(i % 4, i / 4));
    }

//shuffle card deck
    std::random_device rd;
    std::mt19937 shuffler(rd());
    std::shuffle(deck.begin(), deck.end(), shuffler);
}

CardDeck::~CardDeck() {}

std::vector<Card> CardDeck::GetCardsToPlay()
{
//give seven cards to imaginary player. Five for table and two in players hands;
    std::vector<Card> cards(deck.cbegin(), deck.cbegin() + PLAYER_CARDS_QUANTITY);

    deck.erase(deck.cbegin(), deck.cbegin() + PLAYER_CARDS_QUANTITY);
    deck.shrink_to_fit();

    SetIsOwn(cards);

    return cards;
}

void CardDeck::SetIsOwn(std::vector<Card>& cards)
{
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(0, cards.size() - 1);

    int firstIndex = distr(eng);
    int secondIndex = distr(eng);
    cards[firstIndex].IsOwn(true);

    while(firstIndex == secondIndex)
    {
        secondIndex = distr(eng);
    }

    cards[secondIndex].IsOwn(true);
}
