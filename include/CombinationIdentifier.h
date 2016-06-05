#ifndef COMBINATIONIDENTIFIER_H
#define COMBINATIONIDENTIFIER_H

#include <vector>
#include <algorithm>
#include <functional>

#include "Card.h"

namespace combination_strength
{
    enum Combinations
    {
        Nothing = -1,
        Pair = 100,
        Two_Pairs = 200,
        ThreeOfAKind = 300,
        Straight = 400,
        Flush = 500,
        FullHouse = 600,
        FourOfAKind = 700,
        StraightFlush = 800,
        RoyalFlush = 900
    };
}

class CombinationIdentifier
{
    public:
        CombinationIdentifier() = delete;
        CombinationIdentifier(const std::vector<Card>& inputCards);
        virtual ~CombinationIdentifier();

        const std::vector<Card>& GetCards() const;

        int DetectCombination();

    private:

    static const int NUMBERS_QUANTITY = 13;
    const int COMBINATIONS_QUANTITY = 9;

    int arrNumbers[NUMBERS_QUANTITY];

    std::vector<Card> cards;

    std::vector<std::function<int()>> detectCombination;

    void SortCardsByNumber();
    void SortCardsByNumber(int beginRange, int sizeRange);
    void SortCardsBySuit();

    std::pair<int, int> FindLongestSequenceOfSuit();
    std::pair<int, int> FindLongestSequenceOfConsecutiveNumbers();
    std::pair<int, int> FindLongestSequenceOfSameNumbers();

    void EnableArrNumbers();

    int DetectRoyalFlush();
    int DetectStraightFlush();
    int DetectFourOfAKind();
    int DetectFullHouse();
    int DetectFlush();
    int DetectStraight();
    int DetectThreeOfAKind();
    int DetectTwoPairs();
    int DetectPair();
};

#endif // COMBINATIONIDENTIFIER_H
