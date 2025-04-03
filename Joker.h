#ifndef JOKER_H
#define JOKER_H
#include <string>
using namespace std;

class Joker {
    public: 
        enum Type { 
            no_type,
            splash, // First common
            jimbo,
            odd_score,
            even_mult,
            face_mult, 
            face_score,
            no_discard_mult,
            money_chips,
            club_mult,
            heart_mult,
            spade_mult,
            diamond_mult,
            random_mult,
            oops_all_face, // First uncommon
            hack,
            no_e_bonus,
            fibonacci,
            perma_score,
            k_hand_mult, // First rare
            jack_to_queen,
            uncommon_xmult,
            kq_mult, // First special
            FINAL   // Final joker type = do not create!
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

        int getValue();
        void setValue();

    private:
        Type type;    
        Rarity rarity;
        int value = -1;

};



#endif