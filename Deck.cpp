#include "Deck.h"
using namespace std;


Deck::Deck() {
    for (int i = 1; i <= 13; i++) {
        Card tempCard(i, Card::club);
        deck.push_back(tempCard);
    }
    for (int i = 1; i <= 13; i++) {
        Card tempCard(i, Card::heart);
        deck.push_back(tempCard);
    }
    for (int i = 1; i <= 13; i++) {
        Card tempCard(i, Card::spade);
        deck.push_back(tempCard);
    }
    for (int i = 1; i <= 13; i++) {
        Card tempCard(i, Card::diamond);
        deck.push_back(tempCard);
    }
}

int Deck::funnySeedIncrementorInator = 0;

void Deck::shuffle() {
    unsigned seed = (unsigned)time(NULL);
//  Have to use std::shuffle since the member function is already called shuffle. Still shuffles them all the same.
    std::shuffle(deck.begin(), deck.end(), default_random_engine(seed + funnySeedIncrementorInator));
    ++funnySeedIncrementorInator;
}


Card Deck::drawCard() {
//  Making a temporary copy so I can delete it from the deck.
    Card tempCard = deck.front();
    deck.erase(deck.begin());
    return tempCard;
}

int Deck::getDeckSize() {
    return deck.size();
}

void Deck::addCard(Card card) {
    deck.push_back(card);
}