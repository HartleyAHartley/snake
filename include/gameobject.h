#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <functional>


class GameObject
{
    public:
        /** Default constructor */
        GameObject();
        /** Default destructor */
        ~GameObject();
        /** Get self identifier */
        unsigned long long getself(){return self;}
        /** Destory this objec */


    protected:
        bool operator==(GameObject* obj){return self==obj->getself();}
        unsigned long long self;
        void collision(std::function<void(GameObject)> collisionCallback);
        void collisionCB(GameObject obj);

    private:
};

#endif // GAMEOBJECT_H
