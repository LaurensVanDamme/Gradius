//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_VIEW_H
#define GRADIUS_VIEW_H

#include <SFML/Graphics.hpp>
#include "Transformation.h"
#include <vector>

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

        View(unsigned int windowWidth, unsigned int windowHeight, Model::Model *model);

        void addPlayer(Model::Ship *entity, const std::string& pathToTexture, sf::Vector2u imageCount = sf::Vector2u(0,0), float switchTime = 0);

        void addViewEntity(Model::Entity *entity, const std::string& pathToTexture, sf::Vector2u imageCount = sf::Vector2u(0,0), float switchTime = 0);

        void checkForEvents(sf::Event event);

        void updateView(float deltaTime);

        bool isWindowOpen();

        virtual ~View();

    private:
        Model::Model *model;
        sf::RenderWindow *window;
        Transformation *transformation;
        std::vector<Entity *> entities;
    };

}


#endif //GRADIUS_VIEW_H
