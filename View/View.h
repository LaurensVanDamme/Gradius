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

    /**
    * @brief Initialize a View::View object
    */
        View();

        View(unsigned int windowWidth, unsigned int windowHeight, std::weak_ptr<Model::World> model);

    /**
    * @brief Check for window events and react to them
    */
        void checkForEvents(sf::Event event);

    /**
    * @brief Update function from observer pattern: react to the given event
    */
        void update(OP::Event& event) override;

    /**
    * @brief Update the view and redraw the view
    */
        void updateView(float deltaTime);

    /**
    * @brief Return if the window is still open
    */
        bool isWindowOpen();

    private:

    /**
    * @brief Add a View::Entity to the view
    */
        void addViewEntity(std::shared_ptr<Model::Entity> entity);

    private:
        std::unique_ptr<sf::RenderWindow> window;
        std::vector<std::shared_ptr<Entity>> entities;
    };

}


#endif //GRADIUS_VIEW_H
