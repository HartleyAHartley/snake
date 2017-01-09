#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include "keyboardCallback.h"
#include "eventhandler.h"


class GameBoard
{
    public:
        GameBoard(EventHandler* eHandler);
        ~GameBoard();
        void jKeyCallBack();
    protected:

    private:
        EventHandler* m_eventHandler; //!< Pointer to eventHandler Object
        keyCallback m_jKey; //!< Struct for holding keycallback info.

};

#endif // GAMEBOARD_H
