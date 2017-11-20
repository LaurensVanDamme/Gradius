//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_MOVINGENTITY_H
#define GRADIUS_MOVINGENTITY_H

#include "Entity.h"

class MovingEntity: public Entity {
public:
    MovingEntity();
    MovingEntity(double x, double y, float height, float width, float speed);

/**
\n    Moves the entity up in the coordinate system
*/
    void moveUp(float deltaTime);

/**
\n    Moves the entity down in the coordinate system
*/
    void moveDown(float deltaTime);

/**
\n    Moves the entity right in the coordinate system
*/
    void moveRight(float deltaTime);

/**
\n    Moves the entity left in the coordinate system
*/
    void moveLeft(float deltaTime);

private:
    float speed;
};


#endif //GRADIUS_MOVINGENTITY_H
