//
// Created by laurens on 11/18/17.
//

#include "Bullet.h"


Model::Bullet::Bullet() {}

Model::Bullet::Bullet(float x, float y, float height, float width, bool AI)
        : Entity(x, y, height, width), AI(AI) {
    if (AI){
        type = "AIBullet";
    } else {
        type = "Bullet";
    }
    this->speed = 0.16;
    this->health = 1;
    this->damage = 1;
}

void Model::Bullet::update(float time) {
    if (AI){
        this->moveLeft();
    } else {
        this->moveRight();
    }
}

