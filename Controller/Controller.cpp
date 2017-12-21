//
// Created by laurens on 11/18/17.
//

/// Test

#include "../View/Player.h"

/// End Test

#include "Stopwatch.h"
#include "Controller.h"


Ctrl::Controller::Controller(const std::string jsonFile) {
    world = std::make_shared<Model::World>();
    view = std::make_shared<View::View>(2100, 1400, world);
    world->attach(view);
    world->makeBorders();

    ///------------ start Test ------------///

    world->setPlayer(0, 0, 0.6, 0.4);
    world->addAIShooter(4.2, 1.5, 0.4444, 0.3333);
    world->addAIShooter(3.8, 0, 0.4444, 0.3333);
    world->addAIShooter(4.4, -1.5f, 0.4444, 0.3333);
    world->addObstacle(2,1.5,0.5,0.5);
    world->addObstacle(2,0,0.5,0.5);
    world->addObstacle(2,-1.5f,0.5,0.5);

    ///------------- End Test -------------///
}

void Ctrl::Controller::run(){
    // Let the program loop until shut down
    bool yes = true;
    while (view->isWindowOpen())
    {
        sf::Event event;
        view->checkForEvents(event);
        // Check if it's time do make another frame
        if (Stopwatch::getInstance()->updateAndCheck()) {
            if (Stopwatch::getInstance()->getTotalTime() >= 9 and yes){
                world->addAIFollower(-2.3f,2,0.3,0.3);
                world->addAIFollower(2.7,1,0.3,0.3);
                world->addAIFollower(-3,0,0.3,0.3);
                world->addAIFollower(3.2,-1,0.3,0.3);
                world->addAIFollower(0,-2.5f,0.3,0.3);
                yes = false;
            }
            world->updateWorld(Stopwatch::getInstance()->getTotalTime());
            this->getUserInput();
            // Check if the player is destroyed, if so stop the game
            if (!world->checkForDestroyed()){
                this->endGame();
                break;
            }
            view->updateView(Stopwatch::getInstance()->getTotalFrameTime());
        }
    }
}

void Ctrl::Controller::getUserInput() {
    // Get the input from the user and update the model
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->world->getPlayer()->moveLeft();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->world->getPlayer()->moveRight();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->world->getPlayer()->moveUp();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->world->getPlayer()->moveDown();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        this->world->getPlayer()->shoot(Stopwatch::getInstance()->getTotalTime());
    }
}

void Ctrl::Controller::endGame() {
    world = nullptr;
    view = nullptr;
}



