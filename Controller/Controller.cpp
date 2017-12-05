//
// Created by laurens on 11/18/17.
//

// Test

#include "../View/Player.h"

// End Test

#include "Stopwatch.h"
#include "Controller.h"


Ctrl::Controller::Controller(const std::string jsonFile) {
    model = std::make_shared<Model::Model>();
    view = std::make_shared<View::View>(2100, 1400, model);
    model->attach(view);
    model->addBorders();

    //------------ start Test ------------//

    model->setPlayer(-3.5f, 0, 0.88888, 0.66666);
//    view->addViewEntity(model->addAIShip(5, 0, 0.88888, 0.66666, 0.02, 3, 0.20), "../Textures/F5S3.png");

    //------------- End Test -------------//
}

void Ctrl::Controller::run(){
    // Let the program loop until shut down
    while (view->isWindowOpen())
    {
        sf::Event event;
        view->checkForEvents(event);
        // Check if it's time do make another frame
        if (Stopwatch::getInstance()->updateAndCheck()) {
            model->updateWorld(Stopwatch::getInstance()->getTotalTime());
            this->getUserInput();
            // Check if the player is destroyed, if so stop the game
            if (!model->checkForDestroyed()){
                this->endGame();
                break;
            }
            view->updateView(Stopwatch::getInstance()->getTotalFrameTime());
        }
    }
}

void Ctrl::Controller::getUserInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->model->getPlayer()->moveLeft();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->model->getPlayer()->moveRight();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->model->getPlayer()->moveUp();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->model->getPlayer()->moveDown();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        this->model->getPlayer()->shoot(Stopwatch::getInstance()->getTotalTime());
    }
}

void Ctrl::Controller::endGame() {
    model = nullptr;
    view = nullptr;
}



