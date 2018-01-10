//
// Created by laurens on 12/4/17.
//

#ifndef GRADIUS_PLAYERSHIP_H
#define GRADIUS_PLAYERSHIP_H

#include "Ship.h"

namespace Model {

    class PlayerShip: public Ship {
    public:

        /**
        * @brief Initialize a Model::PlayerShip object
        */
        PlayerShip()= default;

        PlayerShip(float x, float y, float width, float height, std::weak_ptr<World> model);

        /**
        * @brief Update the playership with the given time
        */
        void update(float time) override;

        /**
        * @brief Returns if the player can be hit
        */
        bool canBeHit(float time, bool hit = true) override;

        /**
        * @brief Let's the playership shoot
        */
        void shoot(float time);

    protected:

        /**
        * @brief Check if the x coordinate is valid and change it if needed
        */
        void checkCoorX() override;

        /**
        * @brief Check if the y coordinate is valid and change it if needed
        */
        void checkCoorY() override;
    };

}


#endif //GRADIUS_PLAYERSHIP_H
