//
// Created by laurens on 11/20/17.
//

#include "ViewEntity.h"
#include "Transformation.h"
#include "../Model/Entity.h"

ViewEntity::ViewEntity(Entity* entity, sf::Texture *texture, sf::Vector2u imageCount, float switchTime):
    animation(texture, imageCount, switchTime), entity(entity) {
    row = 0;
    // Create a body for the player with a texture
    body.setSize(sf::Vector2f(200, 300));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(600, 400);
    body.setTexture(texture);
}

void ViewEntity::update(Transformation* trans, float deltaTime) {
    animation.update(row, deltaTime);
    body.setTextureRect(animation.uvRect);
    // Get the coordinates from the entity and transform them into pixels
    body.setPosition(trans->transformViaX(this->entity->getPositionX()), trans->transformViaY(this->entity->getPositionY()));
}

void ViewEntity::draw(sf::RenderWindow* window) {
    window->draw(body);
}
