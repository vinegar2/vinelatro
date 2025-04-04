#include "Hand.h"
using namespace std;

Hand::Hand() {
//  Ensuring it's empty
    hand.clear();
    jokers.clear();
}

Hand::Hand(Deck& deck, int N) {
//  Using reference to make sure the cards drawn are banished from the real deck, never to be seen (nor drawn) again
    fillHand(deck, N);
}

void Hand::fillHand(Deck& deck, int N) {
    while ((int)hand.size() < N) {
        if (deck.getDeckSize() != 0) {
            hand.push_back(deck.drawCard());
        } else {
            break;
        }
    }
}

void Hand::addCard(Card& card) {
    hand.push_back(card);
}

string Hand::strHand() {
    ostringstream output;

//  A simple for loop to show what number the card is and the info
    for (int i = 0; i < (int)hand.size(); i++) {
        output << "[" << i + 1 << "] " << hand.at(i).strCard() << " ";
//  I want there to only be 5 cards per line: makes it easier to read!
        if ((i + 1) % 5 == 0) {
            output << "\n";
        }
    }

    return output.str();
}

Card Hand::dealCard(int num) {
    num -= 1;
//  Making a temporary copy of the card so I can delete it from the hand
    Card tempCard = hand.at(num);
    hand.erase(hand.begin() + num);
    return tempCard;
}

void Hand::returnCards(Hand& handToCopy) {
    while (handToCopy.getHandSize() != 0) {
        this->addCard(handToCopy.hand.back());
        handToCopy.hand.pop_back();
        this->order();
    }
}

int Hand::getHandSize() {
    return hand.size();
}

void Hand::empty() {
    hand.clear();
}

void Hand::order() {
    sort(hand.begin(), hand.end());
}

void Hand::addJokers(vector<Joker>& jokers) {
    this->jokers.clear();
    for (int i = 0; i < (int)jokers.size(); i++) {
        this->jokers.push_back(jokers.at(i));
    }
}
bool Hand::hasJoker(Joker::Type type) {
    bool hasJoker = false;
    for (int i = 0; i < (int)jokers.size(); i++) {
        if (jokers.at(i).getType() == type) {
            hasJoker = true;
        }
    }
    return hasJoker;
}

bool Hand::hasPair() {

    for (int i = 0; i < (int)hand.size(); i++) {

        for (int j = i + 1; j < (int)hand.size(); j++) {
            if (hand.at(i).getRank() == hand.at(j).getRank()) {
                return true;
            }
        }
        
    }

    return false;
}

bool Hand::isPair(Card& c1, Card& c2) {
    if (c1.getRank() == c2.getRank()) {
        return true;
    } else {
        return false;
    }
}

bool Hand::isFlush() {
    if (hand.size() != 5) {
        return false;
    } else {
        for (int i = 0; i < (int)hand.size(); i++) {
            if (hand.at(0).getSuit() != hand.at(i).getSuit()) {
                return false;
            }
        }
        return true;
    }
}

bool Hand::isStraight() {
    bool good = true;
    if (hand.size() != 5) {
        return false;
    } else {
//  Ensuring no repeats
        if (hasPair()) {
            return false;
        } else {
//  Low Ace Case
            if ((hand.back().getRank() == 1) && (hand.front().getRank() == 2)) {
                Card tempCard = hand.at(4);
                hand.insert(hand.begin(), tempCard);
                hand.pop_back();
                return (isStraight());
            }
            for (int i = 0; i < (int)hand.size() - 1; i++) {
                if (hand.at(i).getRank() != hand.at(i + 1).getRank() - 1) {
//  Handles High Aces
                    if (i == 3 && hand.at(i + 1).getRank() == 1) {
                        if (hand.at(i).getRank() == 13) {
                            order();
                            break;
                        }
                    }
                    order();
                    good = false;
                }
            }
        }
        order();
        return good;
    }
}

bool Hand::isPartOfThree(Card& card) {
    if ((int)hand.size() < 3) {
        return false;
    } else {
        int pairs = 0;
        for (int i = 0; i < (int)hand.size(); i++) {
            if (isPair(hand.at(i), card)) {
                pairs += 1;
            }
        }
        if (pairs >= 3) {
            return true;
        } else {
            return false;
        }
    }
}

bool Hand::isPartOfFour(Card& card) {
    if ((int)hand.size() < 4) {
        return false;
    } else {
        int pairs = 0;
        for (int i = 0; i < (int)hand.size(); i++) {
            if (isPair(hand.at(i), card)) {
                pairs += 1;
            }
        }
        if (pairs >= 4) {
            return true;
        } else {
            return false;
        }
    }
}

bool Hand::isFace(Card& card) {
    if (hasJoker(Joker::oops_all_face)) {
        return true;
    } else if (card.getRank() >= 11 && card.getRank() <= 13) {
        return true;
    } else {
        return false;
    }
}

Hand::HandType Hand::getHandType() {
    order();

//  Straight flush
    if (hand.size() == 5) {
        if (isFlush() && isStraight()) {
            return straight_flush;
        }
    }

//  Four of a kind
    if (hand.size() >= 4) {

        for (int i = 0; i < (int)hand.size(); i++) {
            int same = 0;

            for (int j = 0; j < (int)hand.size(); j++) {
                if (hand.at(j).getRank() == hand.at(i).getRank()) {
                    same += 1;
                }
            }

            if (same == 4) {
                return four;
            }
        }

    }

//  Full house
    
    if (hand.size() == 5) {

//  It'll be sorted, so if the outer 2 cards are pairs, then we just check to see if the inner one is pairs with someone too
        if (isPair(hand.at(0), hand.at(1)) && isPair(hand.at(3), hand.at(4))) {
            if (isPair(hand.at(0), hand.at(2)) || isPair(hand.at(2), hand.at(4))) {
                return full_house;
            }
        }
        

    }

//  Flush

    if (hand.size() == 5) {
        if (isFlush()) {
            return flush;
        }
    }

//  Straight

    if (hand.size() == 5) {

        if (isStraight()) {
            return straight;
        }

    }

//  Three of a Kind (strictly)

    if (hand.size() >= 3) {
        if (hasPair()) {

            for (int i = 0; i < (int)hand.size() - 2; i++) {
                if (isPair(hand.at(i), hand.at(i + 1))) {
                    if (isPair(hand.at(i), hand.at(i + 2))) {
                        return three;
                    }
                }
            }

        }
    }

//  Two pair

    if (hand.size() >= 4) {
        if (hasPair()) {

            Hand tempHand = *this;

            for (int i = 0; i < (int)tempHand.hand.size(); i++) {
                bool willBeKilled = true;
                for (int j = 0; j < (int)tempHand.hand.size(); j++) {
                    if (i != j) {
                        if (isPair(tempHand.hand.at(i), tempHand.hand.at(j))) {
                            willBeKilled = false;
                        }
                    }
                }
                if (willBeKilled) {
                    tempHand.hand.erase(tempHand.hand.begin() + i);
                }
            }
            if (tempHand.hand.size() == 4) {
                if (isPair(tempHand.hand.at(0), tempHand.hand.at(1)) && isPair(tempHand.hand.at(2), tempHand.hand.at(3))) {
                    return two_pair;
                }
            }

        }
    }

//  Pair (strictly)

    if (hand.size() >= 2) {
        if (hasPair()) {
            return pair;
        }
    }

//  High card

    if (hand.size() >= 1) {
        return high;
    }

    return nothing;
}

float Hand::calculateHandScore(bool& modified, int& money, int discards, int handsRemaining, Hand& remainingHand) {
    int score = 0;
    float mult = 0;

//  If you have splash, then the parts that erase cards are ignored
    bool ignore = hasJoker(Joker::splash);

    switch (getHandType()) {
        case straight_flush:
            score += 100;
            mult += 8;
            break;
        case four:
            score += 60;
            mult += 7;
            if (!ignore) {
                if ((int)hand.size() > 4) {
                    for (int i = 0; i < (int)hand.size(); i++) {
                        if (!isPartOfFour(hand.at(i))) {
                            hand.at(i).disable();
                        }
                    }
                }
            }
            break;
        case full_house:
            score += 40;
            mult += 4;
            break;
        case flush:
            score += 35;
            mult += 4;
            break;
        case straight:
            score += 30;
            mult += 4;
            break;
        case three:
            score += 30;
            mult += 3;
            if (!ignore) {
                if ((int)hand.size() > 3) {
                    for (int i = 0; i < (int)hand.size(); i++) {
                        if (!isPartOfThree(hand.at(i))) {
                            hand.at(i).disable();
                        }
                    }
                }
            }
            break;
        case two_pair:
            score += 20;
            mult += 2;
            if (!ignore) {
                if ((int)hand.size() > 4) {
                    for (int i = 0; i < (int)hand.size(); i++) {
                        bool toDisable = true;
                        for (int j = 0; j < (int)hand.size(); j++) {
                            if (i != j) {
                                if (isPair(hand.at(i), hand.at(j))) {
                                    toDisable = false;
                                }
                            }
                        }
                        if (toDisable) {
                            hand.at(i).disable();
                        }
                    }
                }
            }
            break;
        case pair:
            score += 10;
            mult += 2;
            if (!ignore) {
                if ((int)hand.size() > 2) {
                    for (int i = 0; i < (int)hand.size(); i++) {
                        bool toDisable = true;
                        for (int j = 0; j < (int)hand.size(); j++) {
                            if (i != j) {
                                if (isPair(hand.at(i), hand.at(j))) {
                                    toDisable = false;
                                }
                            }
                        }
                        if (toDisable) {
                            hand.at(i).disable();
                        }
                    }
                }
            }
            break;
        case high:
            score += 5;
            mult += 1;
            if (!ignore) {
                for (int i = 0; i < (int)hand.size() - 1; i++) {
                    hand.at(i).disable();
                }
            }
            break;
        default:
            break;
    }


    for (int i = 0; i < getHandSize(); i++) {
        if (hand.at(i).isEnabled()) {
            score += hand.at(i).getValue();
            score += calcExtraScore(i);
            mult += calcExtraMult(i);
            mult *= calcMultMult(i);
            playHandModify(i, modified);

            extraPlays(i, score, mult, modified);

            hand.at(i).enable();
        }
    }
    additionalScore(score, money);
    additionalMult(mult, discards);
    additionalMultMult(mult, remainingHand);


    return (float)score * mult;
}

void Hand::additionalScore(int& score, int& money) {

    if (hasJoker(Joker::money_chips)) {
        score += 2 * money;
    }

}

void Hand::additionalMult(float& mult, int& discards) {

    if (hasJoker(Joker::no_discard_mult)) {
        if (discards == 0) {
            mult += 15;
        }
    }
    if (hasJoker(Joker::random_mult)) {
        random_device randall;
        mult += (randall() % 24);
    }

}

void Hand::additionalMultMult(float& mult, Hand& remainingHand) {

    if (hasJoker(Joker::uncommon_xmult)) {
        for (int i = 0; i < (int)jokers.size(); i++) {
            if (jokers.at(i).getRarity() == Joker::uncommon) {
                mult *= 1.5;
            }
        }
    }

    if (hasJoker(Joker::k_hand_mult)) {
        for (int i = 0; i < remainingHand.getHandSize(); i++) {
            if (remainingHand.hand.at(i).getRank() == 13) {
                mult *= 1.5;
            }
        }        
    }

}

void Hand::extraPlays(int CardNo, int& score, float& mult, bool& modified) {
    if (hand.at(CardNo).isEnabled()) {
        int j = 0;
        if (hand.at(CardNo).getTag() == Card::red) {
            j += 1;
        }
        if (hasJoker(Joker::no_e_bonus)) {
            int l = hand.at(CardNo).getRank();  // I'mma be so fr this is just to save me time having to type that shit out
            if ((l == 2 || l == 4 || l == 6 || l == 11 || l == 13) && (hand.at(CardNo).getSuit() != Card::spade && hand.at(CardNo).getSuit() != Card::heart)) {
                j += 2;
            }
        }
        if (hasJoker(Joker::hack)) {
            if (hand.at(CardNo).getRank() >= 2 && hand.at(CardNo).getRank() <= 5) {
                j += 1;
            }
        }


        for (int i = 0; i < j; i++) {
            score += hand.at(CardNo).getValue();
            score += calcExtraScore(CardNo);
            mult += calcExtraMult(CardNo);
            mult *= calcMultMult(CardNo);
            playHandModify(CardNo, modified);
        }

    }
}

int Hand::calcExtraScore(int i) {
    int bonusScore = 0;

    if (hasJoker(Joker::odd_score)) {
        if (hand.at(i).isOdd()) {
            bonusScore += 31;
        }
    }


    return bonusScore;
}

int Hand::calcExtraMult(int i) {
    int bonusMult = 0;

    if (hasJoker(Joker::even_mult)) {
        if (hand.at(i).isEven()) {
            bonusMult += 4;
        }
    }
    if (hasJoker(Joker::face_mult)) {
        if (isFace(hand.at(i))) {
            bonusMult += 5;
        }
    }
    if (hasJoker(Joker::fibonacci)) {
        int j = hand.at(i).getRank();
        if (j == 1 || j == 2 || j == 3 || j == 5 || j == 8) {
            bonusMult += 8;
        }
    }
    if (hasJoker(Joker::club_mult)) {
        if (hand.at(i).getSuit() == Card::club) {
            bonusMult += 3;
        }
    }
    if (hasJoker(Joker::heart_mult)) {
        if (hand.at(i).getSuit() == Card::heart) {
            bonusMult += 3;
        }
    }
    if (hasJoker(Joker::spade_mult)) {
        if (hand.at(i).getSuit() == Card::spade) {
            bonusMult += 3;
        }
    }
    if (hasJoker(Joker::diamond_mult)) {
        if (hand.at(i).getSuit() == Card::diamond) {
            bonusMult += 3;
        }
    }


    return bonusMult;
}

float Hand::calcMultMult(int i) {
    int multMult = 0;

    if (hasJoker(Joker::kq_mult)) {
        if (hand.at(i).getRank() == 12 || hand.at(i).getRank() == 13) {
            multMult += 2;
        }
    }

    if (multMult == 0) {
        multMult += 1;
    }
    return multMult;
}

void Hand::playHandModify(int i, bool& modified) {
    if (hand.at(i).isEnabled()) {
//  Forcefemming Jacks
        if (hasJoker(Joker::jack_to_queen)) {
            if (hand.at(i).getRank() != 12 && isFace(hand.at(i))) {
                if (hand.at(i).getTag() != Card::red) { // Handling edge case for if the card already has a red tag
                    hand.at(i).disable();
                }
                hand.at(i).setRank(12);
                hand.at(i).setTag(Card::red);
                hand.at(i).readyToSwap();
                modified = true;
            }
        }
//  Hiker (I buffed him btw because I LOVE HIKER WOOOOO)
        if (hasJoker(Joker::perma_score)) {
            hand.at(i).addBonus(10);
        }

    }
}

bool Hand::swapping(int i) {
    if (hand.at(i).toBeSwapped) {
        return true;
    } else {
        return false;
    }
}

Card Hand::getCard(int i) {
    return hand.at(i);
}