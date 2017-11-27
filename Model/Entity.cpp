//
// Created by laurens on 11/18/17.
//

#include "Entity.h"

Model::Entity::Entity() {}

Model::Entity::Entity(float x, float y, float height, float width) : x(x), y(y), height(height), width(width) {
    this->destroyed = false;
}

float Model::Entity::getPositionX() const {
    return this->x;
}

float Model::Entity::getPositionY() const {
    return this->y;
}

void Model::Entity::updatePositionX(double newPositionX) {
    this->x = newPositionX;
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

bool Model::Entity::isDestroyed() const {
    return destroyed;
}

void Model::Entity::wrecked() {
    this->destroyed = true;
    this->notifyDestroyed();
}
