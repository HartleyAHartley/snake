#include "gameboard.h"

GameBoard::GameBoard(EventHandler* eHandler, Renderer* render)
{
    m_eventHandler = eHandler;
    m_renderer = render;
    m_jKey.callback =(keyCB) &jKeyCallBack;
    m_jKey.keyDown = false;
    m_jKey.sc = SDL_SCANCODE_J;
    m_jKey.rbxRegister =(uint64_t) this;
    m_eventHandler->RegisterKeyCallback(&m_jKey);
    m_board.rect.x = 0;
    m_board.rect.y = 0;
    m_board.rect.w = 100;
    m_board.rect.h = 100;
    m_board.r = 56;
    m_board.g = 47;
    m_board.b = 32;
    m_board.render = false;
    m_renderer->AddRectangle(&m_board);
}

GameBoard::~GameBoard()
{
    //dtor
}

void GameBoard::jKeyCallBack(uint64_t * context){
    std::cout << "j" << std::endl;
    m_board.render = !m_board.render;
}
