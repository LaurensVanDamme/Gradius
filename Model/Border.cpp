//
// Created by laurens on 11/27/17.
//

#include "Border.h"

void Model::Border::checkCoorX() {
    if (this->getPositionX() < (-4 - (this->getWidth() / 2))){
        this->updatePositionX(4 + (this->getWidth() / 2));
    }
}

Model::Border::Border(double x, double y, float height, float width, unsigned int damage) : Obstacle(x, y, height,
                                                                                                     width, damage) {}
