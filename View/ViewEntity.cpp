//
// Created by laurens on 11/20/17.
//

#include "ViewEntity.h"
#include "Transformation.h"
#include "../Model/Entity.h"

ViewEntity::ViewEntity(Entity* entity, std::string pathToTexture, sf::Vector2u imageCount, float switchTime):
        entity(entity) {
    texture.loadFromFile(pathToTexture);
    animation = Animation(&texture, imageCount, switchTime);
    row = 0;
    // Create a body for the player with a texture
    body.setTexture(&texture);
}

void ViewEntity::update(Transformation* trans, float deltaTime) {
    animation.update(row, deltaTime);
    body.setTextureRect(animation.uvRect);
    // Get the coordinates from the entity and transform them into pixels
    body.setSize(sf::Vector2f(trans->transformWidth(this->entity->getWidth()), trans->transformHeight(this->entity->getHeight())));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(trans->transformViaX(this->entity->getPositionX()), trans->transformViaY(this->entity->getPositionY()));
}

void ViewEntity::draw(sf::RenderWindow* window) {
    window->draw(body);
}
