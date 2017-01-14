#include "gameboard.h"

GameBoard::GameBoard(Game* g) {

    m_game = g;

    m_board.rect.x = 200;
    m_board.rect.y = 200;
    m_board.rect.w = 10;
    m_board.rect.h = 10;
    m_board.r = 56;
    m_board.g = 23;
    m_board.b = 255;
    m_game->Getrenderer()->AddRectangle(&m_board);
}

GameBoard::~GameBoard() {
    //dtor
}

void GameBoard::KeyCallBack(int sc) {
    switch (sc) {
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
