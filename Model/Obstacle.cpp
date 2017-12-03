//
// Created by laurens on 11/27/17.
//

#include "Obstacle.h"
#include "../ObserverPattern/Events/UpdateX.h"

Model::Obstacle::Obstacle() {}

Model::Obstacle::Obstacle(double x, double y, float height, float width, unsigned int damage)
        : ScrollingEntity(x, y, height, width, damage) {}

void Model::Obstacle::scroll() {
    this->updatePositionX(this->getPositionX() - scrollSpeed);
    this->checkCoorX();
//    OP::Event::UpdateX event;
    auto event = std::make_shared<OP::Event::UpdateX>(OP::Event::UpdateX()); //  Create a update x event
    this->notify(event);
}

void Model::Obstacle::checkCoorX() {
    if (this->getPositionX() < (-4 - (this->getWidth() / 2))){
        this->wrecked();
    }
}
