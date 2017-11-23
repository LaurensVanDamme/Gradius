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

void MovingEntity::moveUp() {
    this->updatePositionY(this->getPositionY() - speed);
}

void MovingEntity::moveDown() {
    this->updatePositionY(this->getPositionY() + speed);
}

void MovingEntity::moveRight() {
    this->updatePositionX(this->getPositionX() + speed);
}

void MovingEntity::moveLeft() {
    this->updatePositionX(this->getPositionX() - speed);
}
