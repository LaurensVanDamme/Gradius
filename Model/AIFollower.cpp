//
// Created by laurens on 12/6/17.
//

#include "AIFollower.h"
#include "World.h"

Model::AIFollower::AIFollower() {}

Model::AIFollower::AIFollower(float x, float y, float width, float height, const std::weak_ptr<Model::World> &world)
        : Ship(x, y, width, height, world) {
    this->type = "AIFollower";
    this->speed = 0.04 ;
    this->health = 1;
    this->damage = 1;
}

void Model::AIFollower::update(float time) {
    if (auto mod = this->world.lock()){
        if (mod->getPlayer()->getPositionX() < this->x){
            this->moveLeft();
        } else {
            this->moveRight();
        }
        if (mod->getPlayer()->getPositionY() < this->y){
            this->moveDown();
        } else {
            this->moveUp();
        }
    }
}

void Model::AIFollower::checkCoorY() {
    if (this->y >= (3 - (this->getHeight() / 2) - 0.30)){
        this->y = 3 - (this->getHeight() / 2) - 0.30f;
    } else if (this->y <= (-3 + (this->getHeight() / 2) + 0.30)){
        this->y = -3 + (this->getHeight() / 2) + 0.30f;
    }
}