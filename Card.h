#ifndef CARD_H_
#define CARD_H_

#include <string>
#include <sstream>
using namespace std;

class Card
{
    public: 
        enum Suit {club, heart, spade, diamond, MYSTERY};
        enum Tag {none, red };

        Card();
        Card(int rank, Suit suit);
        Card(const Card& original);

        string strCard();

        int getRank();
        Suit getSuit();
        int getValue();
        string getTitle();
        int getID();

        void setRank(int i);
        
        bool operator< (const Card& rhs);
        bool operator== (const Card& rhs);
        bool operator!= (const Card& rhs);

        bool isOdd();
        bool isEven();

        int getMult();

        void addMult(int i);

        void disable();
        void enable();
        bool isEnabled();

        
        bool toBeSwapped = false;
        void readyToSwap();
        void swapped();

        Tag getTag();
        void setTag(Tag tag);

        void rankValue(int i);
        void addBonus(int i);

        




        static int nextId;

    private: 
        string title = "";
        int rank = 0;
        Suit suit = club;
        int value = 0;
        int bonus = 0;
        int mult = 0;
        int id = 0;
        bool enabled = true;
        Tag tag = none;

};
  

#endif // CARD_H_
