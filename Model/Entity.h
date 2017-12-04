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

        Entity(float x, float y, float height, float width, float speed);


        float getPositionX() const;


        float getPositionY() const;


        float getHeight() const;


        float getWidth() const;


        float getSpeed() const;


        unsigned int getHealth() const;


        bool isDestroyed() const;

/**
* @brief Moves the entity up in the coordinate system
*/
        void moveUp();

/**
* @brief Moves the entity down in the coordinate system
*/
        void moveDown();

/**
* @brief Moves the entity right in the coordinate system
*/
        void moveRight();

/**
* @brief Moves the entity left in the coordinate system
*/
        void moveLeft();


        void hit(unsigned int damage);


        virtual bool canBeHit(float time, bool hit);


        virtual const std::string &getType() const=0;


        virtual unsigned int getDamage() const=0;


        virtual void update(float time)=0;

    protected:


        void wrecked();


        virtual void checkCoorX();


        virtual void checkCoorY();


    protected:
        float x;
        float y;
        unsigned int health;

    private:
        float height;
        float width;
        float speed;
        bool destroyed;
    };

}


#endif //GRADIUS_ENTITY_H
