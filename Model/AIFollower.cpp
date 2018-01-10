//
// Created by laurens on 12/6/17.
//

#include "AIFollower.h"
#include "World.h"

Model::AIFollower::AIFollower(float x, float y, float width, float height, std::weak_ptr<Model::World> world)
        : Ship(x, y, width, height, world) {
    this->type = "AIFollower";
    this->speed = 0.04 ;
    this->health = 1;
    this->damage = 1;
}

void Model::AIFollower::update(float time) {
    // Make sure it follows the player
    if (auto mod = this->world.lock()){
        // If he can hit the player
        if (mod->getPlayer()->canBeHit(time, false)) {
            this->speed = 0.04; // Go slow
            // Move to the player
            if (mod->getPlayer()->getPositionX() < this->x) {
                this->moveLeft();
            } else {
                this->moveRight();
            }
            if (mod->getPlayer()->getPositionY() < this->y) {
                this->moveDown();
            } else {
                this->moveUp();
            }
        }
            // If he can't hit the player
        else {
            this->speed = 0.08; // Go fast
            // Move away from the player
            if (mod->getPlayer()->getPositionX() + 1 < this->x) {
                this->moveLeft();
            } else if (mod->getPlayer()->getPositionX() < this->x and this->x - mod->getPlayer()->getPositionX() < 3){
                this->moveRight();
            } if (mod->getPlayer()->getPositionX() - 1 > this->x) {
                this->moveRight();
            } else if (mod->getPlayer()->getPositionX() > this->x and this->x - mod->getPlayer()->getPositionX() < 3){
                this->moveLeft();
            }
        }
    }
}

void Model::AIFollower::checkCoorY() {
    // Make sure the entity can't live long outside the boundaries
    if (this->y >= (3 - (this->getHeight() / 2) - 0.30)){
        this->y = 3 - (this->getHeight() / 2) - 0.30f;
    } else if (this->y <= (-3 + (this->getHeight() / 2) + 0.30)){
        this->y = -3 + (this->getHeight() / 2) + 0.30f;
    }
}