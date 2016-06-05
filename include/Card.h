#ifndef CARD_H
#define CARD_H

#include <stdexcept>

class Card
{
    public:
        Card();
        Card(const Card& other);
        Card(int inputSuit, int inputNumber);
        virtual ~Card();

        Card& operator= (const Card& other);

        int GetSuit() const;
        void SetSuit(int value);

        int GetNumber() const;
        void SetNumber(int value);

        bool IsOwn() const;
        void IsOwn(bool inputIsOwn);

    private:
        const int MIN_NUMBER = 0;
        const int MAX_NUMBER = 12;
        const int MIN_SUIT = 0;
        const int MAX_SUIT = 3;

        int suit;
        int number;

//determines which cards are on the table and which was given in players hands
//(true - in players hands, false - on the table)
        bool isOwn;
};

#endif // CARD_H
