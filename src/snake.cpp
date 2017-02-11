#include "snake.h"
#include "game.h"

Snake::Snake(Game* g)
{
    using namespace std::placeholders; // for `_1`

    m_game = g;

    int sc[4] = {SDL_SCANCODE_W, SDL_SCANCODE_A, SDL_SCANCODE_S, SDL_SCANCODE_D};
    for(int i = 0; i < 4; i++) {
        m_KeyCB[i].callback = std::bind(&KeyCallBack, this, _1);
        m_KeyCB[i].keyDown = false;
        m_KeyCB[i].sc = sc[i];
        m_game->GeteventHandler()->RegisterKeyCallback(&m_KeyCB[i]);
    }
    renderRect m_snake;
    m_snake.rect.w = 20;
    m_snake.rect.h = 20;
    m_snake.x = m_snake.rect.x = m_game->GetW()/2 - (m_snake.rect.w/2);
    m_snake.y = m_snake.rect.y = m_game->GetH()/2 - (m_snake.rect.h/2);
    m_snake.r = 240;
    m_snake.g = 56;
    m_snake.b = 255;
    m_rects["snake1"] = m_snake;
    m_game->Getrenderer()->AddRectangle(&m_rects["snake1"]);
}

Snake::~Snake()
{
    //dtor
}

void Snake::collisionCB(GameObject * obj){
    return;
}

void Snake::KeyCallBack(int sc) {
    XY pos;
    switch (sc) {
    case SDL_SCANCODE_W:
        pos.y -= speed;
        break;
    case SDL_SCANCODE_A:
        pos.x -= speed;
        break;
    case SDL_SCANCODE_S:
        pos.y += speed;
        break;
    case SDL_SCANCODE_D:
        pos.x += speed;
        break;
    default:
        std::cout << "Invaild Scancode";
        return;
    }
    Move(pos);
    collision();
}
