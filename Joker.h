#ifndef JOKER_H
#define JOKER_H
#include <string>
using namespace std;

class Joker {
    public: 
        enum Type { 
            no_type,
            splash,
            odd_score,
            even_mult,
            face_mult,
            oops_all_face,
            k_hand_mult,
            kq_mult,
        };
        enum Rarity {
            no_rarity,
            common,
            uncommon,
            rare,
            special,
        };

        Joker(Type type, Rarity rarity);
        Joker();

        void setType(Type type);
        void setRarity(Rarity rarity);
        void intType(int i);
        void intRarity(int i);

        Type getType();
        Rarity getRarity();

        string getJokerName();
        string getJokerRarity();
        string getDescription();

        bool operator== (const Joker& rhs);
        
        bool isAvailable;
        void unavailable();
        void available();

    private:
        Type type;    
        Rarity rarity;

};



#endif