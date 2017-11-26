//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_BULLET_H
#define GRADIUS_BULLET_H

#include "MovingEntity.h"

namespace Model {

    class Bullet : public MovingEntity {
    public:

        Bullet();

        Bullet(double x, double y, float height, float width, float speed, float timePerShot, unsigned int damage);

    private:
        void checkCoorX();

        void checkCoorY();

        float timePerShot;
        unsigned int damage;
    };

}


#endif //GRADIUS_BULLET_H
