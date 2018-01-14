//
// Created by laurens on 11/18/17.
//

#include <iostream>
#include "Stopwatch.h"
#include "Controller.h"


Ctrl::Controller::Controller() {
    // Give the player the option to chose which level he/she wants to play
    std::string pathToLevel{"../Levels/"};
    std::cout << "Which level do you want to play?\n- Test\n- 1\n- 2" << std::endl;
    while (true){ // Mini Command Line Interface
        std::string level;
        std::cin >> level;
        std::transform(level.begin(), level.end(), level.begin(), ::tolower);
        if (level == "test"){
            pathToLevel += "Test Level.json";
            break;
        } else if (level == "1"){
            pathToLevel += "Level 1.json";
            break;
        } else if (level == "2"){
            pathToLevel += "Level 2.json";
            break;
        } else {
            std::cout << "Unknown level, please try again..." << std::endl;
        }
    }
    gameEnd = false;
    exit = false;
    world = std::make_shared<Model::World>();
    view = std::make_shared<View::View>(2100, 1400, world);
    world->attach(view);
    world->loadLevel(pathToLevel);
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



