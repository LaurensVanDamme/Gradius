//
// Created by laurens on 11/18/17.
//

#include "Ship.h"

Model::Ship::Ship() {}

Model::Ship::Ship(double x, double y, float width, float height, float speed, unsigned int healt, Bullet *bullettype)
        : MovingEntity(x, y, height, width, speed), healt(healt), bullettype(bullettype) {}
