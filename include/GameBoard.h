#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <stdio.h>
#include <functional>
#include <random>

#include "types.h"
#include "eventhandler.h"
#include "gameobject.h"
#include "game.h"

class Game;

class GameBoard : public GameObject
{
public:
    GameBoard(Game* g);
    virtual ~GameBoard();
    void collisionCB(GameObject * obj);

protected:

private:
    keyCallback m_KeyCB[4]; //!< Struct for holding keycallback info.
    std:: mt19937 rng;
    std::uniform_int_distribution<int> x;
    std::uniform_int_distribution<int> y;

};

#endif // GAMEBOARD_H
