#ifndef CARD_H_
#define CARD_H_

#include <string>
#include <sstream>
using namespace std;

class Card
{
    public: 
        enum Suit {club, heart, spade, diamond, MYSTERY};

        Card();
        Card(int rank, Suit suit);

        string strCard();

        int getRank();
        Suit getSuit();
        int getValue();
        string getTitle();
        int getID();
        
        bool operator< (const Card& rhs);
        bool operator== (const Card& rhs);
        bool operator!= (const Card& rhs);

        bool isOdd();
        bool isEven();



        static int nextId;

    private: 
        string title = "";
        int rank = 0;
        Suit suit = club;
        int value = 0;
        int id = 0;

};
  

#endif // CARD_H_
