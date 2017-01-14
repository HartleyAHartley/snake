#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <stdio.h>
#include <functional>

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
    void KeyCallBack(int sc);
protected:

private:
    Game* m_game; //!< Pointer to game object
    renderRect m_board; //!< Struct for holding rectangle rendering info
    keyCallback m_KeyCB[4]; //!< Struct for holding keycallback info.

};

#endif // GAMEBOARD_H
