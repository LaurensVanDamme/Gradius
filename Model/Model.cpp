//
// Created by laurens on 11/18/17.
//

#include "Model.h"
#include "Bullet.h"
#include "Ship.h"

Model::Ship *Model::Model::getPlayer() {
    return player;
}

void Model::Model::setPlayer(double x, double y, float width, float height, float speed, unsigned int healt,
                             Bullet *bullettype) {
    this->player = new Ship(x, y, width, height, speed, healt, bullettype);
}

void Model::Model::addBullet(float speed, float timePerShot, unsigned int damage) {
    float width = this->player->getWidth() / 4;
    float height = this->player->getHeight() /4;
    float x = this->player->getPositionX() + this->player->getWidth() + width;
    float y = this->player->getPositionY();
    Bullet* bullet = new Bullet(x, y, width, height, speed, timePerShot, damage);
    this->bullets.push_back(bullet);
}

void Model::Model::checkForDestroyed() {
    vector<Bullet*> toKeep;
    for (auto bullet: this->bullets) {
        if (!bullet->isDestroyed()){
            toKeep.push_back(bullet);
        } else {
            delete bullet;
        }
    }
    this->bullets = toKeep;
}

Model::Bullet *Model::Model::getLastBullet() const {
    return bullets.back();
}
