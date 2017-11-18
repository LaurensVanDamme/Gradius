//
// Created by laurens on 11/18/17.
//

#include <SFML/Graphics/RenderWindow.hpp>
#include "Controller.h"
#include "../View/View.h"
#include "../Model/Model.h"
#include "../Model/Ship.h"

Controller::Controller() {

}

Controller::Controller(Model *model, View *view): model(model), view(view) {

}

void Controller::checkForEvents(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->model->getPlayer()->moveLeft(deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->model->getPlayer()->moveRight(deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->model->getPlayer()->moveUp(deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->model->getPlayer()->moveDown(deltaTime);
    // kijken naar botsingen
}

