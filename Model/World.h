//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_MODEL_H
#define GRADIUS_MODEL_H

#include "Entity.h"
#include "PlayerShip.h"
#include "Timestamp.h"
#include "../ObserverPattern/Subject.h"
#include <vector>
#include <queue>
#include <memory>
#include <queue>

namespace Model {

    class World: public OP::Subject, public std::enable_shared_from_this<World> {
    public:
        World()= default;

        void loadLevel(std::string pathToJson);

        std::shared_ptr<PlayerShip> getPlayer();

        void addBullet(float x, float y, float width, float height, bool AI);

        bool checkForEnd();

        void updateWorld(float totalTime);

    private:

        void makeBorders();

        bool collision(std::shared_ptr<Entity> e1, std::shared_ptr<Entity> e2);

        void pushToCeilingQueue(unsigned int rows);

        void pushToFloorQueue(unsigned int rows);

        void destroyAll();

    private:
        std::shared_ptr<PlayerShip> player;
        std::vector<std::shared_ptr<Entity>> entities;
        std::queue<unsigned int> ceiling;
        std::queue<unsigned int> floor;
        std::queue<std::shared_ptr<Timestamp>> level;
    };

}

#endif //GRADIUS_MODEL_H
