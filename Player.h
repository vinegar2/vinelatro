

#ifndef PLAYER_H_
#define PLAYER_H_
#include "Hand.h"
#include "Deck.h"
#include "Joker.h"
using namespace std;

class Player
{
    public:
        Hand currentHand;
        float score;
        int muns;
        int handSize;
        int jokerCap;
        int handsCap;
        int handsPlayed;
        int discardsCap;
        int discardsUsed;

        Player() : currentHand(), score(0), muns(0), handSize(7), jokerCap(5), handsCap(4), handsPlayed(0), discardsCap(3), discardsUsed(0) {};
        void clearHand();
        void setHand(Deck& deck, int N);

        void orderHand();
        string getStr();

        void updateScore(float score);
        void resetScore();
        void giveMuns(int munToGive);
        void takeMuns(int munToTake);

        void addJoker(Joker& joker);
        bool hasJoker(Joker& joker);
        bool hasJokerRoom();

        vector<Joker> jokers;

};
  

#endif // PLAYER_H_
