//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_VIEW_H
#define GRADIUS_VIEW_H

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


        void addViewEntity(std::shared_ptr<Model::Entity> entity);


        void checkForEvents(sf::Event event);


        void updateView(float deltaTime);


        bool isWindowOpen();

    private:
        std::unique_ptr<sf::RenderWindow> window;
        std::vector<std::shared_ptr<Entity>> entities;
    };

}


#endif //GRADIUS_VIEW_H
