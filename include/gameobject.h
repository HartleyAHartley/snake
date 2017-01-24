#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <functional>
#include <list>
#include "types.h"

class Game;

class GameObject
{
    public:
        /** Default constructor */
        GameObject();
        /** Default destructor */
        virtual ~GameObject();
        /** Get self identifier */
        unsigned long long getself(){return self;}
        /** Destroy this object */


    protected:
        bool operator==(GameObject* obj){return self==obj->getself();}
        unsigned long long self;
        void collision();
        virtual void collisionCB(GameObject * obj);
        Game* m_game; //!< Pointer to game object
        std::list<renderRect> m_rects; //!< Struct for holding rectangle rendering info


    private:
};

#endif // GAMEOBJECT_H
