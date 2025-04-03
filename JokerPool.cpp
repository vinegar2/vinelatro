#include "JokerPool.h"
#include <iostream>
using namespace std;

JokerPool::JokerPool() {
    Joker tempJoker;

    for (int i = static_cast<int>(Joker::splash); i < static_cast<int>(Joker::FINAL); i++) {
        tempJoker.intType(i);
        if (tempJoker.getType() < Joker::oops_all_face) {
            tempJoker.intRarity(1);
        } else if (tempJoker.getType() < Joker::k_hand_mult) {
            tempJoker.intRarity(2);
        } else if (tempJoker.getType() < Joker::kq_mult) {
            tempJoker.intRarity(3);
        } else {
            tempJoker.intRarity(4);
        }
        pool.push_back(tempJoker);
    }
}

Joker JokerPool::drawJoker() {
    random_device rando;
    Joker tempJoker;
    int r = (rando() % (int)pool.size());

    if (isEmpty()) {
        Joker nullJoker(Joker::no_type, Joker::no_rarity);
        return nullJoker;
    }

    while (pool.at(r).isAvailable == false) {
        r = (rando() % (int)pool.size());
    }

    if (pool.at(r).getRarity() == Joker::common) {
        tempJoker = pool.at(r);
        pool.at(r).unavailable();
    }

    if (pool.at(r).getRarity() == Joker::uncommon) {
        if (rando() % 4 == 1) {
            tempJoker = pool.at(r);
            pool.at(r).unavailable();
        } else {
            tempJoker = drawJoker();
        }
    }

    if (pool.at(r).getRarity() == Joker::rare) {
        if (rando() % 10 == 1) {
            tempJoker = pool.at(r);
            pool.at(r).unavailable();
        } else {
            tempJoker = drawJoker();
        }
    }

    if (pool.at(r).getRarity() == Joker::special) {
        if (rando() % 25 == 1) {
            tempJoker = pool.at(r);
            pool.at(r).unavailable();
        } else {
            tempJoker = drawJoker();
        }
    }

    return tempJoker;
}

void JokerPool::returnJoker(Joker& joker) {
    for (int i = 0; i < (int)pool.size(); i++) {
        if (joker == pool.at(i)) {
            pool.at(i).available();
        }
    }
}

bool JokerPool::isEmpty() {
    for (int i = 0; i < (int)pool.size(); i++) {
        if (pool.at(i).isAvailable) {
            return false;
        }
    }
    return true;
}