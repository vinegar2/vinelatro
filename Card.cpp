#include "Card.h"
using namespace std;

//  Constructors
Card::Card() {}

int Card::nextId = 1;

Card::Card(int rank, Suit suit) {
    this->rank = rank;
    this->suit = suit;
    id = nextId;
    ++nextId;
    
    if (rank == 1) {
        title = "Ace";
        value = 11;
    } else if (rank > 1 && rank < 11) {
        title = to_string(rank);
        value = rank;
    } else if (rank == 11) {
        title = "Jack";
        value = 11;
    } else if (rank == 12) {
        title = "Queen";
        value = 11;
    } else if (rank == 13) {
        title = "King";
        value = 11;
    }
}

Card::Card(const Card& original) {
    this->rank = original.rank;
    this->suit = original.suit;
    this->id = original.id;
    this->value = original.value;
    this->toBeSwapped = original.toBeSwapped;
    this->mult = original.mult;
    this->enabled = original.enabled;
    this->tag = original.tag;
    this->bonus = original.bonus;

    if (rank == 1) {
        title = "Ace";
        value = 11;
    } else if (rank > 1 && rank < 11) {
        title = to_string(rank);
        value = rank;
    } else if (rank == 11) {
        title = "Jack";
        value = 11;
    } else if (rank == 12) {
        title = "Queen";
        value = 11;
    } else if (rank == 13) {
        title = "King";
        value = 11;
    }
}

string Card::strCard() {
    ostringstream output;
    output << title << " of ";
    switch(suit) {
        case club:
            output << "Clubs";
            break;
        case heart:
            output << "Hearts";
            break;
        case spade:
            output << "Spades";
            break;
        case diamond:
            output << "Diamonds";
            break;
        default:
            output << "Something";
    }

    
    if (bonus > 0) {
        output << " + " << bonus;
    }

    switch(tag) {
        case red:
            output << " (r)";
            break;
        default:
            break;
    }
    
    return output.str();
}

bool Card::operator< (const Card& rhs) {

    int rankEff = this->rank, rhsEff = rhs.rank;

    if (rankEff == 1) {
        rankEff = 14;
    }
    if (rhsEff == 1) {
        rhsEff = 14;
    }

    if (rankEff < rhsEff) {
        return true;
    } else {
        return false;
    }
}

bool Card::operator== (const Card& rhs) {
    if (this->rank == rhs.rank && this->suit == rhs.suit && this->value == rhs.value && this->id == rhs.id) {
        return true;
    } else {
        return false;
    }
}

bool Card::operator!= (const Card& rhs) {
    return !(*this == rhs);
}

int Card::getRank() {
    return rank;
}

Card::Suit Card::getSuit() {
    return suit;
}

int Card::getValue() {
    return value + bonus;
}

string Card::getTitle() {
    return title;
}

int Card::getID() {
    return id;
}

bool Card::isOdd() {
    if (rank % 2 == 1 && rank < 11) {
        return true;
    } else {
        return false;
    }
}

bool Card::isEven() {
    if (!isOdd() && rank < 11) {
        return true;
    } else {
        return false;
    }
}

int Card::getMult() {
    return mult;
}

void Card::addMult(int i) {
    mult += i;
}

void Card::disable() {
    enabled = false;
}
void Card::enable() {
    enabled = true;
}
bool Card::isEnabled() {
    return enabled;
}

void Card::setRank(int i) {
    this->rank = i;
    rankValue(i);
}

void Card::readyToSwap() {
    toBeSwapped = true;
}
void Card::swapped() {
    toBeSwapped = false;
}

Card::Tag Card::getTag() {
    return tag;
}

void Card::setTag(Card::Tag tag) {
    this->tag = tag;
}

void Card::rankValue(int i) {
    if (i > 1 && i < 11) {
        value = i;
    } else {
        value = 11;
    }
}

void Card::addBonus(int i) {
    bonus += i;
}