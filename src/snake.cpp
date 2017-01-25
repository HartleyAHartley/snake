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
    switch (sc) {
    case SDL_SCANCODE_W:
        m_rects["snake1"].AddY(-50 * m_game->getDTime());
        break;
    case SDL_SCANCODE_A:
        m_rects["snake1"].AddX(-50 * m_game->getDTime());
        break;
    case SDL_SCANCODE_S:
        m_rects["snake1"].AddY(50 * m_game->getDTime());
        break;
    case SDL_SCANCODE_D:
        m_rects["snake1"].AddX(50 * m_game->getDTime());
        break;
    default:
        std::cout << "Invaild Scancode";
        return;
    }
    using namespace std::placeholders; // for `_1`
    collision();
}
