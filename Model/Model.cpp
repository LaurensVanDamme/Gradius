//
// Created by laurens on 11/18/17.
//

#include "Model.h"
#include "Bullet.h"
#include "Ship.h"
#include "Border.h"

#include <iostream>
using namespace std;

Model::Ship *Model::Model::getPlayer() {
    return player;
}

void Model::Model::setPlayer(double x, double y, float width, float height, float speed, unsigned int healt,
                             float timePerShot) {
    this->player = new Ship(x, y, width, height, speed, healt, timePerShot);
}

Model::ScrollingEntity* Model::Model::addBullet(unsigned int damage, float speed) {
    float width = this->player->getWidth() / 4;
    float height = this->player->getHeight() /4;
    float x = this->player->getPositionX() + (this->player->getWidth() / 2) + width;
    float y = this->player->getPositionY();
    auto bullet = new Bullet(x, y, width, height, damage, speed);
    this->scrollingEntities.push_back(bullet);
    return bullet;
}

Model::ScrollingEntity *Model::Model::addBorder() {
    static float x = -4;
    static float y = 2.875;
    static unsigned int number = 0;
    if (number == 33){
        x = -4;
        y = -2.875;
    } else if (number == 67){
        return nullptr;
    }
    auto border = new Border(x, y, 0.25, 0.25, 2);
    x += 0.25;
    number++;
    this->scrollingEntities.push_back(border);
    return border;
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
        if (player->getPositionX() > scrollingEntity->getPositionX()){
            if ((player->getPositionX() - (player->getWidth() / 2) <
                    (scrollingEntity->getPositionX() + (scrollingEntity->getWidth() / 2)))){
                player->hit();
            }
        } else {
            if ((player->getPositionX() + (player->getWidth() / 2) >
                 (scrollingEntity->getPositionX() - (scrollingEntity->getWidth() / 2)))){
                player->hit();
            }
        }
        if (player->getPositionY() > scrollingEntity->getPositionY()){
            if ((player->getPositionY() - (player->getHeight() / 2) <
                 (scrollingEntity->getPositionY() + (scrollingEntity->getHeight() / 2)))){
                player->hit();
            }
        } else {
            if ((player->getPositionY() + (player->getHeight() / 2) >
                 (scrollingEntity->getPositionY() - (scrollingEntity->getHeight() / 2)))){
                player->hit();
            }
        }
    }
    // To add: Collitionhandling and aiShips
}
