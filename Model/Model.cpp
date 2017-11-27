//
// Created by laurens on 11/18/17.
//

#include "Model.h"
#include "Bullet.h"
#include "Ship.h"

#include <iostream>
using namespace std;

Model::Ship *Model::Model::getPlayer() {
    return player;
}

void Model::Model::setPlayer(double x, double y, float width, float height, float speed, unsigned int healt,
                             float timePerShot) {
    this->player = new Ship(x, y, width, height, speed, healt, timePerShot);
}

Model::Bullet* Model::Model::addBullet(unsigned int damage, float speed) {
    float width = this->player->getWidth() / 4;
    float height = this->player->getHeight() /4;
    float x = this->player->getPositionX() + (this->player->getWidth() / 2) + width;
    float y = this->player->getPositionY();
    auto bullet = new Bullet(x, y, width, height, damage, speed);
    this->scrollingEntities.push_back(bullet);
    return bullet;
}

void Model::Model::checkForDestroyed() {
    vector<ScrollingEntity*> toKeep;
    for (auto scrollingEntity: this->scrollingEntities) {
        if (!scrollingEntity->isDestroyed()){
            toKeep.push_back(scrollingEntity);
        } else {
            delete scrollingEntity;
        }
    }
    this->scrollingEntities = toKeep;
}

void Model::Model::updateWorld() {
    for (auto scrollingEntity: scrollingEntities){
        scrollingEntity->scroll();
    } // To add: Collitionhandling and aiShips
}
