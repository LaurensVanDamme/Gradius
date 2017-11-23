//
// Created by laurens on 11/20/17.
//

#include "Entity.h"
#include "Transformation.h"
#include "../Model/Entity.h"

#include <iostream>
using namespace std;

View::Entity::Entity(Model::Entity* entity, std::string pathToTexture, sf::Vector2u imageCount = sf::Vector2u(0,0),
                             float switchTime = 0): entity(entity) {
    texture.loadFromFile(pathToTexture);
    if (switchTime != 0 and imageCount != sf::Vector2u(0,0)) {
        animation = Animation(&texture, imageCount, switchTime);
        animationEnabled = true;
        row = 0;
    } else {
        animationEnabled = false;
    }
    // Create a body for the player with a texture
    body.setTexture(&texture);
}

void View::Entity::update(Transformation* trans, float deltaTime) {
    if (animationEnabled) {
        animation.update(row, deltaTime);
        body.setTextureRect(animation.uvRect);
    }
    // Get the coordinates from the entity and transform them into pixels
    body.setSize(sf::Vector2f(trans->transformWidth(this->entity->getWidth()),
                              trans->transformHeight(this->entity->getHeight())));
    body.setOrigin(body.getSize() / 2.0f);
//    cout << "(" << this->entity->getPositionX() << ", " << this->entity->getPositionY() << ") == (" << trans->transformViaX(this->entity->getPositionX()) << ", " << trans->transformViaY(this->entity->getPositionY()) << ")\n";
    body.setPosition(trans->transformViaX(this->entity->getPositionX()),
                     trans->transformViaY(this->entity->getPositionY()));
}

void View::Entity::draw(sf::RenderWindow* window) {
    window->draw(body);
}
