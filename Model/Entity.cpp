//
// Created by laurens on 11/18/17.
//

#include "Entity.h"

double Entity::getPositionX() const {
    return this->x;
}

double Entity::getPositionY() const {
    return this->y;
}

void Entity::updatePositionX(double newPositionX) {
    this->x = newPositionX;
}

void Entity::updatePositionY(double newPositionY) {
    this->y = newPositionY;
}

float Entity::getHeight() const {
    return height;
}

float Entity::getWidth() const {
    return width;
}
