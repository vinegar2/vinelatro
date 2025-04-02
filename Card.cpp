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

string Card::strCard() {
    ostringstream output;
    output << title << " of ";
    if (suit == club) {
        output << "Clubs";
    } else if (suit == heart) {
        output << "Hearts";
    } else if (suit == spade) {
        output << "Spades";
    } else if (suit == diamond) {
        output << "Diamonds";
    } else {
        output << "Something";
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
    return value;
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