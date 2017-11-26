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

        Bullet(double x, double y, float width, float height, float speed, float timePerShot, unsigned int damage);

    private:
        void checkCoorX() override;

        void checkCoorY() override;

        float timePerShot;
        unsigned int damage;
    };

}


#endif //GRADIUS_BULLET_H
