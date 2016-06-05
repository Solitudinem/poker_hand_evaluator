#include "Identifier.h"

Identifier::Identifier() : playerCards(deck.GetCardsToPlay()), ci(playerCards)
{
    int firstOwnCardNumber = -1;
    int secondOwnCardNumber = -1;
    int combination = 0;

    size_t length = playerCards.size();
    for (size_t i = 0, j = 0; i < length; i++, j += 11)
    {
        table.DrawCard(j, 0, playerCards[i], i);

        if (playerCards[i].IsOwn() && firstOwnCardNumber < 0)
        {
            firstOwnCardNumber = i + 1;
        }
        else if (playerCards[i].IsOwn() && firstOwnCardNumber > 0)
        {
            secondOwnCardNumber = i + 1;
        }
    }

    table.PrintTable();

    combination = ci.DetectCombination();

    ShowResult(combination, firstOwnCardNumber, secondOwnCardNumber);
}
Identifier::~Identifier() {}

void Identifier::ShowResult(int combination, int firstOwnCardNumber, int secondOwnCardNumber)
{
    if (combination == combination_strength::RoyalFlush)
    {
        std::cout << "Congratulations, you have: " << ROYAL_FLUSH << ". Your cards numbers are: " << firstOwnCardNumber << " and " << secondOwnCardNumber <<   std::endl;
    }
    else if (combination >= combination_strength::StraightFlush && combination < combination_strength::RoyalFlush)
    {
        std::cout << "Congratulations, you have: " << STRAIGHT_FLUSH << ". Your cards numbers are: " << firstOwnCardNumber << " and " << secondOwnCardNumber <<   std::endl;
    }
    else if (combination >= combination_strength::FourOfAKind && combination < combination_strength::StraightFlush)
    {
        std::cout << "Congratulations, you have: " << FOUR_OF_A_KIND << ". Your cards numbers are: " << firstOwnCardNumber << " and " << secondOwnCardNumber <<   std::endl;
    }
    else if (combination >= combination_strength::FullHouse && combination < combination_strength::FourOfAKind)
    {
        std::cout << "Congratulations, you have: " << FULL_HOUSE << ". Your cards numbers are: " << firstOwnCardNumber << " and " << secondOwnCardNumber <<   std::endl;
    }
    else if (combination >= combination_strength::Flush && combination < combination_strength::FullHouse)
    {
        std::cout << "Congratulations, you have: " << FLUSH << ". Your cards numbers are: " << firstOwnCardNumber << " and " << secondOwnCardNumber <<   std::endl;
    }
    else if (combination >= combination_strength::Straight && combination < combination_strength::Flush)
    {
        std::cout << "Congratulations, you have: " << STRAIGHT << ". Your cards numbers are: " << firstOwnCardNumber << " and " << secondOwnCardNumber <<   std::endl;
    }
    else if (combination >= combination_strength::ThreeOfAKind && combination < combination_strength::Straight)
    {
        std::cout << "Congratulations, you have: " << THREE_OF_A_KIND << ". Your cards numbers are: " << firstOwnCardNumber << " and " << secondOwnCardNumber <<   std::endl;
    }
    else if (combination >= combination_strength::Two_Pairs && combination < combination_strength::ThreeOfAKind)
    {
        std::cout << "Congratulations, you have: " << TWO_PAIRS << ". Your cards numbers are: " << firstOwnCardNumber << " and " << secondOwnCardNumber <<   std::endl;
    }
    else if (combination >= combination_strength::Pair && combination < combination_strength::Two_Pairs)
    {
        std::cout << "Congratulations, you have: " << PAIR << ". Your cards numbers are: " << firstOwnCardNumber << " and " << secondOwnCardNumber <<   std::endl;
    }
    else
    {
        std::cout << "Sorry, you have: " << NOTHING << ". Your cards numbers are: " << firstOwnCardNumber << " and " << secondOwnCardNumber <<   std::endl;
    }
}
