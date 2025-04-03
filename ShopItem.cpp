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
        this->price = shopJoker.getValue();
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