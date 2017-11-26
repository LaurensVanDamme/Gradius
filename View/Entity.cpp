//
// Created by laurens on 11/20/17.
//

#include "Entity.h"
#include "Transformation.h"
#include "../Model/Entity.h"

#include <iostream>
using namespace std;

View::Entity::Entity(Model::Entity* entity, std::string pathToTexture, sf::Vector2u imageCount = sf::Vector2u(0,0),
                             float switchTime = 0): Observer(entity) {
    this->destroyed = false;
    texture.loadFromFile(pathToTexture);
    // Check if an animation has to be made
    if (switchTime != 0 and imageCount != sf::Vector2u(0,0)) {
        animation = Animation(&texture, imageCount, switchTime);
        animationEnabled = true;
        row = 0;
    } else {
        animationEnabled = false;
    }
    // Create a body for the player with a texture and set it at the right position
    Transformation* trans = Transformation::getTransformation();
    body.setTexture(&texture);
    body.setSize(sf::Vector2f(trans->transformWidth(this->subject->getWidth()),
                              trans->transformHeight(this->subject->getHeight())));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(trans->transformViaX(this->subject->getPositionX()), trans->transformViaY(this->subject->getPositionY()));
}

void View::Entity::updateXCoor() {
    // Get the X coordinate from the entity and transform it into pixels
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(Transformation::getTransformation()->transformViaX(this->subject->getPositionX()), body.getPosition().y);
}

void View::Entity::updateYCoor() {
    // Get the X coordinate from the entity and transform it into pixels
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(body.getPosition().x, Transformation::getTransformation()->transformViaY(this->subject->getPositionY()));
}

void View::Entity::updateDestroyed() {
    this->destroyed = true;
}

bool View::Entity::isDestroyed() const {
    return destroyed;
}

void View::Entity::draw(sf::RenderWindow* window, float deltaTime) {
    if (animationEnabled) {
        animation.update(row, deltaTime);
        body.setTextureRect(animation.uvRect);
    }
    window->draw(body);
}
