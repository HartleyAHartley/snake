#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <stdio.h>
#include <functional>

#include "types.h"
#include "eventhandler.h"
#include "gameobject.h"
#include "game.h"

class Game;

class Snake : public GameObject
{
    public:
        /** Default constructor */
        Snake(Game* g);
        /** Default destructor */
        virtual ~Snake();
        /** KeyCallBack */
        void KeyCallBack(int sc);


    protected:
        virtual void collisionCB(GameObject obj);

    private:
        Game* m_game; //!< Pointer to game object
        renderRect m_board; //!< Struct for holding rectangle rendering info
        keyCallback m_KeyCB[4]; //!< Struct for holding keycallback info.
};

#endif // SNAKE_H
