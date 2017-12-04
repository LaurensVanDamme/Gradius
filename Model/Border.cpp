//
// Created by laurens on 11/27/17.
//

#include "Border.h"

Model::Border::Border(double x, double y, float height, float width, unsigned int damage) : Obstacle(x, y, height,
                                                                                                     width, damage) {}
void Model::Border::checkCoorX() {
    if (this->x < (-4 - (this->getWidth() / 2))){
        this->x = 4 + (this->getWidth() / 2);
    }
}