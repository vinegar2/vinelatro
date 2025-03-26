

#ifndef PLAYER_H_
#define PLAYER_H_
#include "Hand.h"
#include "Deck.h"
using namespace std;

class Player
{
    public:
        Hand currentHand;
        int score;
        Player() : currentHand(), score(0) {};
        void clearHand();
        void setHand(Deck& deck, int N);

        void orderHand();
        string getStr();

        void updateScore(Hand& hand);
        void resetScore();

};
  

#endif // PLAYER_H_
