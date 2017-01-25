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
    m_snake.rect.x = 0;
    m_snake.rect.y = 0;
    m_snake.rect.w = 20;
    m_snake.rect.h = 20;
    m_snake.r = 240;
    m_snake.g = 56;
    m_snake.b = 255;
    m_rects.insert(m_rects.end(), m_snake);
    m_game->Getrenderer()->AddRectangle(&m_rects.back());
}

Snake::~Snake()
{
    //dtor
}

void Snake::collisionCB(GameObject * obj){
    std::cout << "snake" << std::endl;
    return;
}

void Snake::KeyCallBack(int sc) {
    switch (sc) {
    case SDL_SCANCODE_W:
        m_rects.back().y -= 50 * m_game->getDTime();
        m_rects.back().rect.y = (int)m_rects.back().y;
        break;
    case SDL_SCANCODE_A:
        m_rects.back().x -= 50 * m_game->getDTime();
        m_rects.back().rect.x = (int)m_rects.back().x;
        break;
    case SDL_SCANCODE_S:
        m_rects.back().y += 50 * m_game->getDTime();
        m_rects.back().rect.y = (int)m_rects.back().y;
        break;
    case SDL_SCANCODE_D:
        m_rects.back().x += 50 * m_game->getDTime();
        m_rects.back().rect.x = (int)m_rects.back().x;
        break;
    default:
        std::cout << "Invaild Scancode";
        return;
    }
    using namespace std::placeholders; // for `_1`
    collision();
}
