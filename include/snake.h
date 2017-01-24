#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <stdio.h>
#include <functional>

class Game;
#include "gameobject.h"
#include "types.h"

class Snake : public GameObject
{
    public:
        /** Default constructor */
        Snake(Game* g);
        /** Default destructor */
        ~Snake();
        /** KeyCallBack */
        void KeyCallBack(int sc);


    protected:
        void collisionCB(GameObject * obj);

    private:
        keyCallback m_KeyCB[4]; //!< Struct for holding keycallback info.
};

#endif // SNAKE_H
