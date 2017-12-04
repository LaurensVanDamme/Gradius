//
// Created by laurens on 11/18/17.
//

#include "Entity.h"
#include "../ObserverPattern/Events/UpdateX.h"
#include "../ObserverPattern/Events/UpdateY.h"
#include "../ObserverPattern/Events/Destroyed.h"

#include <iostream>

Model::Entity::Entity() {}

Model::Entity::Entity(float x, float y, float height, float width, float speed) : x(x), y(y), height(height),
                                                                                  width(width) {
    this->health = 1;
    this->destroyed = false;
}

float Model::Entity::getPositionX() const {
    return this->x;
}

float Model::Entity::getPositionY() const {
    return this->y;
}

float Model::Entity::getHeight() const {
    return height;
}

float Model::Entity::getWidth() const {
    return width;
}

float Model::Entity::getSpeed() const {
    return speed;
}

unsigned int Model::Entity::getHealth() const {
    return health;
}

bool Model::Entity::isDestroyed() const {
    return destroyed;
}

void Model::Entity::moveUp() {
    this->y = this->y + this->getSpeed();
    this->checkCoorY();
//    OP::Event::UpdateY event;
    auto event = std::make_shared<OP::Event::UpdateY>(OP::Event::UpdateY()); //  Create an update y event
    this->notify(event);
}

void Model::Entity::moveDown() {
    this->y = this->y - this->getSpeed();
    this->checkCoorY();
//    OP::Event::UpdateY event;
    auto event = std::make_shared<OP::Event::UpdateY>(OP::Event::UpdateY()); //  Create an update y event
    this->notify(event);
}

void Model::Entity::moveRight() {
    this->x = this->x + this->getSpeed();
    this->checkCoorX();
//    OP::Event::UpdateX event;
    auto event = std::make_shared<OP::Event::UpdateX>(OP::Event::UpdateX()); //  Create an update x event
    this->notify(event);
}

void Model::Entity::moveLeft() {
    this->x = this->x - this->getSpeed();
    this->checkCoorX();
//    OP::Event::UpdateX event;
    auto event = std::make_shared<OP::Event::UpdateX>(OP::Event::UpdateX()); //  Create an update x event
    this->notify(event);
}

void Model::Entity::hit(unsigned int damage) {
    // Reduce healt one at a time
    // (if damage > healt it will be set to a very large number if it's substracted in one time)
    for (unsigned int i = 0; i < damage; i++) {
        if ((health--) == 0) {
            this->wrecked();
            break;
        }
    }
}

bool Model::Entity::canBeHit(float time, bool hit) {
    return true;
}

void Model::Entity::wrecked() {
    this->destroyed = true;
//    OP::Event::Destroyed event;
    auto event = std::make_shared<OP::Event::Destroyed>(OP::Event::Destroyed()); //  Create a destroyed event
    this->notify(event);
}

void Model::Entity::checkCoorX() {
    if (this->x >= (4 + (this->getWidth() / 2))){
        this->wrecked();
    } else if (this->x <= (-4 - (this->getWidth() / 2))){
        this->wrecked();
    }
}

void Model::Entity::checkCoorY() {
    if (this->y >= (3 + (this->getHeight() / 2))){
        this->wrecked();
    } else if (this->y <= (-3 - (this->getHeight() / 2))){
        this->wrecked();
    }
}
