//
// Created by laurens on 11/27/17.
//

#include "Obstacle.h"
#include <limits>

Model::Obstacle::Obstacle(float x, float y, float height, float width)
        : Entity(x, y, height, width) {
    this->type = "Obstacle";
    this->speed = 0.02f;
    this->health = std::numeric_limits<unsigned int>::infinity();
    this->damage = 1;
}


void Model::Obstacle::update(float time) {
    this->moveLeft();
}


