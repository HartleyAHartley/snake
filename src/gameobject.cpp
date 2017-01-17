#include "gameobject.h"

GameObject::GameObject()
{
    self = (unsigned long long)this;
}

GameObject::~GameObject()
{
    //dtor
}

void GameObject::collision(std::function<void(GameObject)> collisionCallback){
    GameObject obj;
    collisionCallback(obj);
}
