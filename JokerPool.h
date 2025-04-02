#ifndef JOKERPOOL_H
#define JOKERPOOL_H
#include "Joker.h"
#include <vector>
#include <random>
using namespace std;

class JokerPool {
    public:
        vector<Joker> pool;

        JokerPool();

        Joker drawJoker();
        void returnJoker(Joker& joker);

        bool isEmpty();



};





#endif