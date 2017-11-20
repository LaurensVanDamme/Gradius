//
// Created by laurens on 11/18/17.
//

#include "Entity.h"
#include "MovingEntity.h"

#include <iostream>
using namespace std;

MovingEntity::MovingEntity() {}

MovingEntity::MovingEntity(double x, double y, float height, float width, float speed) :
        Entity(x, y, height, width), speed(speed) {

}

void MovingEntity::moveUp(float deltaTime) {
    this->updatePositionY(this->getPositionY() - (speed * deltaTime));
}

void MovingEntity::moveDown(float deltaTime) {
    this->updatePositionY(this->getPositionY() + (speed * deltaTime));
}

void MovingEntity::moveRight(float deltaTime) {
    this->updatePositionX(this->getPositionX() + (speed * deltaTime));
}

void MovingEntity::moveLeft(float deltaTime) {
    this->updatePositionX(this->getPositionX() - (speed * deltaTime));
}
