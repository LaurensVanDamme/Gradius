//
// Created by laurens on 12/4/17.
//

#include "PlayerShip.h"

Model::PlayerShip::PlayerShip() {}

Model::PlayerShip::PlayerShip(float x, float y, float width, float height, unsigned int healt
                              ) : Ship(x, y, width, height, healt, 0.08) {
    timePerShot = 0.25;
}

const std::string &Model::PlayerShip::getType() const {
    return "PlayerShip";
}

unsigned int Model::PlayerShip::getDamage() const {
    return 5;
}

void Model::PlayerShip::update(float time) {

}

bool Model::PlayerShip::canBeHit(float time, bool hit) {
    if (time - lastTimeHit >= 1.5){
        if (hit) {
            lastTimeHit = time;
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