//
// Created by laurens on 11/18/17.
//

/// Test

#include "../View/Player.h"

/// End Test

#include "Stopwatch.h"
#include "Controller.h"


Ctrl::Controller::Controller() {
    gameEnd = false;
    exit = false;
    world = std::make_shared<Model::World>();
    view = std::make_shared<View::View>(2100, 1400, world);
    world->attach(view);
    world->loadLevel("../Levels/Level 1.json");
}

void Ctrl::Controller::run(){
    // Let the program loop until shut down
    while (!exit and view->isWindowOpen())
    {
        sf::Event event;
        view->checkForEvents(event);
        // Check if it's time to make another frame
        if (Stopwatch::getInstance()->updateAndCheck()) {
            view->updateView(Stopwatch::getInstance()->getTotalFrameTime());
            // As long as the game hasn't ended update the world
            if (!gameEnd) {
                world->updateWorld(Stopwatch::getInstance()->getTotalTime());
                // Check if the player is destroyed, if so stop the game
                if (world->checkForEnd()) {
                    this->gameEnd = true;
                    world = nullptr;
                }
            }
            this->getUserInput();
        }
    }
}

void Ctrl::Controller::getUserInput() {
    // Get the input from the user and update the model
    if (!gameEnd) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            this->world->getPlayer()->moveLeft();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            this->world->getPlayer()->moveRight();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) or sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            this->world->getPlayer()->moveUp();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) or sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            this->world->getPlayer()->moveDown();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            this->world->getPlayer()->shoot(Stopwatch::getInstance()->getTotalTime());
        }
    } else {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            this->endGame();
            this->exit = true;
        }
    }
}

void Ctrl::Controller::endGame() {
    view = nullptr;
}



