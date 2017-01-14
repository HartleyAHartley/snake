#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


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

    private:
};

#endif // GAMEOBJECT_H
