#include "Joker.h"

Joker::Joker() {
    this->type = Type::no_type;
    this->rarity = Rarity::no_rarity;
    isAvailable = true;
}
Joker::Joker (Type type, Rarity rarity) {
    this->type = type;
    this->rarity = rarity;  
    setValue();
    isAvailable = true;
}

void Joker::setValue() {
//  Painting in broad strokes at first...
    switch(rarity) {
        case common:
            value = 4;
            break;
        case uncommon:
            value = 7;
            break;
        case rare:
            value = 8;
            break;
        case special:
            value = 15;
            break;
        default:
            value = -1;
            break;
    }
//  Before refining it
    switch(type) {
        case jimbo:
            value = 2;
            break;
        case splash:
            value = 3;
            break;
        case oops_all_face:
            value = 5;
            break;
        case perma_score:
            value = 5;
            break;
        case club_mult:
            value = 5;
            break;
        case heart_mult:
            value = 5;
            break;
        case spade_mult:
            value = 5;
            break;
        case diamond_mult:
            value = 5;
            break;
        case hack:
            value = 6;
            break;        
        case fibonacci:
            value = 8;
            break;
        case no_e_bonus:
            value = 8;
            break;
        case no_discard_mult:
            value = 5;
            break;
        case money_chips:
            value = 6;
            break;

        default:
            break;
    }

}

int Joker::getValue() {
    setValue();
    return value;
}


void Joker::setType(Type type) {
    this->type = type;
}
void Joker::intType(int i) {
    this->type = static_cast<Type>(i);
}

void Joker::setRarity(Rarity rarity) {
    this->rarity = rarity;
}
void Joker::intRarity(int i) {
    this->rarity = static_cast<Rarity>(i);
}

void Joker::unavailable() {
    this->isAvailable = false;
}
void Joker::available() {
    this->isAvailable = true;
}


Joker::Type Joker::getType() {
    return this->type;
}
Joker::Rarity Joker::getRarity() {
    return this->rarity;
}

string Joker::getJokerName() {
    string name = "";
    switch(getType()) {
        case splash:
            name += "Splash";
            break;
        case odd_score:
            name += "Odd Todd";
            break;
        case even_mult:
            name += "Even Steven";
            break;
        case kq_mult:
            name += "Triboulet";
            break;
        case oops_all_face:
            name += "Pareidolia";
            break;
        case face_mult:
            name += "Smiley Face";
            break;
        case face_score:
            name += "Scary Face";
            break;
        case k_hand_mult:
            name += "Baron";
            break;
        case jack_to_queen:
            name += "Estrogen";
            break;
        case jimbo:
            name += "Joker";
            break;
        case hack:
            name += "Hack";
            break;
        case no_e_bonus:
            name += "Jokr";
            break;
        case fibonacci:
            name += "Fibonacci";
            break;
        case no_discard_mult:
            name += "Mystic Summit";
            break;
        case perma_score:
            name += "Hiker";
            break;
        case money_chips:
            name += "Bull";
            break;
        case uncommon_xmult:
            name += "Baseball Card";
            break;
        case club_mult:
            name += "Gluttonous Joker";
            break;
        case heart_mult:
            name += "Lusty Joker";
            break;
        case spade_mult:
            name += "Wrathful Joker";
            break;
        case diamond_mult:
            name += "Greedy Joker";
            break;
        case random_mult:
            name += "Misprint";
            break;
        case no_type:
            name += "no_type";
            break;
        default:
            break;
    }
    return name;
}
string Joker::getJokerRarity() {
    string name = "";
    switch (getRarity()) {
        case common:
            name += "Common";
            break;
        case uncommon:
            name += "Uncommon";
            break;
        case rare:
            name += "Rare";
            break;
        case special:
            name += "Special";
            break;
        case no_rarity:
            name += "no_rarity";
            break;
        default:
            break;
    }
    return name;
}
string Joker::getDescription() {
    string name = "";
    switch(getType()) {
        case splash:
            name += "Every card played counts in scoring";
            break;
        case odd_score:
            name += "Every odd-numbered card gives +31 score when scored";
            break;
        case even_mult:
            name += "Every even-numbered card gives +4 mult when scored";
            break;
        case kq_mult:
            name += "Every King or Queen gives x2 mult when scored";
            break;
        case oops_all_face:
            name += "Every card counts as a face card";
            break;
        case face_mult:
            name += "Every face card gives +5 mult when scored";
            break;
        case k_hand_mult:
            name += "Every King held in hand gives x1.5 mult";
            break;
        case jack_to_queen:
            name += "All non-Queen face cards are converted to Queens after being scored, transitioned Queens are scored twice";
            break;
        case jimbo:
            name += "+4 mult";
            break;
        case perma_score:
            name += "Cards permanently gain +10 when scored";
            break;
        case face_score:
            name += "Every face card gives +30 score when scored";
            break;
        case hack:
            name += "Retriggers every played 2 - 5";
            break;
        case no_e_bonus:
            name += "Every card without an 'e' in the name (including Suit!) scores thrice";
            break;        
        case fibonacci:
            name += "Each played Ace, 2, 3, 5, or 8 gives +8 mult when scored";
            break;
        case random_mult:
            name += "Random +mult from 0-23";
            break;
        case no_discard_mult:
            name += "+15 mult when 0 discards remaining";
            break;
        case money_chips:
            name += "+2 score for each $1 you have";
            break;
        case uncommon_xmult:
            name += "Each Uncommon Joker gives x1.5 mult";
            break;
        case club_mult:
            name += "Each played Club gives +3 mult when scored";
            break;
        case heart_mult:
            name += "Each played Heart gives +3 mult when scored";
            break;
        case spade_mult:
            name += "Each played Spade gives +3 mult when scored";
            break;
        case diamond_mult:
            name += "Each played Diamond gives +3 mult when scored";
            break;
        default:
            name += "Either I fucked something up, or you exhausted the Joker pool. Either way, you shouldn't see this message.";
            break;
    }
    return name;
}

bool Joker::operator== (const Joker& rhs) {
    if (this->type == rhs.type) {
        return true;
    } else {
        return false;
    }
}