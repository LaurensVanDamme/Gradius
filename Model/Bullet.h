//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_BULLET_H
#define GRADIUS_BULLET_H

#include "MovingEntity.h"

class Bullet: public MovingEntity {
public:

private:
    float timePerShot;
    unsigned int damage;
};


#endif //GRADIUS_BULLET_H
