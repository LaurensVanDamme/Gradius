//
// Created by laurens on 11/27/17.
//

#include "Border.h"

Model::Border::Border() {}

Model::Border::Border(double x, double y, float height, float width) : Obstacle(x, y, height, width, 0.03) {}

const std::string &Model::Border::getType() const {
    return "Border";
}

unsigned int Model::Border::getDamage() const {
    return 2;
}

void Model::Border::checkCoorX() {
    if (this->x >= (4 + this->getWidth())){
        this->wrecked();
    } else if (this->x < (-4 - (this->getWidth() / 2))){
        this->x = 4 + (this->getWidth() / 2);
    }
}
