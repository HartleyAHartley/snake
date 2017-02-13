#include "snake.h"
#include "game.h"

Snake::Snake(Game* g)
{
    name = "Snake";
    m_game = g;
    m_dir.x = 1;
    m_dir.y = 0;


    int sc[4] = {SDL_SCANCODE_W, SDL_SCANCODE_A, SDL_SCANCODE_S, SDL_SCANCODE_D};
    for(int i = 0; i < 4; i++) {
        m_KeyCB[i].callback = std::bind(&KeyCallBack, this, std::placeholders::_1);
        m_KeyCB[i].keyDown = true;
        m_KeyCB[i].sc = sc[i];
        m_game->GeteventHandler()->RegisterKeyCallback(&m_KeyCB[i]);
    }
    renderRect m_snake;
    m_snake.rect.w = m_game->getGrid();
    m_snake.rect.h = m_game->getGrid();
    m_snake.x = m_snake.rect.x = m_game->GetW()/2 - (m_snake.rect.w/2);
    m_snake.y = m_snake.rect.y = m_game->GetH()/2 - (m_snake.rect.h/2);
    m_snake.r = 240;
    m_snake.g = 56;
    m_snake.b = 255;
    m_rects["0"] = m_snake;

    m_game->Getrenderer()->AddRectangle(&m_rects);
}

Snake::~Snake()
{
    //dtor
}

void Snake::collisionCB(GameObject * obj){
    if(!strcmp(obj->getName(), "GameBoard")){
        XY pos;
        pos.x = m_game->GetW()/2 - (m_rects["0"].rect.w/2);
        pos.y = m_game->GetH()/2 - (m_rects["0"].rect.h/2);
        SetRect(&m_rects["0"],pos);
    } else if(!strcmp(obj->getName(), "Fruit")) {
        length++;
    }
}

void Snake::AddRect(){
    renderRect temp;
    temp.rect.w = m_game->getGrid();
    temp.rect.h = m_game->getGrid();
    temp.rect.x = temp.x = m_rects["0"].x-(m_dir.x*speed);
    temp.rect.y = temp.y = m_rects["0"].y-(m_dir.y*speed);
    temp.offset.x = -(m_dir.x*speed);
    temp.offset.y = -(m_dir.y*speed);
    temp.r = 56;
    temp.g = 255;
    temp.b = 240;
    m_rects["1"] = temp;
}

void Snake::Update(){
    MoveRect(&m_rects["0"],m_dir*speed);
    collision();
}

void Snake::MoveRect(renderRect * rect, XY movement){
    rect->AddX((movement.x ) * m_game->getDTime());
    rect->AddY((movement.y ) * m_game->getDTime());
}

void Snake::SetRect(renderRect * rect, XY pos){
    rect->rect.x = rect->x = pos.x;
    rect->rect.y = rect->y = pos.y;
}

void Snake::align(){
    XY pos;
    pos.x = round(m_rects["0"].x/m_game->getGrid())*m_game->getGrid();
    pos.y = round(m_rects["0"].y/m_game->getGrid())*m_game->getGrid();
    SetRect(&m_rects["0"],pos);
}

void Snake::KeyCallBack(int sc) {
    switch (sc) {
    case SDL_SCANCODE_W:
        if(m_dir.y==0){
            m_dir.y=-1;
            m_dir.x=0;
            align();
        }
        break;
    case SDL_SCANCODE_A:
        if(m_dir.x==0){
            m_dir.y=0;
            m_dir.x=-1;
            align();
        }
        break;
    case SDL_SCANCODE_S:
        if(m_dir.y==0){
            m_dir.y=1;
            m_dir.x=0;
            align();
        }
        break;
    case SDL_SCANCODE_D:
        if(m_dir.x==0){
            m_dir.y=0;
            m_dir.x=1;
            align();
        }
        break;
    default:
        std::cout << "Invaild Scancode";
        return;
    }
}
