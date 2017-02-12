#include "fruit.h"
#include "game.h"

Fruit::Fruit(Game * g)
{
    m_game = g;
    name="Fruit";
    std::random_device rd;
    std:: mt19937 bng(rd());
    rng = bng;
    std::uniform_int_distribution<int> bx(m_game->getGrid(),m_game->GetW()-m_game->getGrid());
    std::uniform_int_distribution<int> by(m_game->getGrid(),m_game->GetH()-m_game->getGrid());
    x = bx;
    y = by;

    renderRect m_board;
    m_board.rect.x = GetX();
    m_board.rect.y = GetY();
    m_board.rect.w = m_game->getGrid();
    m_board.rect.h = m_game->getGrid();
    m_board.r = 56;
    m_board.g = 23;
    m_board.b = 255;

    m_rects["fruit"] = m_board;
    m_game->Getrenderer()->AddRectangle(&m_rects);
}

Fruit::~Fruit()
{
    //dtor
}

int Fruit::GetX(){
    int i = x(rng);
    return i-(i%m_game->getGrid());
}
int Fruit::GetY(){
    int i = y(rng);
    return i-(i%m_game->getGrid());
}

void Fruit::collisionCB(GameObject * obj){
    m_rects["fruit"].rect.x = GetX();
    m_rects["fruit"].rect.y = GetY();
    return;
}
