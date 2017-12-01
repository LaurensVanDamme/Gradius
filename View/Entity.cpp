//
// Created by laurens on 11/20/17.
//

#include "Entity.h"
#include "Transformation.h"
#include "../Model/Entity.h"

View::Entity::Entity() {}

View::Entity::Entity(std::weak_ptr<Model::Entity> entity, std::string pathToTexture, sf::Vector2u imageCount = sf::Vector2u(0,0),
                             float switchTime = 0): Observer(entity) {
    destroyed = false;
    texture.loadFromFile(pathToTexture);
    // Check if an animation has to be made
    if (switchTime != 0 and imageCount != sf::Vector2u(0,0)) {
        animation = Animation(texture, imageCount, switchTime);
        animationEnabled = true;
        row = 0;
    } else {
        animationEnabled = false;
    }
    // Create a body for the player with a texture and set it at the right position
    if(auto sub = subject.lock()) {
        Transformation *trans = Transformation::getInstance();
        body.setTexture(&texture);
        body.setSize(sf::Vector2f(trans->transformWidth(sub->getWidth()),
                                  trans->transformHeight(sub->getHeight())));
        body.setOrigin(body.getSize() / 2.0f);
        body.setPosition(trans->transformViaX(sub->getPositionX()),
                         trans->transformViaY(sub->getPositionY()));
    }
}

void View::Entity::updateXCoor() {
    // Get the X coordinate from the entity and transform it into pixels
    body.setOrigin(body.getSize() / 2.0f);
    if(auto sub = subject.lock()) {
        body.setPosition(Transformation::getInstance()->transformViaX(sub->getPositionX()), body.getPosition().y);
    }
}

void View::Entity::updateYCoor() {
    // Get the X coordinate from the entity and transform it into pixels
    body.setOrigin(body.getSize() / 2.0f);
    if(auto sub = subject.lock()) {
        body.setPosition(body.getPosition().x, Transformation::getInstance()->transformViaY(sub->getPositionY()));
    }
}

void View::Entity::updateDestroyed() {
    destroyed = true;
}

bool View::Entity::isDestroyed() const {
    return destroyed;
}

void View::Entity::draw(std::unique_ptr<sf::RenderWindow>& window, float deltaTime) {
    // Update the animation if it exists
    if (animationEnabled) {
        animation.update(row, deltaTime);
        body.setTextureRect(animation.uvRect);
    }
    window->draw(body);
}
