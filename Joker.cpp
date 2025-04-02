#include "Joker.h"

Joker::Joker() {
    this->type = Type::no_type;
    this->rarity = Rarity::no_rarity;
    isAvailable = true;
}
Joker::Joker (Type type, Rarity rarity) {
    this->type = type;
    this->rarity = rarity;  
    isAvailable = true;
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
        case k_hand_mult:
            name += "Baron";
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
            name += "Does absolutely nothing (for now)";
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