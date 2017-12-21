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
    texture = std::make_shared<sf::Texture>(sf::Texture());
    texture->loadFromFile(pathToTexture);
    // Check if an animation has to be made
    if (switchTime != 0 and imageCount != sf::Vector2u(0,0)) {
        animation = Animation(texture, imageCount, switchTime);
        animationEnabled = true;
        row = 0;
    } else {
        animationEnabled = false;
    }
    // Create a body for the player with a texture and set it at the right position
    if(auto sub = subject.lock()) {  // Make a temporary shared pointer of the weak pointer
        body.setTexture(&*texture);
        if (auto s = std::dynamic_pointer_cast<Model::Entity>(sub)) {  // Cast the subject to a World Entity
            body.setSize(sf::Vector2f(Transformation::getInstance()->transformWidth(s->getWidth()),
                                      Transformation::getInstance()->transformHeight(s->getHeight())));
            body.setOrigin(body.getSize() / 2.0f);
            body.setPosition(Transformation::getInstance()->transformViaX(s->getPositionX()),
                             Transformation::getInstance()->transformViaY(s->getPositionY()));
        }
    }
}

void View::Entity::update(OP::Event& event) {
    // Check which type of event it is
    switch (event.type){
        case OP::Event::UpdateX:
            // Get the X coordinate from the entity and transform it into pixels
            body.setOrigin(body.getSize() / 2.0f);
            if (auto sub = subject.lock()) {  // Make a temporary shared pointer of the weak pointer
                if (auto s = std::dynamic_pointer_cast<Model::Entity>(sub)) {  // Cast the subject to a World Entity
                    body.setPosition(Transformation::getInstance()->transformViaX(s->getPositionX()),
                                     body.getPosition().y);
                }
            }
            break;
        case OP::Event::UpdateY:
            // Get the Y coordinate from the entity and transform it into pixels
            body.setOrigin(body.getSize() / 2.0f);
            if(auto sub = subject.lock()) {  // Make a temporary shared pointer of the weak pointer
                if (auto s = std::dynamic_pointer_cast<Model::Entity>(sub)) {  // Cast the subject to a World Entity
                    body.setPosition(body.getPosition().x, Transformation::getInstance()->transformViaY(s->getPositionY()));
                }
            }
            break;
        case OP::Event::Destroyed:
            this->destroyed = true;
    }
}

bool View::Entity::isDestroyed() const {
    return destroyed;
}

void View::Entity::draw(std::unique_ptr<sf::RenderWindow>& window, float deltaTime) {
    // Update the animation if it exists
    if (animationEnabled) {
        animation.update(row, deltaTime);
        body.setTextureRect(animation.getUvRect());
    }
    window->draw(body);
}
