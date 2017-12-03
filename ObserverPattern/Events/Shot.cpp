//
// Created by laurens on 12/3/17.
//

#include "Shot.h"

OP::Event::Shot::Shot() {}

OP::Event::Shot::Shot(float x, float y, bool AI) : x(x), y(y), AI(AI) {}

float OP::Event::Shot::getX() const {
    return x;
}

float OP::Event::Shot::getY() const {
    return y;
}

bool OP::Event::Shot::isAI() const {
    return AI;
}
