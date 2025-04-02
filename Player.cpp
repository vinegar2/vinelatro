#include "Player.h"

void Player::clearHand() {
    currentHand.empty();
}

void Player::setHand(Deck& deck, int N) {
    currentHand.fillHand(deck, N);
    orderHand();
}

void Player::orderHand() {
    currentHand.order();
}

string Player::getStr() {
    return currentHand.strHand();
}

void Player::updateScore(float score) {
    this->score += score;
}

void Player::resetScore() {
    score = 0;
}

void Player::giveMuns(int munsToGive) {
    muns += munsToGive;
}

void Player::takeMuns(int munsToTake) {
    muns -= munsToTake;
}

void Player::addJoker(Joker& joker) {
    if (!hasJoker(joker) && (int)jokers.size() < jokerCap) {
        jokers.push_back(joker);
    }
}
bool Player::hasJoker(Joker& joker) {
    for (int i = 0; i < (int)jokers.size(); i++) {
        if (jokers.at(i) == joker) {
            return true;
        }
    }
    return false;
}