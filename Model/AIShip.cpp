//
// Created by laurens on 12/3/17.
//

#include "AIShip.h"

Model::AIShip::AIShip(double x, double y, float width, float height, float speed, unsigned int healt, float timePerShot)
        : Ship(x, y, width, height, speed, healt, timePerShot) {
    lastTimeUp = 0;
    lastTimeDown = 0;
    goingDown = false;
    goingUp = false;
    yAcceleration = 0.03;
    timesDown = 0;
    timesUp = 0;
}

bool Model::AIShip::moveAndAttack(float time) {
    this->moveLeft();
    unsigned int i = rand() % 50 + 1;
    if (goingDown and ((time - lastTimeDown) < 0.2)){
        this->speed += this->yAcceleration;
        this->moveDown();
        this->speed -= this->yAcceleration;
    } else if (goingUp and ((time - lastTimeUp) < 0.2)){
        this->speed += this->yAcceleration;
        this->moveUp();
        this->speed -= this->yAcceleration;
    } else {
        if (goingDown){
            goingDown = false;
        }
        if (goingUp){
            goingUp = false;
        }
        if (32 <= i and i < 40 and ((timesDown - 3) < timesUp)) {
            this->speed += this->yAcceleration;
            this->moveDown();
            this->speed -= this->yAcceleration;
            this->goingDown = true;
            lastTimeDown = time;
            timesDown++;
        }
        if (10 <= i and i < 18 and ((timesUp - 3) < timesDown)) {
            this->speed += this->yAcceleration;
            this->moveUp();
            this->speed -= this->yAcceleration;
            this->goingUp = true;
            lastTimeUp = time;
            timesUp++;
        }
    }
    return (i < 6 or i > 44) and this->canShoot(time);
}

void Model::AIShip::checkCoorX() {
    if (this->getPositionX() >= (4 + (this->getWidth() / 2))){
        this->updatePositionX(4 + (this->getWidth() / 2));
    } else if (this->getPositionX() <= (-4 - (this->getWidth() / 2))){
        this->wrecked();
    }
}

void Model::AIShip::checkCoorY() {
    if (this->getPositionY() >= (3 - (this->getHeight() / 2) - 0.30)){
        this->updatePositionY(3 - (this->getHeight() / 2) - 0.30);
    } else if (this->getPositionY() <= (-3 + (this->getHeight() / 2) + 0.30)){
        this->updatePositionY(-3 + (this->getHeight() / 2) - 0.30);
    }
}
