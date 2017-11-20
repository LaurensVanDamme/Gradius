//
// Created by laurens on 11/18/17.
//

#include "Ship.h"

Ship::Ship() {}

Ship::Ship(double x, double y, float width, float height, float speed, unsigned int healt, Bullet *bullettype)
        : MovingEntity(x, y, height, width, speed), healt(healt), bullettype(bullettype) {}
