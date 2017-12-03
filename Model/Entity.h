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

/**
\n    Returns the x coordinate of the entity
*/
        float getPositionX() const;

/**
\n    Returns the y coordinate of the entity
*/
        float getPositionY() const;

/**
\n    Updates the x coordinate of the entity by a new x coordinate
*/
        void updatePositionX(float newPositionX);

/**
\n    Updates the y coordinate of the entity by a new y coordinate
*/
        void updatePositionY(float newPositionY);


        float getHeight() const;


        float getWidth() const;


        bool isDestroyed() const;


        void wrecked();

    private:
        bool destroyed;
        float x;
        float y;
        float height;
        float width;
    };

}


#endif //GRADIUS_ENTITY_H
