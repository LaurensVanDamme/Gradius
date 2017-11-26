//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_MOVINGENTITY_H
#define GRADIUS_MOVINGENTITY_H

#include "Entity.h"

namespace Model {

    class MovingEntity : public Entity {
    public:
        MovingEntity();

        MovingEntity(double x, double y, float height, float width, float speed);

        float getSpeed() const;

/**
\n    Moves the entity up in the coordinate system
*/
        void moveUp();

/**
\n    Moves the entity down in the coordinate system
*/
        void moveDown();

/**
\n    Moves the entity right in the coordinate system
*/
        void moveRight();

/**
\n    Moves the entity left in the coordinate system
*/
        void moveLeft();

    private:
        virtual void checkCoorX()=0;

        virtual void checkCoorY()=0;

        float speed;
    };

}


#endif //GRADIUS_MOVINGENTITY_H
