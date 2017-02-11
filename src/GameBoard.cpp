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

    renderRect m_board[5];
    int w[] = {10,10,m_game->GetH(),m_game->GetH(),10};
    int h[] = {m_game->GetW(),m_game->GetW(),10,10,10};
    int posX[] = {0,m_game->GetW()-w[1],w[0],w[0],10};
    int posY[] = {0,0,0,m_game->GetH()-h[3],10};
    std::string names[] = {"boardL","boardR","boardUp","boardDown","test"};
    int colorR = 56;
    int colorG = 23;
    int colorB = 255;
    for(int i=0;i<5;i++){
        m_board[i].rect.w = w[i];
        m_board[i].rect.h = h[i];
        m_board[i].x = posX[i];
        m_board[i].y = posY[i];
        m_board[i].r = colorR;
        m_board[i].g = colorG;
        m_board[i].b = colorB;
        m_rects[names[i]] = m_board[i];
        m_game->Getrenderer()->AddRectangle(&m_rects[names[i]]);
    }

}

void GameBoard::collisionCB(GameObject * obj){
    m_rects["pebble"].rect.x = x(rng);
    m_rects["pebble"].rect.y = y(rng);
    return;
}

GameBoard::~GameBoard() {
    //dtor
}
