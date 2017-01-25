#include "gameobject.h"
#include "game.h"

GameObject::GameObject()
{
    self = (unsigned long long)this;
}

GameObject::~GameObject()
{
    //dtor
}

void GameObject::Update(){
    return;
}

void GameObject::collisionCB(GameObject * obj){
    return;
}

void GameObject::collision(){
    for(auto const& i : *m_game->GetGameObjects()){
        if(i != this){
            for(auto const& j : i->m_rects){
                for(auto const& h : m_rects){
                    if(SDL_HasIntersection(&j.rect,&h.rect)){
                        collisionCB(&(*i));
                        i->collisionCB(this);
                    }
                }
            }
        }
    }
}
