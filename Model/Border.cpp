//
// Created by laurens on 11/27/17.
//

#include "Border.h"
#include <limits>

Model::Border::Border(float x, float y, float height, float width) : Obstacle(x, y, height, width) {
    this->type = "Border";
    this->speed = 0.03f;
    this->health = std::numeric_limits<unsigned int>::infinity();
    this->damage = 2;
}

void Model::Border::checkCoorX() {
    // Make sure the entity can't live long outside the boundaries
    if (this->x >= (4 + this->getWidth())){
        this->wrecked();
    }
        // If the border is at the left end of the coordinate system, spawn at the right end of the coordinate system
    else if (this->x < (-4 - (this->getWidth() / 2))) {
        this->x = 4 + (this->getWidth() / 2);
    }
}
