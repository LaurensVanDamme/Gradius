//
// Created by laurens on 11/27/17.
//

#ifndef GRADIUS_PLAYER_H
#define GRADIUS_PLAYER_H

#include "Entity.h"
#include <memory>

namespace Model {
    class Ship;
}

namespace View {

    class Player: public Entity {
    public:

    /**
    * @brief Initialize a View::Player object
    */
        Player()= default;

        Player(std::weak_ptr<Model::Ship> entity, const std::string &pathToTexture, const sf::Vector2u &imageCount,
               float switchTime);

    /**
    * @brief Draw the player and it's health on the given window
    */
        void draw(std::unique_ptr<sf::RenderWindow>& window, float deltaTime) override;

    private:
        std::weak_ptr<Model::Ship> subject;
    };

}

#endif //GRADIUS_PLAYER_H
