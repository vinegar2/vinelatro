#ifndef HAND_H_
#define HAND_H_

#include <vector>
#include <string>
#include <sstream>
#include "Deck.h"
#include "Joker.h"
using namespace std;

class Hand
{
    private:
        vector<Card> hand;
        vector<Joker> jokers;

    public:
        Hand();
        Hand(Deck& deck, int N);
        string strHand();
        Card dealCard(int num);
        int getHandSize();

        void empty();
        void order();

        void fillHand(Deck& deck, int N);
        void addCard(Card& card);
        void returnCards(Hand& handToCopy);
        void addJokers(vector<Joker>& jokers);


        bool hasPair();
        bool isPair(Card& c1, Card& c2);
        bool isFlush();
        bool isStraight();
        bool isPartOfThree(Card& card);
        bool isPartOfFour(Card& card);
        bool isFace(Card& card);

        float calculateHandScore();
        bool hasJoker(Joker::Type type);

        int calcExtraScore(int i);
        int calcExtraMult(int i);
        float calcMultMult(int i);

        enum HandType { straight_flush, four, full_house, flush, straight, three, two_pair, pair, high, nothing };
        HandType getHandType();

};

#endif // HAND_H_
