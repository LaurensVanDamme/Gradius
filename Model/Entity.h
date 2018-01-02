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


        float getSpeed() const;


        unsigned int getHealth() const;


        unsigned int getDamage() const;


        const std::string &getType() const;


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


        void wrecked();


        void hit(unsigned int damage);


        virtual bool canBeHit(float time, bool hit);


        virtual void update(float time)=0;

    protected:


        virtual void checkCoorX();


        virtual void checkCoorY();


    protected:
        float x;
        float y;
        float speed;
        unsigned int health;
        unsigned int damage;
        std::string type;

    private:
        float height;
        float width;
        bool destroyed;
    };

}


#endif //GRADIUS_ENTITY_H
