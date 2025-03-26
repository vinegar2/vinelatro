#ifndef HAND_H_
#define HAND_H_

#include <vector>
#include <string>
#include <sstream>
#include "Deck.h"
using namespace std;

class Hand
{
    private:
        vector<Card> hand;

    public:
        Hand();
        Hand(Deck& deck, int N);
        string strHand();
        Card dealCard(int num);
        int getHandSize();

        void empty();
        void fillHand(Deck& deck, int N);
        void addCard(Card& card);
        void returnCards(Hand& handToCopy);

        void order();

        bool hasPair();
        bool isPair(Card& c1, Card& c2);

        bool isFlush();
        bool isStraight();

        int calculateHandScore();



        enum HandType { straight_flush, four, full_house, flush, straight, three, two_pair, pair, high, nothing };
        HandType getHandType();

};

#endif // HAND_H_
