//
// Created by laurens on 11/18/17.
//

#include "Bullet.h"
#include "../ObserverPattern/Events/UpdateX.h"
#include <iostream>
using namespace std;

Model::Bullet::Bullet() {}

Model::Bullet::Bullet(double x, double y, float height, float width, unsigned int damage, float speed)
        : ScrollingEntity(x, y, height, width, damage) {
    this->scrollSpeed = speed;
}

void Model::Bullet::scroll() {
    this->updatePositionX(this->getPositionX() + scrollSpeed);
    this->checkCoorX();
//    OP::Event::UpdateX event;
    auto event = std::make_shared<OP::Event::UpdateX>(OP::Event::UpdateX()); //  Create a update x event
    this->notify(event);
}

void Model::Bullet::checkCoorX() {
    if (this->getPositionX() > (4 + (this->getWidth() / 2))){
        this->wrecked();
    } else if (this->getPositionX() < (-4 - (this->getWidth() / 2))){
        this->wrecked();
    }
}

