//
// Created by laurens on 11/18/17.
//

#include "Bullet.h"
#include <iostream>
using namespace std;

Model::Bullet::Bullet() {}

Model::Bullet::Bullet(double x, double y, float width, float height, float speed,
                      unsigned int damage) : MovingEntity(x, y, height, width, speed), damage(damage) {}

void Model::Bullet::checkCoorX() {
    if (this->getPositionX() > (4 + (this->getWidth() / 2))){
        this->wrecked();
        this->notifyDestroyed();
    } else if (this->getPositionX() < (-4 - (this->getWidth() / 2))){
        this->wrecked();
        this->notifyDestroyed();
    }
}

void Model::Bullet::checkCoorY() {
    if (this->getPositionY() > (3 - (this->getHeight() / 2))) {
        this->wrecked();
        this->notifyDestroyed();
    } else if (this->getPositionY() < (-3 + (this->getHeight() / 2))) {
        this->wrecked();
        this->notifyDestroyed();
    }
}
