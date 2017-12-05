//
// Created by laurens on 11/18/17.
//

#include "Entity.h"
#include "Model.h"
#include "Border.h"
#include "../ObserverPattern/Event.h"

std::shared_ptr<Model::PlayerShip> Model::Model::getPlayer() {
    return player;
}

void Model::Model::setPlayer(float x, float y, float width, float height) {
    this->player = std::make_shared<PlayerShip>(x, y, width, height, shared_from_this());
    OP::Event event(OP::Event::AddedEntity);
    event.addedEntity.entity = this->player;
    this->notify(event);
}

void Model::Model::addBorders() {
    float x = -4;
    float y = 2.875;
    unsigned int number = 0;
    while (true) {
        if (number == 33) {
            x = -4;
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

void Model::Model::addBullet(float x, float y, float width, float height, bool AI) {
    auto bullet = std::make_shared<Bullet>(x, y, width, height, AI);
    this->entities.push_back(bullet);
    OP::Event event(OP::Event::AddedEntity);
    event.addedEntity.entity = bullet;  // Problem here...
    this->notify(event);
}

//std::shared_ptr<Model::AIShip>
//Model::Model::addAIShip(double x, double y, float width, float height, float speed, unsigned int healt,
//                        float timePerShot) {
//    auto AI = std::make_shared<AIShip>(AIShip(x, y, width, height, speed, healt, timePerShot));
//    this->AIShips.push_back(AI);
//    return AI;
//}

bool Model::Model::checkForDestroyed() {
    if (player->isDestroyed()){
        return false;
    }
    std::vector<std::shared_ptr<Entity>> toKeep;
    for (auto scrollingEntity: this->entities) {
        if (!scrollingEntity->isDestroyed())
            toKeep.push_back(scrollingEntity);
    }
    this->entities = toKeep;
    return true;
}

bool collision(std::shared_ptr<Model::Entity> e1, std::shared_ptr<Model::Entity> e2){
    bool x = false;
    bool y = false;
    if (e1->getPositionX() > e2->getPositionX()){
        if ((e1->getPositionX() - (e1->getWidth() / 2) <
             (e2->getPositionX() + (e2->getWidth() / 2)))){
            x = true;
        }
    } else {
        if ((e1->getPositionX() + (e1->getWidth() / 2) >
             (e2->getPositionX() - (e2->getWidth() / 2)))){
            x = true;
        }
    }
    if (e1->getPositionY() > e2->getPositionY()){
        if ((e1->getPositionY() - (e1->getHeight() / 2) <
             (e2->getPositionY() + (e2->getHeight() / 2)))){
            y = true;
        }
    } else {
        if ((e1->getPositionY() + (e1->getHeight() / 2) >
             (e2->getPositionY() - (e2->getHeight() / 2)))){
            y = true;
        }
    }
    return x and y;
}

void Model::Model::updateWorld(float totalTime) {
    for (auto entity: entities){
        entity->update(totalTime);
        if (collision(player, entity)){
            if (player->canBeHit(totalTime)) {
                player->hit(entity->getDamage());
            }
        }
    }
    // To add: Collitionhandling in een functie steken and aiShips, die kunnen dan ook gehit worden door een kogel van de speler
    // daardoor is die functie voor collition handig
}
