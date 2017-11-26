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

void Model::MovingEntity::moveUp() {
    this->updatePositionY(this->getPositionY() - speed);
    this->notifyYCoor();
}

void Model::MovingEntity::moveDown() {
    this->updatePositionY(this->getPositionY() + speed);
    this->notifyYCoor();
}

void Model::MovingEntity::moveRight() {
    this->updatePositionX(this->getPositionX() + speed);
    this->notifyXCoor();
}

void Model::MovingEntity::moveLeft() {
    this->updatePositionX(this->getPositionX() - speed);
    this->notifyXCoor();
}
