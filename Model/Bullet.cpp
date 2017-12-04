//
// Created by laurens on 11/18/17.
//

#include "Bullet.h"
#include "../ObserverPattern/Events/UpdateX.h"
#include <iostream>
using namespace std;

Model::Bullet::Bullet() {}

Model::Bullet::Bullet(float x, float y, float height, float width, float speed, bool AI)
        : Entity(x, y, height, width, speed), AI(AI) {}

const std::string &Model::Bullet::getType() const {
    if (AI){
        return "AIBullet";
    } else {
        return "Bullet";
    }
}

unsigned int Model::Bullet::getDamage() const {
    return 1;
}

void Model::Bullet::update(float time) {
    if (AI){
        this->moveLeft();
    } else {
        this->moveRight();
    }
}

