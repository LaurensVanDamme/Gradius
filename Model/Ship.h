//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_SHIP_H
#define GRADIUS_SHIP_H

#include "Entity.h"
#include "Bullet.h"

namespace Model {

    class World;

    class Ship : public Entity {
    public:

        /**
        * @brief Initialize a Model::Ship object
        */
        Ship()= default;

        Ship(float x, float y, float width, float height, std::weak_ptr<World> &world);

        /**
        * @brief Returns if the ship can shoot
        */
        bool canShoot(float time);

    protected:
        float lastTimeHit{};
        float timePerShot{}; // in seconds
        std::weak_ptr<World> world;

    private:
        float lastTimeShot{};
    };

}


#endif //GRADIUS_SHIP_H
