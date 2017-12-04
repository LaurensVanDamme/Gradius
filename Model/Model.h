//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_MODEL_H
#define GRADIUS_MODEL_H

#include "Entity.h"
#include "Border.h"
#include "AIShip.h"
#include "PlayerShip.h"
#include <vector>
#include <memory>

namespace Model {

    class Model {  // Vergeet deconstructor ni!!!
    public:
        std::shared_ptr<PlayerShip> getPlayer();

        void setPlayer(float x, float y, float width, float height);

//        std::shared_ptr<Entity> addBullet(unsigned int damage, float speed);
//
//        std::shared_ptr<Entity> addAIBullet(unsigned int damage, float speed);

        std::shared_ptr<Entity> addBorder();

//        std::shared_ptr<AIShip> addAIShip(double x, double y, float width, float height, float speed,
//                                                   unsigned int healt, float timePerShot);

        bool checkForDestroyed();

        void updateWorld(float totalTime);



    private:
        std::shared_ptr<PlayerShip> player;
        std::vector<std::shared_ptr<Entity>> scrollingEntities;
        std::vector<std::shared_ptr<AIShip>> AIShips;
    };

}

#endif //GRADIUS_MODEL_H
