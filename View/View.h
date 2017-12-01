//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_VIEW_H
#define GRADIUS_VIEW_H

#include "Transformation.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

namespace Model {
    class Model;
    class Entity;
    class Ship;
}

namespace View {

    class Entity;


    class View {  // Vergeet deconstructor ni!!!
    public:
        View();

        View(unsigned int windowWidth, unsigned int windowHeight);

        void addPlayer(std::weak_ptr<Model::Ship> entity, const std::string& pathToTexture, sf::Vector2u imageCount = sf::Vector2u(0,0), float switchTime = 0);

        void addViewEntity(std::shared_ptr<Model::Entity> entity, const std::string& pathToTexture, sf::Vector2u imageCount = sf::Vector2u(0,0), float switchTime = 0);

        void checkForEvents(sf::Event event);

        void updateView(float deltaTime);

        bool isWindowOpen();

    private:
        std::unique_ptr<sf::RenderWindow> window;
        std::vector<std::shared_ptr<Entity>> entities;
    };

}


#endif //GRADIUS_VIEW_H
