//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_SHIP_H
#define GRADIUS_SHIP_H

#include "MovingEntity.h"
#include "Bullet.h"

namespace Model {

    class Ship : public MovingEntity {
    public:
        Ship();

        Ship(double x, double y, float width, float height, float speed, unsigned int healt,
             float timePerShot);

        bool canShoot(float time);

    private:
        void checkCoorX() override;

        void checkCoorY() override;

        float lastTimeShot;
        float timePerShot;
        unsigned int healt;
        Bullet *bullettype;
    };

}


#endif //GRADIUS_SHIP_H
