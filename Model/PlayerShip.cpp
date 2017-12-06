//
// Created by laurens on 12/4/17.
//

#include "PlayerShip.h"
#include "Model.h"

Model::PlayerShip::PlayerShip() {}

Model::PlayerShip::PlayerShip(float x, float y, float width, float height, std::weak_ptr<Model> model):
        Ship(x, y, width, height, model) {
    this->type = "PlayerShip";
    this->speed = 0.08;
    this->health = 4;
    this->damage = 5;
    this->timePerShot = 0.25;
}

void Model::PlayerShip::update(float time) {

}

bool Model::PlayerShip::canBeHit(float time, bool hit) {
    if ((time - this->lastTimeHit) >= 1.5){
        if (hit) {
            this->lastTimeHit = time;
        }
        return true;
    } else {
        return false;
    }
}

void Model::PlayerShip::shoot(float time) {
    if (this->canShoot(time)){
        if (auto mod = model.lock()){
            mod->addBullet(this->x + (this->getWidth() / 2) + 0.2222f, this->y, 0.2222, 0.1666, false);
        }
    }
}

void Model::PlayerShip::checkCoorX() {
    if (this->x >= (4 - (this->getWidth() / 2))){
        this->x = 4 - (this->getWidth() / 2);
    } else if (this->x <= (-4 + (this->getWidth() / 2))){
        this->x = -4 + (this->getWidth() / 2);
    }
}

void Model::PlayerShip::checkCoorY() {
    if (this->y >= (3 - (this->getHeight() / 2))){
        this->y = 3 - (this->getHeight() / 2);
    } else if (this->y <= (-3 + (this->getHeight() / 2))){
        this->y = -3 + (this->getHeight() / 2);
    }
}
