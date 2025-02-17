//
// Created by laurens on 11/18/17.
//

#include "Ship.h"

Model::Ship::Ship(float x, float y, float width, float height, std::weak_ptr<World> &world)
        : Entity(x, y, height, width), world(world) {
    lastTimeShot = 0;
    lastTimeHit = 0;
}

bool Model::Ship::canShoot(float time){
    // If the difference in time is bigger than timePerShot the ship can shoot
    if (time - lastTimeShot >= timePerShot){
        lastTimeShot = time;
        return true;
    } else {
        return false;
    }
}
