//
// Created by laurens on 11/27/17.
//

#include "Obstacle.h"

Model::Obstacle::Obstacle() {}

Model::Obstacle::Obstacle(float x, float y, float height, float width)
        : Entity(x, y, height, width) {
    this->type = "Obstacle";
    this->speed = 0.03f;
    this->damage = 1;
}


void Model::Obstacle::update(float time) {
    this->moveLeft();
}


