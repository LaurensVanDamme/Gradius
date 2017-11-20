//
// Created by laurens on 11/18/17.
//

#include "View.h"
#include "ViewEntity.h"


View::View() {

}

View::View(unsigned int windowWidth, unsigned int windowHeight, Model *model): model(model){
    window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Gradius - Main Menu");
    transformation = Transformation(windowWidth, windowHeight);
}

void View::updateView(float deltaTime) {
    window->clear(sf::Color(150, 150, 150));
    // Go over every entity in the view update it and draw it on the window
    for (auto entity: this->entities){
        entity->update(&transformation, deltaTime);
        entity->draw(window);
    }
    window->display();
}

void View::checkForEvents(sf::Event event) {
    while (window->pollEvent(event))
    {
        switch (event.type){
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::Resized:
                transformation.updateWindowSize(window->getSize().x, window->getSize().y);
                break;
        }
    }
}

bool View::isWindowOpen() {
    return window->isOpen();
}

View::~View() {
    for (auto entity: this->entities){
        delete entity;
    }
}
