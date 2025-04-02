#ifndef SHOPITEM_H
#define SHOPITEM_H
#include "Joker.h"
#include "Card.h"
#include <string>
#include <sstream>

class ShopItem {
    public:
        enum itemType { none, joker, tarot, };

        ShopItem();

        int getPrice();
        void setPrice();

        itemType getItemType();
        void setItemType(itemType type);

        Joker getJoker();
        void setJoker(Joker& joker);

        string displayItem();



    private:
        itemType type;
        Joker shopJoker;
        int price;        

};



#endif