//
// Created by laurens on 11/18/17.
//

#include "Ship.h"

Model::Ship::Ship() {}

Model::Ship::Ship(double x, double y, float width, float height, float speed, unsigned int healt, float timePerShot)
        : MovingEntity(x, y, height, width, speed), health(healt), timePerShot(timePerShot) {
    lastTimeShot = 0;
}

void Model::Ship::checkCoorX() {
    if (this->x >= (4 - (this->getWidth() / 2))){
        this->x = 4 - (this->getWidth() / 2);
    } else if (this->x <= (-4 + (this->getWidth() / 2))){
        this->x = -4 + (this->getWidth() / 2);
    }
}

void Model::Ship::checkCoorY() {
    if (this->y >= (3 - (this->getHeight() / 2))){
        this->y = 3 - (this->getHeight() / 2);
    } else if (this->y <= (-3 + (this->getHeight() / 2))){
        this->y = -3 + (this->getHeight() / 2);
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

bool Model::Ship::canBeHit(float time, bool hit) {
    if (time - lastTimeHit >= 1.5){
        if (hit) {
            lastTimeHit = time;
        }
        return true;
    } else {
        return false;
    }
}

unsigned int Model::Ship::getHealt() const {
    return health;
}

void Model::Ship::hit(unsigned int damage) {
    this->health -= damage;
    if (this->health == 0){
        this->wrecked();
    }
}
