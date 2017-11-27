//
// Created by laurens on 11/18/17.
//

#include "ScrollingEntity.h"

Model::ScrollingEntity::ScrollingEntity() {}

Model::ScrollingEntity::ScrollingEntity(double x, double y, float height, float width,
                                        unsigned int damage) : Entity(x, y, height, width), damage(damage) {
    scrollSpeed = 0.06;
}

unsigned int Model::ScrollingEntity::getDamage() const {
    return damage;
}
