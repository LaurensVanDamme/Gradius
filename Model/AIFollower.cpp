//
// Created by laurens on 12/6/17.
//

#include "AIFollower.h"

Model::AIFollower::AIFollower() {}

Model::AIFollower::AIFollower(float x, float y, float width, float height, const std::weak_ptr<Model::World> &world)
        : Ship(x, y, width, height, world) {
    this->type = "AIFollower";
}

void Model::AIFollower::update(float time) {
    if (auto mod = this.)
}

void Model::AIFollower::checkCoorY() {
    if (this->y >= (3 - (this->getHeight() / 2) - 0.30)){
        this->y = 3 - (this->getHeight() / 2) - 0.30f;
    } else if (this->y <= (-3 + (this->getHeight() / 2) + 0.30)){
        this->y = -3 + (this->getHeight() / 2) + 0.30f;
    }
}