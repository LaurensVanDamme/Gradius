//
// Created by laurens on 11/18/17.
//

#include "Entity.h"

Model::Entity::Entity() {}

Model::Entity::Entity(double x, double y, float height, float width) : x(x), y(y), height(height), width(width) {}

double Model::Entity::getPositionX() const {
    return this->x;
}

double Model::Entity::getPositionY() const {
    return this->y;
}

void Model::Entity::updatePositionX(double newPositionX) {
    if (newPositionX > 4){
        this->x = 4;
    } else if (newPositionX < -4){
        this->x = -4;
    } else {
        this->x = newPositionX;
    }
}

void Model::Entity::updatePositionY(double newPositionY) {
    if (newPositionY > 3){
        this->y = 3;
    } else if (newPositionY < -3){
        this->y = -3;
    } else {
        this->y = newPositionY;
    }
}

float Model::Entity::getHeight() const {
    return height;
}

float Model::Entity::getWidth() const {
    return width;
}
