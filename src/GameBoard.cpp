#include "gameboard.h"

GameBoard::GameBoard(Game* g) {

    std::random_device rd;
    std:: mt19937 bng(rd());
    rng = bng;
    std::uniform_int_distribution<int> bx(0,640);
    std::uniform_int_distribution<int> by(0,480);
    x = bx;
    y = by;

    m_game = g;

    renderRect m_board;
    m_board.rect.x = 200;
    m_board.rect.y = 200;
    m_board.rect.w = 10;
    m_board.rect.h = 10;
    m_board.r = 56;
    m_board.g = 23;
    m_board.b = 255;

    m_rects["pebble"] = m_board;
    m_game->Getrenderer()->AddRectangle(&m_rects["pebble"]);
}

void GameBoard::collisionCB(GameObject * obj){
    m_rects["pebble"].rect.x = x(rng);
    m_rects["pebble"].rect.y = y(rng);
    return;
}

GameBoard::~GameBoard() {
    //dtor
}
