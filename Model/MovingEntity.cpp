//
// Created by laurens on 11/18/17.
//

#include "Entity.h"
#include "MovingEntity.h"
#include "../ObserverPattern/Events/UpdateX.h"
#include "../ObserverPattern/Events/UpdateY.h"

#include <iostream>
using namespace std;

Model::MovingEntity::MovingEntity() {}

Model::MovingEntity::MovingEntity(double x, double y, float height, float width, float speed) :
        Entity(x, y, height, width), speed(speed) {

}

float Model::MovingEntity::getSpeed() const {
    return speed;
}

void Model::MovingEntity::moveUp() {
    this->y = this->y + this->getSpeed();
    this->checkCoorY();
//    OP::Event::UpdateY event;
    auto event = std::make_shared<OP::Event::UpdateY>(OP::Event::UpdateY()); //  Create a update y event
    this->notify(event);
}

void Model::MovingEntity::moveDown() {
    this->y = this->y - this->getSpeed();
    this->checkCoorY();
//    OP::Event::UpdateY event;
    auto event = std::make_shared<OP::Event::UpdateY>(OP::Event::UpdateY()); //  Create a update y event
    this->notify(event);
}

void Model::MovingEntity::moveRight() {
    this->x = this->x + this->getSpeed();
    this->checkCoorX();
//    OP::Event::UpdateX event;
    auto event = std::make_shared<OP::Event::UpdateX>(OP::Event::UpdateX()); //  Create a update x event
    this->notify(event);
}

void Model::MovingEntity::moveLeft() {
    this->x = this->x - this->getSpeed();
    this->checkCoorX();
//    OP::Event::UpdateX event;
    auto event = std::make_shared<OP::Event::UpdateX>(OP::Event::UpdateX()); //  Create a update x event
    this->notify(event);
}
