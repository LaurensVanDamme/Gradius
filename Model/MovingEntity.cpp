//
// Created by laurens on 11/18/17.
//

#include "Entity.h"
#include "MovingEntity.h"

#include <iostream>
using namespace std;

Model::MovingEntity::MovingEntity() {}

Model::MovingEntity::MovingEntity(double x, double y, float height, float width, float speed) :
        Entity(x, y, height, width), speed(speed) {

}

float Model::MovingEntity::getSpeed() const {
    return speed;
}

void Model::MovingEntity::moveUp() {
    this->updatePositionY(this->getPositionY() - this->getSpeed());
    this->checkCoorY();
    this->notifyYCoor();
}

void Model::MovingEntity::moveDown() {
    this->updatePositionY(this->getPositionY() + this->getSpeed());
    this->checkCoorY();
    this->notifyYCoor();
}

void Model::MovingEntity::moveRight() {
    this->updatePositionX(this->getPositionX() + this->getSpeed());
    this->checkCoorX();
    this->notifyXCoor();
}

void Model::MovingEntity::moveLeft() {
    this->updatePositionX(this->getPositionX() - this->getSpeed());
    this->checkCoorX();
    this->notifyXCoor();
}
