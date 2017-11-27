//
// Created by laurens on 11/27/17.
//

#include "Obstacle.h"

Model::Obstacle::Obstacle() {}

Model::Obstacle::Obstacle(double x, double y, float height, float width, unsigned int damage)
        : ScrollingEntity(x, y, height, width, damage) {}

void Model::Obstacle::scroll() {
    this->updatePositionX(this->getPositionX() - scrollSpeed);
    this->checkCoorX();
    this->notifyXCoor();
}

void Model::Obstacle::checkCoorX() {
    if (this->getPositionX() < (-4 - (this->getWidth() / 2))){
        this->wrecked();
    }
}
