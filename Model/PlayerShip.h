//
// Created by laurens on 12/4/17.
//

#ifndef GRADIUS_PLAYERSHIP_H
#define GRADIUS_PLAYERSHIP_H

#include "Ship.h"

namespace Model {

    class PlayerShip: public Ship {
    public:

        PlayerShip();

        PlayerShip(float x, float y, float width, float height, std::weak_ptr<World> model);


        void update(float time) override;


        bool canBeHit(float time, bool hit = true) override;


        void shoot(float time);

    protected:


        virtual void checkCoorX() override;


        virtual void checkCoorY() override;
    };

}


#endif //GRADIUS_PLAYERSHIP_H
