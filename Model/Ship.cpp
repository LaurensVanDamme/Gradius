//
// Created by laurens on 11/18/17.
//

#include "Ship.h"

Model::Ship::Ship() {}

Model::Ship::Ship(float x, float y, float width, float height, unsigned int healt, float speed)
        : Entity(x, y, height, width, speed), health(healt) {
    lastTimeShot = 0;
}

bool Model::Ship::canShoot(float time){
    if (time - lastTimeShot >= timePerShot){
        lastTimeShot = time;
        return true;
    } else {
        return false;
    }
}
