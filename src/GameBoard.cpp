#include "GameBoard.h"

GameBoard::GameBoard(EventHandler* eHandler)
{
    m_eventHandler = eHandler;
    m_jKey.callback =(keyCB) &jKeyCallBack;
    m_jKey.keyDown = true;
    m_jKey.sc = SDL_SCANCODE_J;
    m_eventHandler->RegisterKeyCallback(m_jKey);
}

GameBoard::~GameBoard()
{
    //dtor
}

void GameBoard::jKeyCallBack(){
    std::cout << "j" << std::endl;
}
