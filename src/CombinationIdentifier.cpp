#include "CombinationIdentifier.h"

using namespace combination_strength;

CombinationIdentifier::CombinationIdentifier(const std::vector<Card>& inputCards)
{
//copy cards from table and player to local vector<Card> cards
    std::copy(inputCards.cbegin(), inputCards.cend(), std::back_inserter(cards));

//pushing methods of combination determination in vector
    detectCombination.reserve(COMBINATIONS_QUANTITY);
    detectCombination.push_back(std::bind(&CombinationIdentifier::DetectRoyalFlush, this));
    detectCombination.push_back(std::bind(&CombinationIdentifier::DetectStraightFlush, this));
    detectCombination.push_back(std::bind(&CombinationIdentifier::DetectFourOfAKind, this));
    detectCombination.push_back(std::bind(&CombinationIdentifier::DetectFullHouse, this));
    detectCombination.push_back(std::bind(&CombinationIdentifier::DetectFlush, this));
    detectCombination.push_back(std::bind(&CombinationIdentifier::DetectStraight, this));
    detectCombination.push_back(std::bind(&CombinationIdentifier::DetectThreeOfAKind, this));
    detectCombination.push_back(std::bind(&CombinationIdentifier::DetectTwoPairs, this));
    detectCombination.push_back(std::bind(&CombinationIdentifier::DetectPair, this));
}
CombinationIdentifier::~CombinationIdentifier() {}

const std::vector<Card>& CombinationIdentifier::GetCards() const
{
    return cards;
}

void CombinationIdentifier::SortCardsByNumber()
{
    std::sort(cards.begin(), cards.end(), [](const Card& i, const Card& j) {return j.GetNumber() < i.GetNumber(); });
}
void CombinationIdentifier::SortCardsByNumber(int beginRange, int sizeRange)
{
    std::sort(cards.begin() + beginRange, cards.begin() + beginRange + sizeRange, [](const Card& i, const Card& j) {return j.GetNumber() < i.GetNumber(); });
}
//cards of the same suit now will be adjacent in vector<Card> cards
void CombinationIdentifier::SortCardsBySuit()
{
    std::sort(cards.begin(), cards.end(), [](const Card& i, const Card& j) {return j.GetSuit() < i.GetSuit(); });
}

//pair.first = start index of sequence of cards of the same suit in vector<Card> cards
//pair.second = length of that sequence in vector<Card> cards
std::pair<int, int> CombinationIdentifier::FindLongestSequenceOfSuit()
{
    int startIndex = -1;
    int counter = 0;
    int sequenceLength = 0;
    size_t length = cards.size();

    SortCardsBySuit();

    for (size_t i = 0; i < length; i++)
    {
        if (cards[i].GetSuit() == cards[i - 1].GetSuit())   //if suites of adjacent cards are same...
        {
            counter++;                                      //increment counter
        }
        else
        {
            counter = 0;
        }

        if (counter > sequenceLength)                       //if counter is bigger than sequence length, that we already found...
        {
            sequenceLength = counter;                       //assign it to sequence length
            startIndex = i - sequenceLength;                //define start index of sequence
        }
    }
//true length of sequnce is always +1 to number of matches
    ++sequenceLength;

    return std::pair<int, int>(startIndex, sequenceLength);
}

//pair.first = start index of sequnce of cards with consecutive numbers in vector<Card> cards
//pair.second = length of that sequence in vector<Card> cards
std::pair<int, int> CombinationIdentifier::FindLongestSequenceOfConsecutiveNumbers()
{
    int startIndex = -1;
    int counter = 0;
    int sequenceLength = 0;
    size_t length = cards.size();

    SortCardsByNumber();

    for (size_t i = 1; i < length; i++)
    {
        if (cards[i].GetNumber() == (cards[i - 1].GetNumber() - 1))   //if number of card is one lower, than number of preceding card...
        {
            counter++;                                                  //increment counter
        }
        else
        {
            counter = 0;
        }

        if (counter > sequenceLength)           //if counter is bigger than sequence length, that we already found...
        {
            sequenceLength = counter;           //assign it to sequence length
            startIndex = i - sequenceLength;    //define start index of sequence
        }
    }
//the true length of sequnce is always +1 to counter of matches;
    sequenceLength++;
    return std::pair<int, int>(startIndex, sequenceLength);
}

//pair.first = start index of sequence of cards of the same number
//pair.second = length of sequence of cards of the same number
std::pair<int, int> CombinationIdentifier::FindLongestSequenceOfSameNumbers()
{
    int startIndex = -1;
    int counter = 0;
    int sequenceLength = 0;
    size_t length = cards.size();

    SortCardsByNumber();

    for (size_t i = 1; i < length; i++)
    {
        if (cards[i].GetNumber() == cards[i - 1].GetNumber())     //if numbers of adjacent cards are same...
        {
            counter++;                                            //increment counter
        }
        else
        {
            counter = 0;
        }

        if (counter > sequenceLength)           //if counter is bigger than sequence length, that we already found...
        {
            sequenceLength = counter;           //assign it to sequence length
            startIndex = i - sequenceLength;    //define start index of sequence
        }
    }
//the true length of sequnce is always +1 to counter of matches;
    sequenceLength++;

    return std::pair<int, int>(startIndex, sequenceLength);
}

//arrNumbers is array of quantity of entries of each number from vector<Card> cards, where index is number(0 - 2, 1 - 3 ... 12 - ace) and value is quantity of entries
void CombinationIdentifier::EnableArrNumbers()
{
    size_t length = cards.size();
    std::fill(std::begin(arrNumbers), std::end(arrNumbers), 0);

    for (size_t i = 0; i < length; i++)
    {
        arrNumbers[cards[i].GetNumber()]++;       //increment the value in index, which (index) equals to card number
    }
}

//Royal Flush - five consecutive cards of the same suit starting from 10
int CombinationIdentifier::DetectRoyalFlush()
{
    int aceNumber = 12;        //0 - 2, 1 - 3, 12 - ace
    int counter = 0;
    int isThereOwnCard = 0;
    int sequnceLength = 4;
    int necessaryLength = 5;

    std::pair<int, int> sequence = FindLongestSequenceOfSuit();
    SortCardsByNumber(sequence.first, sequence.second);
//if sequnece of suit starts from ace and its length is 5 or bigger
    if (cards[sequence.first].GetNumber() == aceNumber && sequence.second >= necessaryLength)
    {
        int length = sequence.first + sequence.second;
        for (int i = sequence.first; i < length - 1; i++)
        {
            if (cards[i].GetNumber() == (cards[i + 1].GetNumber() + 1)) //if numbers of adjacent cards are consecutive...
            {
                counter++;                                                 //increment counter
            }
            if (cards[i].IsOwn())       //if player has his cards in this sequence
            {
                isThereOwnCard++;       //increment corresponding indicator
            }
        }

        if (counter >= sequnceLength && isThereOwnCard > 0)     //if quantity of consecutive numbers is 4 or more and there are players cards...
        {
            return RoyalFlush;
        }
        return Nothing;
    }
    return Nothing;
}

//any five consecutive cards of the same suit
int CombinationIdentifier::DetectStraightFlush()
{
    int counter = 0;
    int isThereOwnCard = 0;
    int sequnceLength = 4;
    int necessaryLength = 5;

    auto sequence = FindLongestSequenceOfSuit();

    if (sequence.second >= necessaryLength)         //if sequence of cards of the same suit is longer than or equal to five cards...
    {
        SortCardsByNumber(sequence.first, sequence.second);
        int length = sequence.first + sequence.second;
        for (int i = sequence.first; i < length - 1; i++)
        {
            if (cards[i].GetNumber() == (cards[i + 1].GetNumber() + 1))   ////if numbers of adjacent cards are consecutive...
            {
                counter++;
            }
            if (cards[i].IsOwn() || cards[i + 1].IsOwn())       //if player has his cards in this sequence
            {
                isThereOwnCard++;
            }
        }

        if (counter >= sequnceLength && isThereOwnCard > 0)//if quantity of consecutive numberls is 4 or more and there are players cards...
        {
            return StraightFlush + cards[sequence.first].GetNumber();
        }
        return Nothing;
    }
    return Nothing;
}

//Any four cards of the same rank
int CombinationIdentifier::DetectFourOfAKind()
{
    auto sequence = FindLongestSequenceOfSameNumbers();
    int length = sequence.first + sequence.second;
    if (sequence.second == 4)           //if there is 4 cards of the same rank...
    {
        for (int i = sequence.first; i < length; i++)
        {
            if (cards[i].IsOwn())       //...and own among them...
            {
                return FourOfAKind + cards[i].GetNumber();
            }
        }
    }

    return Nothing;
}

//Any three cards of the same rank together with any two cards of the same rank
int CombinationIdentifier::DetectFullHouse()
{
    int combinationForce = 0;
    int threeCardsDetector = 3;
    int twoCardsDetector = 2;
    int threeCounter = 0;
    int twoCounter = 0;

    EnableArrNumbers();

    for (int i = 0; i < NUMBERS_QUANTITY; i++)
    {
        if (arrNumbers[i] == threeCardsDetector)    //if there are three cards of the same rank...
        {
            combinationForce = i;
            threeCounter++;
        }
        else if (arrNumbers[i] == twoCardsDetector) //and two cards of the same rank, but not among presceding three
        {
            twoCounter++;
        }
    }

    if (threeCounter > 0 && twoCounter > 0)
    {
        for (int i = 0; i < NUMBERS_QUANTITY; i++)
        {
        //if there is own card among three cards of the same rank or among two cards of the same rank
            if ((arrNumbers[i] == threeCardsDetector &&
                std::find_if(cards.cbegin(), cards.cend(), [&i](const Card& card) {return card.GetNumber() == i && card.IsOwn(); }) != cards.cend()) ||
                (arrNumbers[i] == twoCardsDetector &&
                std::find_if(cards.cbegin(), cards.cend(), [&i](const Card& card) {return card.GetNumber() == i && card.IsOwn(); }) != cards.cend()))
            {
                return FullHouse + combinationForce;
            }
        }
    }

    return Nothing;
}

//Any five cards of the same suit (not consecutive)
int CombinationIdentifier::DetectFlush()
{
    int necessaryLength = 5;

    auto sequence = FindLongestSequenceOfSuit();

    if (sequence.second >= necessaryLength) //if there is sequence of cards of the same suit and its length more than or equal to 5
    {
        SortCardsByNumber(sequence.first, sequence.second);
        int length = sequence.first + sequence.second;
        for (int i = 0; i < length; i++)
        {
            if (cards[i].IsOwn())           //if there is players card in this sequence
            {
                return Flush + cards[sequence.first].GetNumber();
            }
        }
    }
    return Nothing;
}

//Any five consecutive cards of different suits. Aces can count as either a high or a low card
int CombinationIdentifier::DetectStraight()
{
    int aceNumber = 12;
    int necessaryLength = 5;
    int possibleLength = 4;

    auto sequence = FindLongestSequenceOfConsecutiveNumbers();
    int length = sequence.first + sequence.second;

//if length of equence of consecutive numbers is more than or equal to five
//or length of equence of consecutive numbers is more than or equal to four and the highest card in vector<Card> cards is Ace and that Ace is not in sequence
    if ((sequence.second >= necessaryLength) || (sequence.second >= possibleLength && cards[0].GetNumber() == aceNumber && sequence.first != 0))
    {
        for (int i = sequence.first; i < length; i++)
        {
            if (cards[i].IsOwn())   //find players cards in sequence
            {
                return Straight + cards[sequence.first].GetNumber();
            }
        }
    }
 //if length of equence of consecutive numbers is more than or equal to four and the highest card in vector<Card> cards is Ace and that Ace belongs to player and that Ace is not in sequence
    if (sequence.second >= possibleLength && cards[0].GetNumber() == aceNumber && cards[0].IsOwn() && sequence.first != 0)
    {
        return Straight + cards[sequence.first].GetNumber();
    }

    return Nothing;
}

//Any three cards of the same rank
int CombinationIdentifier::DetectThreeOfAKind()
{
    int threeCardsDetector = 3;
    EnableArrNumbers();

    for (int i = 0; i < NUMBERS_QUANTITY; i++)
    {
    //if there are three cards of the same rank in vector<Card> cards and there is players card among them
        if (arrNumbers[i] == threeCardsDetector &&
        std::find_if(cards.cbegin(), cards.cend(), [&i](const Card& card) {return card.IsOwn() && card.GetNumber() == i; }) != cards.cend())
        {
            return ThreeOfAKind + i;
        }
    }

    return Nothing;
}

//Any two cards of the same rank together with another two cards of the same rank
int CombinationIdentifier::DetectTwoPairs()
{
    int combinationForce = 0;
    int counter = 0;
    int twoCardsDetector = 2;

    EnableArrNumbers();

    for (int i = 0; i < NUMBERS_QUANTITY; i++)
    {
        if (arrNumbers[i] == twoCardsDetector) //how many pairs of cards of the same rank we hawe in vector<Card> cards
        {
            counter++;
            combinationForce = i;
        }
    }

    if (counter >= 2)   //we have at least two pairs
    {
        for (int i = 0; i < NUMBERS_QUANTITY; i++)
        {
        //if there is own card among that pairs
            if (arrNumbers[i] == 2 &&
            std::find_if(cards.cbegin(), cards.cend(), [&i](const Card& card) {return card.IsOwn() && card.GetNumber() == i; }) != cards.cend())
            {
                return Two_Pairs + combinationForce;
            }
        }
    }

    return Nothing;
}

//Any two cards of the same rank
int CombinationIdentifier::DetectPair()
{
    int twoCardsDetector = 2;

    EnableArrNumbers();

    for (int i = 0; i < NUMBERS_QUANTITY; i++)
    {
    //if there is two cards of the same rank in vector<Card> cards and one of them belong to player
        if (arrNumbers[i] == twoCardsDetector &&
        std::find_if(cards.cbegin(), cards.cend(), [&i](const Card& card) {return card.IsOwn() && card.GetNumber() == i; }) != cards.cend())
        {
            return Pair + i;
        }
    }

    return Nothing;
}

int CombinationIdentifier::DetectCombination()
{
    int combinationStrength = -1;
    for (int i = 0; i < COMBINATIONS_QUANTITY; i++)
    {
        combinationStrength = detectCombination[i]();
        if (combinationStrength > 0)
        {
            return combinationStrength;
        }
    }

    return Nothing;
}
