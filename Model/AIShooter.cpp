//
// Created by laurens on 12/3/17.
//

#include "AIShooter.h"
#include "World.h"

Model::AIShooter::AIShooter(float x, float y, float width, float height, std::weak_ptr<World> world)
        : Ship(x, y, width, height, world) {
    this->type = "AIShooter";
    this->speed = 0.02;
    this->health = 1;
    this->damage = 1;
    this->timePerShot = 0.10;

    // AI stuff
    this->lastTimeUp = 0;
    this->lastTimeDown = 0;
    this->goingDown = false;
    this->goingUp = false;
    this->yAcceleration = 0.03;
    this->timesDown = 0;
    this->timesUp = 0;
}


void Model::AIShooter::update(float time) {
    this->moveLeft();
    // Generate a random number to move up, move down or shoot
    auto i = static_cast<unsigned int>(rand() % 50 + 1);
    // Make sure if he goes down, that he keeps doing that for an amount of time
    if (goingDown and ((time - lastTimeDown) < 0.2)){
        this->speed += this->yAcceleration;
        this->moveDown();
        this->speed -= this->yAcceleration;
    }
        // Make sure if he goes up, that he keeps doing that for an amount of time
    else if (goingUp and ((time - lastTimeUp) < 0.2)) {
        this->speed += this->yAcceleration;
        this->moveUp();
        this->speed -= this->yAcceleration;
    } else {
        // Reset the variables
        if (goingDown){
            goingDown = false;
        }
        if (goingUp){
            goingUp = false;
        }
        // Let it go up or down with the random number
        if (32 <= i and i < 40 and ((timesDown - 3) < timesUp)) {
            this->speed += this->yAcceleration; // Accelerate its y speed
            this->moveDown();
            this->speed -= this->yAcceleration;
            this->goingDown = true;
            lastTimeDown = time;
            timesDown++;
        }
        if (10 <= i and i < 18 and ((timesUp - 3) < timesDown)) {
            this->speed += this->yAcceleration;
            this->moveUp();
            this->speed -= this->yAcceleration;
            this->goingUp = true;
            lastTimeUp = time;
            timesUp++;
        }
    }
    // See if it has to shoot with the random number
    if ((i < 3 or i > 48) and this->canShoot(time)) {
        if (auto mod = this->world.lock()){
            mod->addBullet(this->x - (this->getWidth() / 2) - 0.18f, this->y, 0.15, 0.10, true);
        }
    }
}

void Model::AIShooter::checkCoorX() {
    // Make sure the entity can't live long outside the boundaries
    if (this->x >= (6 + (this->getWidth() / 2))) {
        this->wrecked();
    } else
    if (this->x <= (-4 - (this->getWidth() / 2))){
        this->wrecked();
    }
}

void Model::AIShooter::checkCoorY() {
    // Make sure the entity can't live long outside the boundaries
    if (this->y >= (3 - (this->getHeight() / 2) - 0.30)){
        this->y = 3 - (this->getHeight() / 2) - 0.30f;
    } else if (this->y <= (-3 + (this->getHeight() / 2) + 0.30)){
        this->y = -3 + (this->getHeight() / 2) + 0.30f;
    }
}