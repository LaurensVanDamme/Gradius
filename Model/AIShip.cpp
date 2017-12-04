//
// Created by laurens on 12/3/17.
//

#include "AIShip.h"

Model::AIShip::AIShip() {

}

Model::AIShip::AIShip(float x, float y, float width, float height)
        : Ship(x, y, width, height) {
    this->type = "AIShip";
    this->speed = 0.02;
    this->health = 2;
    this->damage = 1;

    // AI stuff
    this->lastTimeUp = 0;
    this->lastTimeDown = 0;
    this->goingDown = false;
    this->goingUp = false;
    this->yAcceleration = 0.03;
    this->timesDown = 0;
    this->timesUp = 0;
}


void Model::AIShip::update(float time) {
    this->moveLeft();
    unsigned int i = rand() % 50 + 1;
//    if (goingDown and ((time - lastTimeDown) < 0.2)){
//        this->speed += this->yAcceleration;
//        this->moveDown();
//        this->speed -= this->yAcceleration;
//    } else if (goingUp and ((time - lastTimeUp) < 0.2)){
//        this->speed += this->yAcceleration;
//        this->moveUp();
//        this->speed -= this->yAcceleration;
//    } else {
//        if (goingDown){
//            goingDown = false;
//        }
//        if (goingUp){
//            goingUp = false;
//        }
//        if (32 <= i and i < 40 and ((timesDown - 3) < timesUp)) {
//            this->speed += this->yAcceleration;
//            this->moveDown();
//            this->speed -= this->yAcceleration;
//            this->goingDown = true;
//            lastTimeDown = time;
//            timesDown++;
//        }
//        if (10 <= i and i < 18 and ((timesUp - 3) < timesDown)) {
//            this->speed += this->yAcceleration;
//            this->moveUp();
//            this->speed -= this->yAcceleration;
//            this->goingUp = true;
//            lastTimeUp = time;
//            timesUp++;
//        }
//    }
    bool shoot = (i < 6 or i > 44) and this->canShoot(time);
}

void Model::AIShip::checkCoorX() {
    if (this->x >= (4 + (this->getWidth() / 2))){
        this->x = 4 + (this->getWidth() / 2);
    } else if (this->x <= (-4 - (this->getWidth() / 2))){
        this->wrecked();
    }
}

void Model::AIShip::checkCoorY() {
    if (this->y >= (3 - (this->getHeight() / 2) - 0.30)){
        this->y = 3 - (this->getHeight() / 2) - 0.30f;
    } else if (this->y <= (-3 + (this->getHeight() / 2) + 0.30)){
        this->y = -3 + (this->getHeight() / 2) - 0.30f;
    }
}