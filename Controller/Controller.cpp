//
// Created by laurens on 11/18/17.
//

// Test

#include "../View/Player.h"

// End Test

#include "Stopwatch.h"
#include "Controller.h"
//#include "../View/View.h"
//#include "../Model/Model.h"
#include "../Model/Ship.h"

#include <iostream>

Ctrl::Controller::Controller(const std::string jsonFile) {
    model = std::make_unique<Model::Model>(Model::Model());
    view = std::make_unique<View::View>(View::View(2100, 1400));
    this->makeBorders();

    //------------ start Test ------------//

    model->setPlayer(-3.5, 0, 0.88888, 0.66666, 0.08, 4, 0.25);
    view->addPlayer(model->getPlayer(), "../Textures/Night Raider sprites.png", sf::Vector2u(4,2), 0.15);

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
        if (this->model->getPlayer()->canShoot(Stopwatch::getInstance()->getTotalTime())) {
            this->view->addViewEntity(this->model->addBullet(1, 0.16), "../Textures/beam1.png");
        }
    }
}

void Ctrl::Controller::makeBorders() {
    std::shared_ptr<Model::Entity> border = this->model->addBorder();
    // As long as a border is added continue
    while(border){
        this->view->addViewEntity(border, "../Textures/rock.png");
        border = this->model->addBorder();
    }
}

void Ctrl::Controller::endGame() {
    model = nullptr;
    view = nullptr;
}



