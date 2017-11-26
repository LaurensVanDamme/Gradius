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
