//
// Created by laurens on 11/27/17.
//

#include "Obstacle.h"
#include "../ObserverPattern/Events/UpdateX.h"

Model::Obstacle::Obstacle() {}

Model::Obstacle::Obstacle(float x, float y, float height, float width, float speed)
        : Entity(x, y, height, width, speed) {}

const std::string &Model::Obstacle::getType() const {
    return "Obstacle";
}

unsigned int Model::Obstacle::getDamage() const {
    return 1;
}

void Model::Obstacle::update(float time) {
    this->moveLeft();
}


