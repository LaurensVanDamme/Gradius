//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_MODEL_H
#define GRADIUS_MODEL_H

#include "Entity.h"
#include "AIShip.h"
#include "PlayerShip.h"
#include "../ObserverPattern/Subject.h"
#include <vector>
#include <memory>

namespace Model {

    class Model: public OP::Subject {  // Vergeet deconstructor ni!!!
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
        std::vector<std::shared_ptr<Entity>> entities;
    };

}

#endif //GRADIUS_MODEL_H
