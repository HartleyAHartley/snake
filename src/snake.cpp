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
    align();
    m_game->Getrenderer()->AddRectangle(&m_rects);
    m_game->Getrenderer()->AddRectangle(&m_tails);
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
        if(maxLength == 0){
            maxLength=4;
        } else{
            maxLength*=2;
        }
    }
}

void Snake::Reset(){
    m_tails.clear();
    if(m_tails.empty()){
        std::cout<<"reset"<<std::endl;
    }
    maxLength =0;
    length =1;
    endTail =1;
    m_rects["0"].x = m_rects["0"].rect.x = m_game->GetW()/2 - (m_rects["0"].rect.w/2);
    m_rects["0"].y = m_rects["0"].rect.y = m_game->GetH()/2 - (m_rects["0"].rect.h/2);
    align();
}

void Snake::AddRect(int id){
    renderRect temp;
    temp.rect.w = m_game->getGrid();
    temp.rect.h = m_game->getGrid();
    temp.rect.x = temp.x = m_rects["0"].x;
    temp.rect.y = temp.y = m_rects["0"].y;
    temp.offset.x = -(m_dir.x*speed);
    temp.offset.y = -(m_dir.y*speed);
    temp.r = (12*id)%256;
    temp.g = (255*id/5)%256;
    temp.b = (240*id/7)%256;
    temp.render = false;
    m_tails.push_front(temp);
}

void Snake::UpdateRect(){
    renderRect temp = m_tails.back();
    m_tails.pop_back();
    temp.render = false;
    temp.rect.x = m_rects["0"].x;
    temp.rect.y = m_rects["0"].y;
    m_tails.push_front(temp);
}

void Snake::Update(){
    time+=m_game->getDTime();
    if(time > 0.1){
        time=0;
        MoveRect(&m_rects["0"],m_dir*m_game->getGrid());
        m_tails.front().render = true;
        if(length <= maxLength){
            AddRect(length++);
        } else if(!m_tails.empty()){
            UpdateRect();
        }
    }
    collision();
}

void Snake::MoveRect(renderRect * rect, XY movement){
    rect->AddX(movement.x);
    rect->AddY(movement.y);
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
        }
        break;
    case SDL_SCANCODE_A:
        if(m_dir.x==0){
            m_dir.y=0;
            m_dir.x=-1;
        }
        break;
    case SDL_SCANCODE_S:
        if(m_dir.y==0){
            m_dir.y=1;
            m_dir.x=0;
        }
        break;
    case SDL_SCANCODE_D:
        if(m_dir.x==0){
            m_dir.y=0;
            m_dir.x=1;
        }
        break;
    default:
        std::cout << "Invaild Scancode";
        return;
    }
}
