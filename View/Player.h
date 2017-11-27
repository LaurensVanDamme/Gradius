//
// Created by laurens on 11/27/17.
//

#ifndef GRADIUS_PLAYER_H
#define GRADIUS_PLAYER_H

#include "Entity.h"

namespace Model {
    class Ship;
}

namespace View {

    class Player: public Entity {
    public:
        Player(Model::Ship *entity, const std::string &pathToTexture, const sf::Vector2u &imageCount,
               float switchTime);

        void draw(sf::RenderWindow *window, float deltaTime) override;

    private:
        Model::Ship* subject;
    };

}

#endif //GRADIUS_PLAYER_H
