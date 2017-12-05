//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_SHIP_H
#define GRADIUS_SHIP_H

#include "Entity.h"
#include "Bullet.h"

namespace Model {

    class Model;

    class Ship : public Entity {
    public:


        Ship();

        Ship(float x, float y, float width, float height, std::weak_ptr<Model> model);


        bool canShoot(float time);

    protected:
        float lastTimeHit;
        float timePerShot; // in seconds
        std::weak_ptr<Model> model;

    private:
        float lastTimeShot;
    };

}


#endif //GRADIUS_SHIP_H
