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
             Bullet *bullettype = nullptr);

    private:
        void checkCoorX();

        void checkCoorY();

        unsigned int healt;
        Bullet *bullettype;
    };

}


#endif //GRADIUS_SHIP_H
