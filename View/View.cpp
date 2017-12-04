//
// Created by laurens on 11/18/17.
//

#include "View.h"
#include "Entity.h"
#include "Player.h"
#include "../Model/Entity.h"
#include "../Model/Ship.h"
#include "Transformation.h"
#include "../ObserverPattern/Events/AddedEntity.h"

#include <iostream>


View::View::View() {

}

View::View::View(unsigned int windowWidth, unsigned int windowHeight){
    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(windowWidth, windowHeight), "Gradius");
    Transformation::getInstance()->updateWindowSize(windowWidth, windowHeight);
}

void View::View::addViewEntity(std::shared_ptr<Model::Entity> entity) {
    std::string pathToTexture = "../Textures/";
    sf::Vector2u imageCount(0,0);
    float switchTime = 0;
    if (entity->getType() == "PlayerShip"){
        if (auto ent = std::dynamic_pointer_cast<Model::Ship>(entity)) {
            auto ventity = std::make_shared<Player>(Player(ent, "../Textures/Night Raider sprites.png",
                                                           sf::Vector2u(4,2), 0.15));
            ent->attach(ventity);
            this->entities.push_back(ventity);
            return;
        }
    } else if (entity->getType() == "AIShip"){
        pathToTexture += "F5S3.png";
    } else if (entity->getType() == "Border"){
        pathToTexture += "rock.png";
    }
    auto ventity = std::make_shared<Entity>(Entity(entity, pathToTexture, imageCount, switchTime));
    entity->attach(ventity);
    this->entities.push_back(ventity);
}

//----------Tijdelijk----------//

sf::Text getFPS(sf::Font font) {
    static sf::Clock clock;
    float cTime = clock.getElapsedTime().asSeconds();
    clock.restart();
    int fps = std::round(1 / cTime);

    std::string str = "FPS: " + std::to_string(fps);
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setString(str);
    return text;
}

//-------einde tijdelijk-------//

void View::View::updateView(float deltaTime) {
    window->clear(sf::Color(150, 150, 150));
    // Go over every entity in the view and draw it on the window if it isn't destroyed
    std::vector<std::shared_ptr<Entity>> toKeep;
    for (auto entity: this->entities){
        if (!entity->isDestroyed()){
            entity->draw(window, deltaTime);
            toKeep.push_back(entity);
        }
    }
    this->entities = toKeep;
    //----------Tijdelijk----------//
    sf::Font font;
    font.loadFromFile("arial.ttf");
    window->draw(getFPS(font));
    //-------Einde tijdelijk-------//
    window->display();
}

void View::View::checkForEvents(sf::Event event) {
    while (window->pollEvent(event))
    {
        switch (event.type){
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::Resized:
            Transformation::getInstance()->updateWindowSize(window->getSize().x, window->getSize().y);
                break;
        }
    }
}

void View::View::update(std::shared_ptr<OP::Event::Event> event) {
    if (auto e = std::dynamic_pointer_cast<OP::Event::AddedEntity>(event)){
        // continue...
    }
}

bool View::View::isWindowOpen() {
    return window->isOpen();
}
