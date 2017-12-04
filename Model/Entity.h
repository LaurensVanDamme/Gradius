//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_ENTITY_H
#define GRADIUS_ENTITY_H

#include "../ObserverPattern/Subject.h"

namespace Model {

    class Entity: public OP::Subject {
    public:

        Entity();

        Entity(float x, float y, float height, float width);


        float getPositionX() const;


        float getPositionY() const;


        float getHeight() const;


        float getWidth() const;


        unsigned int getHealth() const;


        bool isDestroyed() const;


        void hit(unsigned int damage);


        virtual bool canBeHit(float time);


        virtual const std::string &getType() const=0;


        virtual void update()=0;

    protected:

        void wrecked();

    private:

        virtual float checkCoorX()=0;

        virtual float checkCoorY()=0;

    protected:
        float x;
        float y;
        unsigned int health;

    private:
        float height;
        float width;
        bool destroyed;
    };

}


#endif //GRADIUS_ENTITY_H
