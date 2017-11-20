//
// Created by laurens on 11/18/17.
//

#include "Entity.h"
#include "MovingEntity.h"

MovingEntity::MovingEntity() {}

MovingEntity::MovingEntity(double x, double y, float height, float width, float speed) :
        Entity(x, y, height, width), speed(speed) {

}

void MovingEntity::moveUp(float deltaTime) {
    double newY = this->getPositionY() + (speed * deltaTime);
    if (newY > 3){
        this->updatePositionY(3.0);
    } else {
        this->updatePositionY(newY);
    }
}

void MovingEntity::moveDown(float deltaTime) {
    double newY = this->getPositionY() - (speed * deltaTime);
    if (newY < -3){
        this->updatePositionY(-3.0);
    } else {
        this->updatePositionY(newY);
    }
}

void MovingEntity::moveRight(float deltaTime) {
    double newX = this->getPositionX() + (speed * deltaTime);
    if (newX > 4){
        this->updatePositionX(4.0);
    } else {
        this->updatePositionX(newX);
    }
}

void MovingEntity::moveLeft(float deltaTime) {
    double newX = this->getPositionX() - (speed * deltaTime);
    if (newX < -4){
        this->updatePositionX(-4.0);
    } else {
        this->updatePositionX(newX);
    }
}
