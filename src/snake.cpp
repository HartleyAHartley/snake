#include "snake.h"

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
    m_board.rect.x = 0;
    m_board.rect.y = 0;
    m_board.rect.w = 20;
    m_board.rect.h = 20;
    m_board.r = 240;
    m_board.g = 56;
    m_board.b = 255;
    m_game->Getrenderer()->AddRectangle(&m_board);
}

Snake::~Snake()
{
    //dtor
}

void Snake::KeyCallBack(int sc) {
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
        return;
    }
    /*if(collision(GameObject* obj)){
        obj.destory();
    }*/
}
