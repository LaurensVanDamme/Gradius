//
// Created by laurens on 11/18/17.
//

#include "Ship.h"

Model::Ship::Ship() {}

Model::Ship::Ship(double x, double y, float width, float height, float speed, unsigned int healt, float timePerShot)
        : MovingEntity(x, y, height, width, speed), healt(healt), bullettype(bullettype), timePerShot(timePerShot) {
    lastTimeShot = 0;
}

void Model::Ship::checkCoorX() {
    if (this->getPositionX() >= (4 - (this->getWidth() / 2))){
        this->updatePositionX(4 - (this->getWidth() / 2));
    } else if (this->getPositionX() <= (-4 + (this->getWidth() / 2))){
        this->updatePositionX(-4 + (this->getWidth() / 2));
    }
}

void Model::Ship::checkCoorY() {
    if (this->getPositionY() >= (3 - (this->getHeight() / 2))){
        this->updatePositionY(3 - (this->getHeight() / 2));
    } else if (this->getPositionY() <= (-3 + (this->getHeight() / 2))){
        this->updatePositionY(-3 + (this->getHeight() / 2));
    }
}

bool Model::Ship::canShoot(float time){
    if (time - lastTimeShot >= timePerShot){
        lastTimeShot = time;
        return true;
    } else {
        return false;
    }
}
