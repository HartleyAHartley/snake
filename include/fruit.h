#ifndef FRUIT_H
#define FRUIT_H

#include <random>

class Game;
#include "gameObject.h"
#include "types.h"


class Fruit : public GameObject
{
    public:
        Fruit(Game * g);
        virtual ~Fruit();

    protected:
        void collisionCB(GameObject * obj);

    private:
        std:: mt19937 rng;
        std::uniform_int_distribution<int> x;
        std::uniform_int_distribution<int> y;
        int GetX();
        int GetY();
};

#endif // FRUIT_H
