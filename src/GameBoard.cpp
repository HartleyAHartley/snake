#include "gameboard.h"

GameBoard::GameBoard(Game* g) {
    m_game = g;
    name="GameBoard";

    int w[] = {m_game->getGrid(),m_game->getGrid(),m_game->GetW(),m_game->GetW()};
    int h[] = {m_game->GetH(),m_game->GetH(),m_game->getGrid(),m_game->getGrid()};
    int posX[] = {0,m_game->GetW()-m_game->getGrid(),m_game->getGrid(),m_game->getGrid()};
    int posY[] = {0,0,0,m_game->GetH()-m_game->getGrid()};
    std::string names[] = {"boardL","boardR","boardUp","boardDown"};
    int colorR = 56;
    int colorG = 23;
    int colorB = 255;
    for(int i=0;i<4;i++){
        renderRect m_board;
        m_board.rect.w = w[i];
        m_board.rect.h = h[i];
        m_board.x = m_board.rect.x = posX[i];
        m_board.y = m_board.rect.y = posY[i];
        m_board.r = colorR;
        m_board.g = colorG;
        m_board.b = colorB;
        m_rects[names[i]] = m_board;

    }
    m_game->Getrenderer()->AddRectangle(&m_rects);
}

void GameBoard::collisionCB(GameObject * obj){
    return;
}

GameBoard::~GameBoard() {
    //dtor
}
