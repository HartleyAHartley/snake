#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <stdio.h>
#include <deque>

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
        void Update();

    private:
        float time=0;
        const int speed=25;
        keyCallback m_KeyCB[4]; //!< Struct for holding keycallback info.
        XY m_dir;
        void align();
        void AddRect(int id);
        void MoveRect(renderRect * rect, XY movement);
        void SetRect(renderRect * rect, XY pos);
        int maxLength=0;
        int length=1;
        int endTail =1;
        std::deque<renderRect> m_tails;
        void UpdateRect();
        void Reset();
};

#endif // SNAKE_H
