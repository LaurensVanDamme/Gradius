//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_MODEL_H
#define GRADIUS_MODEL_H

#include "Entity.h"
#include "AIShip.h"
#include "Ship.h"
#include <vector>
#include <memory>

namespace Model {

    class Model {  // Vergeet deconstructor ni!!!
    public:
        std::shared_ptr<Ship> getPlayer();

        void setPlayer(double x, double y, float width, float height, float speed, unsigned int healt,
                       float timePerShot);

        std::shared_ptr<Entity> addBullet(unsigned int damage, float speed);

        std::shared_ptr<Entity> addAIBullet(unsigned int damage, float speed);

        std::shared_ptr<Entity> addBorder();

        std::shared_ptr<AIShip> addAIShip(double x, double y, float width, float height, float speed,
                                                   unsigned int healt, float timePerShot);

        bool checkForDestroyed();

        std::vector<std::shared_ptr<Entity>> updateWorld(float totalTime);



    private:
        std::shared_ptr<Ship> player;
        std::vector<std::shared_ptr<Entity>> scrollingEntities;
        std::vector<std::shared_ptr<AIShip>> AIShips;
    };

}

#endif //GRADIUS_MODEL_H
