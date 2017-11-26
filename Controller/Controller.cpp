//
// Created by laurens on 11/18/17.
//

// Test

#include "../View/Entity.h"
#include "../Model/Ship.h"

// End Test

#include "Stopwatch.h"
#include "Controller.h"
#include "../View/View.h"
#include "../Model/Model.h"

#include <iostream>
using namespace std;

Ctrl::Controller::Controller(const std::string jsonFile) {
    stopwatch = Stopwatch::getStopwatch();
    model = new Model::Model;
    view = new View::View(2100, 1400, model);

    //------------ start Test ------------//

    model->setPlayer(-3.5, 0, 0.88888, 0.66666, 0.08, 2);
    view->addViewEntity(model->getPlayer(), "../Textures/Night Raider sprites.png", sf::Vector2u(4,1), 0.15);

    //------------- End Test -------------//
}

void Ctrl::Controller::run(){
    // Let the program loop until shut down
    while (view->isWindowOpen())
    {
        sf::Event event;
        view->checkForEvents(event);
        if (stopwatch->updateAndCheck()) {
            view->updateView(stopwatch->getTotalTickTime());
            this->checkForEvents();
        }
    }
}

void Ctrl::Controller::checkForEvents() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->model->getPlayer()->moveLeft();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->model->getPlayer()->moveRight();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->model->getPlayer()->moveUp();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->model->getPlayer()->moveDown();
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
//        this->model->
    // kijken naar botsingen
}

