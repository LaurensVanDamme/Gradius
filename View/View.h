//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_VIEW_H
#define GRADIUS_VIEW_H


#include "../ObserverPattern/Observer.h"
#include "../ObserverPattern/Event.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

namespace Model {
    class World;
}

namespace View {

    class Entity;


    class View: public OP::Observer {
    public:


        View();

        View(unsigned int windowWidth, unsigned int windowHeight, std::weak_ptr<Model::World> model);


        void checkForEvents(sf::Event event);


        void update(OP::Event& event) override;


        void updateView(float deltaTime);


        bool isWindowOpen();

    private:


        void addViewEntity(std::shared_ptr<Model::Entity> entity);

    private:
        std::unique_ptr<sf::RenderWindow> window;
        std::vector<std::shared_ptr<Entity>> entities;
    };

}


#endif //GRADIUS_VIEW_H
