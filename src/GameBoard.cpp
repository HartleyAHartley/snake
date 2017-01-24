#include "gameboard.h"

GameBoard::GameBoard(Game* g) {

    m_game = g;

    renderRect m_board;
    m_board.rect.x = 200;
    m_board.rect.y = 200;
    m_board.rect.w = 10;
    m_board.rect.h = 10;
    m_board.r = 56;
    m_board.g = 23;
    m_board.b = 255;

    m_rects.insert(m_rects.end(), m_board);
    m_game->Getrenderer()->AddRectangle(&m_rects.back());
}

void GameBoard::collisionCB(GameObject * obj){
    std::cout << "board" << std::endl;
    return;
}

GameBoard::~GameBoard() {
    //dtor
}

void GameBoard::KeyCallBack(int sc) {
    switch (sc) {
    case SDL_SCANCODE_W:
        m_rects.back().rect.y--;
        break;
    case SDL_SCANCODE_A:
        m_rects.back().rect.x--;
        break;
    case SDL_SCANCODE_S:
        m_rects.back().rect.y++;
        break;
    case SDL_SCANCODE_D:
        m_rects.back().rect.x++;
        break;
    default:
        std::cout << "Invaild Scancode";
    }
}
