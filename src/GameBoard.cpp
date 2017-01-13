#include "gameboard.h"

GameBoard::GameBoard(EventHandler* eHandler, Renderer* render)
{
    using namespace std::placeholders; // for `_1`

    m_eventHandler = eHandler;
    m_renderer = render;

    int sc[4] = {SDL_SCANCODE_W, SDL_SCANCODE_A, SDL_SCANCODE_S, SDL_SCANCODE_D};
    for(int i = 0; i < 4; i++){
        m_KeyCB[i].callback = std::bind(&KeyCallBack, this, _1);
        m_KeyCB[i].keyDown = true;
        m_KeyCB[i].sc = sc[i];
        m_eventHandler->RegisterKeyCallback(&m_KeyCB[i]);
    }


    m_board.rect.x = 0;
    m_board.rect.y = 0;
    m_board.rect.w = 100;
    m_board.rect.h = 100;
    m_board.r = 240;
    m_board.g = 56;
    m_board.b = 255;
    m_renderer->AddRectangle(&m_board);
}

GameBoard::~GameBoard()
{
    //dtor
}

void GameBoard::KeyCallBack(int sc){
    switch (sc){
        case SDL_SCANCODE_W:
            m_board.rect.y--;
            break;
        case SDL_SCANCODE_A:
            m_board.rect.x--;
            break;
        case SDL_SCANCODE_S:
            m_board.rect.y++;
            break;
        case SDL_SCANCODE_D:
            m_board.rect.x++;
            break;
        default:
            std::cout << "Invaild Scancode";
    }
}
