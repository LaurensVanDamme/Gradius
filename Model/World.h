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

        /**
        * @brief Initialize a Model::World object
        */
        World()= default;

        /**
        * @brief Load a level from a json file and prepare the world to start the game
        */
        void loadLevel(std::string pathToJson);

        /**
        * @brief Returns a pointer to the playerschip of the world
        */
        std::shared_ptr<PlayerShip> getPlayer();

        /**
        * @brief Add a bullet to the world
        */
        void addBullet(float x, float y, float width, float height, bool AI);

        /**
        * @brief Returns if the game has to end
        */
        bool checkForEnd();

        /**
        * @brief Updates the world completely
        */
        void updateWorld(float totalTime);

    private:

        /**
        * @brief Creates the borders on the top and bottom of the world
        */
        void makeBorders();

        /**
        * @brief Checks if there is collision between two entities
        */
        bool collision(std::shared_ptr<Entity> e1, std::shared_ptr<Entity> e2);

        /**
        * @brief Destroys every entity in the world
        */
        void destroyAll();

    private:
        std::shared_ptr<PlayerShip> player;
        std::vector<std::shared_ptr<Entity>> entities;
        std::queue<std::shared_ptr<Timestamp>> level;
    };

}

#endif //GRADIUS_MODEL_H
