//
// Created by laurens on 11/18/17.
//

#include "Entity.h"
#include "World.h"
#include "Border.h"
#include "AIFollower.h"
#include "AIShooter.h"
#include "../ObserverPattern/Event.h"

Model::World::World(){}

std::shared_ptr<Model::PlayerShip> Model::World::getPlayer() {
    return player;
}

void Model::World::setPlayer(float x, float y, float width, float height) {
    this->player = std::make_shared<PlayerShip>(x, y, width, height, shared_from_this());
    this->entities.push_back(this->player);
    OP::Event event(OP::Event::AddedEntity);
    event.addedEntity.entity = this->player;
    this->notify(event);
}

void Model::World::addBullet(float x, float y, float width, float height, bool AI) {
    auto bullet = std::make_shared<Bullet>(x, y, width, height, AI);
    this->entities.push_back(bullet);
    OP::Event event(OP::Event::AddedEntity);
    event.addedEntity.entity = bullet;
    this->notify(event);
}

void Model::World::addObstacle(float x, float y, float width, float height) {
    auto obstacle = std::make_shared<Obstacle>(x, y, width, height);
    this->entities.push_back(obstacle);
    OP::Event event(OP::Event::AddedEntity);
    event.addedEntity.entity = obstacle;
    this->notify(event);
}

void Model::World::addAIShooter(float x, float y, float width, float height) {
    auto AI = std::make_shared<AIShooter>(x, y, width, height, shared_from_this());
    this->entities.push_back(AI);
    OP::Event event(OP::Event::AddedEntity);
    event.addedEntity.entity = AI;
    this->notify(event);
}

void Model::World::addAIFollower(float x, float y, float width, float height) {
    auto AI = std::make_shared<Model::AIFollower>(x, y, width, height, shared_from_this());
    this->entities.push_back(AI);
    OP::Event event(OP::Event::AddedEntity);
    event.addedEntity.entity = AI;
    this->notify(event);
}

void Model::World::makeBorders() {
    float x = -4.125f;
    float y = 2.875f;
    unsigned int number = 0;
    while (true) {
        if (number == 33) {
            x = -4.125f;
            y = -2.875f;
        } else if (number == 66) {
            break;
        }
        auto border = std::make_shared<Border>(x, y, 0.25, 0.25);
        x += 0.25;
        number++;
        this->entities.push_back(border);
        OP::Event event(OP::Event::AddedEntity);
        event.addedEntity.entity = border;
        this->notify(event);
    }
}

bool Model::World::checkForDestroyed() {
    return !player->isDestroyed();
}

bool Model::World::collision(std::shared_ptr<Model::Entity> e1, std::shared_ptr<Model::Entity> e2){
    bool x = false;
    bool y = false;
    if (e1->getPositionX() > e2->getPositionX()){
        if ((e1->getPositionX() - (e1->getWidth() / 2) - 0.005 <
             (e2->getPositionX() + (e2->getWidth() / 2) - 0.005))){
            x = true;
        }
    } else {
        if ((e1->getPositionX() + (e1->getWidth() / 2) - 0.005 >
             (e2->getPositionX() - (e2->getWidth() / 2) - 0.005))){
            x = true;
        }
    }
    if (e1->getPositionY() > e2->getPositionY()){
        if ((e1->getPositionY() - (e1->getHeight() / 2) - 0.005 <
             (e2->getPositionY() + (e2->getHeight() / 2) - 0.005))){
            y = true;
        }
    } else {
        if ((e1->getPositionY() + (e1->getHeight() / 2) - 0.005 >
             (e2->getPositionY() - (e2->getHeight() / 2) - 0.005))){
            y = true;
        }
    }
    return x and y;
}

void Model::World::updateWorld(float totalTime) {
    // Update all entities
    for (auto entity: entities) {
        entity->update(totalTime);
    }

    // Check for collisions
    for (auto e1: entities){
        std::string type1 = e1->getType();
        for (auto e2: entities) {
            std::string type2 = e2->getType();
            if (type1 == "Bullet"){
                if (type2 == "Bullet" or type2 == "AIBullet" or type2 == "PlayerShip") {
                    continue;
                }
            } else if (type1 == "AIBullet"){
                if (type2.substr(0,2) == "AI" or type2 == "Bullet") {
                    continue;
                }
            } else if (type1.substr(0,2) == "AI"){
                if (type2.substr(0,2) == "AI") {
                    continue;
                }
            }
            if (e1 != e2 and this->collision(e1, e2)) {
                if (e1->canBeHit(totalTime, true)) {
                    e1->hit(e2->getDamage());
                }
            }
        }
    }

    // Delete all destroyed entities
    std::vector<std::shared_ptr<Entity>> toKeep;
    for (auto entity: this->entities) {
        if (!entity->isDestroyed())
            toKeep.push_back(entity);
    }
    this->entities = toKeep;

}

void Model::World::pushToCeilingQueue(unsigned int rows) {
    this->ceiling.push(rows);
}

void Model::World::pushToFloorQueue(unsigned int rows) {
    this->floor.push(rows);
}
