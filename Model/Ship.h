//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_SHIP_H
#define GRADIUS_SHIP_H

#include "Entity.h"
#include "Bullet.h"

namespace Model {

    class Ship : public Entity {
    public:


        Ship();

        Ship(float x, float y, float width, float height, unsigned int healt, float speed);


        bool canShoot(float time);

    private:
        float lastTimeShot;

    protected:
        float lastTimeHit;
        float timePerShot; // in seconds
    };

}


#endif //GRADIUS_SHIP_H
