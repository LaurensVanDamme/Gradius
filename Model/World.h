//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_MODEL_H
#define GRADIUS_MODEL_H

#include "Entity.h"
#include "AIShooter.h"
#include "PlayerShip.h"
#include "../ObserverPattern/Subject.h"
#include <vector>
#include <memory>
#include <queue>

namespace Model {

    class World: public OP::Subject, public std::enable_shared_from_this<World> {  // Vergeet deconstructor ni!!!
    public:
        World();

        std::shared_ptr<PlayerShip> getPlayer();

        void setPlayer(float x, float y, float width, float height);

        void addBullet(float x, float y, float width, float height, bool AI);

        void addObstacle(float x, float y, float width, float height);

        void addAIShip(float x, float y, float width, float height);

        void makeBorders();

        bool checkForDestroyed();

        bool collision(std::shared_ptr<Entity> e1, std::shared_ptr<Entity> e2);

        void updateWorld(float totalTime);

        void pushToCeilingQueue(unsigned int rows);

        void pushToFloorQueue(unsigned int rows);

    private:
        std::shared_ptr<PlayerShip> player;
        std::vector<std::shared_ptr<Entity>> entities;
        std::queue<unsigned int> ceiling;
        std::queue<unsigned int> floor;
    };

}

#endif //GRADIUS_MODEL_H
