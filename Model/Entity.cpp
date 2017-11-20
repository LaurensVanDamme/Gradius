//
// Created by laurens on 11/18/17.
//

#include "Entity.h"

Entity::Entity() {}

Entity::Entity(double x, double y, float height, float width) : x(x), y(y), height(height), width(width) {}

double Entity::getPositionX() const {
    return this->x;
}

double Entity::getPositionY() const {
    return this->y;
}

void Entity::updatePositionX(double newPositionX) {
    if (newPositionX > 4){
        this->x = 4;
    } else if (newPositionX < -4){
        this->x = -4;
    } else {
        this->x = newPositionX;
    }
}

void Entity::updatePositionY(double newPositionY) {
    if (newPositionY > 3){
        this->y = 3;
    } else if (newPositionY < -3){
        this->y = -3;
    } else {
        this->y = newPositionY;
    }
}

float Entity::getHeight() const {
    return height;
}

float Entity::getWidth() const {
    return width;
}
