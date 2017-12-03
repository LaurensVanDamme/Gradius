//
// Created by laurens on 11/18/17.
//

#include "Entity.h"
#include "../ObserverPattern/Events/Destroyed.h"

#include <iostream>

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

void Model::Entity::updatePositionX(float newPositionX) {
    this->x = newPositionX;
}

void Model::Entity::updatePositionY(float newPositionY) {
    this->y = newPositionY;
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
//    OP::Event::Destroyed event;
    auto event = std::make_shared<OP::Event::Destroyed>(OP::Event::Destroyed()); //  Create a destroyed event
    this->notify(event);
}
