//
// Created by laurens on 12/4/17.
//

#include "PlayerShip.h"

Model::PlayerShip::PlayerShip() {}

Model::PlayerShip::PlayerShip(float x, float y, float width, float height) : Ship(x, y, width, height) {
    this->type = "PlayerShip";
    this->speed = 0.08;
    this->health = 4;
    this->damage = 5;
    this->timePerShot = 0.25;
}

void Model::PlayerShip::update(float time) {

}

bool Model::PlayerShip::canBeHit(float time, bool hit) {
    if ((time - this->lastTimeHit) >= 1.5){
        if (hit) {
            this->lastTimeHit = time;
        }
        return true;
    } else {
        return false;
    }
}

void Model::PlayerShip::checkCoorX() {
    if (this->x >= (4 - (this->getWidth() / 2))){
        this->x = 4 - (this->getWidth() / 2);
    } else if (this->x <= (-4 + (this->getWidth() / 2))){
        this->x = -4 + (this->getWidth() / 2);
    }
}

void Model::PlayerShip::checkCoorY() {
    if (this->y >= (3 - (this->getHeight() / 2))){
        this->y = 3 - (this->getHeight() / 2);
    } else if (this->y <= (-3 + (this->getHeight() / 2))){
        this->y = -3 + (this->getHeight() / 2);
    }
}