#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <stdio.h>
#include "types.h"
#include "eventhandler.h"
#include <functional>

class EventHandler;

class GameBoard
{
    public:
        GameBoard(EventHandler* eHandler, Renderer* render);
        ~GameBoard();
        void KeyCallBack(int sc);
    protected:

    private:
        EventHandler* m_eventHandler; //!< Pointer to eventHandler Object
        Renderer* m_renderer; //!< Pointer to renderer Object
        renderRect m_board; //!< Struct for holding rectangle rendering info
        keyCallback m_KeyCB[4]; //!< Struct for holding keycallback info.

};

#endif // GAMEBOARD_H
