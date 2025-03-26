#include "Player.h"

void Player::clearHand() {
    currentHand.empty();
}

void Player::setHand(Deck& deck, int N) {
    currentHand.fillHand(deck, N);
}

void Player::orderHand() {
    currentHand.order();
}

string Player::getStr() {
    return currentHand.strHand();
}