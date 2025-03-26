#ifndef DECK_H_
#define DECK_H_

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>
#include "Card.h"
using namespace std;

class Deck
{
    private:
        vector<Card> deck;
        static int funnySeedIncrementorInator;

    public: 
        Deck();
        void shuffle();
        Card drawCard();
        int getDeckSize();
        void addCard(Card card);

};
  

#endif // DECK_H_
