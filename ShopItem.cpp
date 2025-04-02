#include "ShopItem.h"

ShopItem::ShopItem() {
    this->type = none;
    this->price = 0;
}

int ShopItem::getPrice() {
    return price;
}
void ShopItem::setPrice() {
    if (type == itemType::joker) {
        switch(shopJoker.getRarity()) {
            case Joker::common:
                this->price = 2;
                break;
            case Joker::uncommon:
                this->price = 4;
                break;
            case Joker::rare:
                this->price = 7;
                break;
            case Joker::special:
                this->price = 15;
                break;
            default:
                this->price = -1;
                break;
        }
    }
}

ShopItem::itemType ShopItem::getItemType() {
    return type;
}
void ShopItem::setItemType(itemType type) {
    this->type = type;
}

Joker ShopItem::getJoker() {
    return shopJoker;
}
void ShopItem::setJoker(Joker& joker) {
    this->type = itemType::joker;
    this->shopJoker = joker;
    setPrice();
}

string ShopItem::displayItem() {
    ostringstream str;

    if (this->type == itemType::joker) {
        str << shopJoker.getJokerName() << " - $" << price << " - " << shopJoker.getDescription();       
    }

    return str.str();
}