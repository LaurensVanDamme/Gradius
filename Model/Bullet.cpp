//
// Created by laurens on 11/18/17.
//

#include "Bullet.h"

Model::Bullet::Bullet(float x, float y, float width, float height, bool AI)
        : Entity(x, y, height, width), AI(AI) {
    if (this->AI){
        this->type = "AIBullet";
    } else {
        this->type = "Bullet";
    }
    this->speed = 0.16;
    this->health = 1;
    this->damage = 1;
}

void Model::Bullet::update(float time) {
    // If it's an AI bullet the bullet must go left, else it must go right
    if (this->AI){
        this->moveLeft();
    } else {
        this->moveRight();
    }
}

