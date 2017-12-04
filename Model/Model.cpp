//
// Created by laurens on 11/18/17.
//

#include "Entity.h"
#include "Model.h"
#include "Border.h"

std::shared_ptr<Model::PlayerShip> Model::Model::getPlayer() {
    return player;
}

void Model::Model::setPlayer(float x, float y, float width, float height) {
    this->player = std::make_shared<PlayerShip>(PlayerShip(x, y, width, height));
}

//std::shared_ptr<Model::ScrollingEntity> Model::Model::addBullet(unsigned int damage, float speed) {
//    float width = this->player->getWidth() / 4;
//    float height = this->player->getHeight() /4;
//    float x = this->player->getPositionX() + (this->player->getWidth() / 2) + width;
//    float y = this->player->getPositionY();
//    auto bullet = std::make_shared<Bullet>(Bullet(x, y, width, height, damage, speed));
//    this->scrollingEntities.push_back(bullet);
//    return bullet;
//}
//
//std::shared_ptr<Model::ScrollingEntity> Model::Model::addAIBullet(unsigned int damage, float speed) {
//    float width = this->player->getWidth() / 4;
//    float height = this->player->getHeight() /4;
//    float x = this->player->getPositionX() + (this->player->getWidth() / 2) + width;
//    float y = this->player->getPositionY();
//    auto bullet = std::make_shared<Bullet>(Bullet(x, y, width, height, damage, speed));
//    this->scrollingEntities.push_back(bullet);
//    return bullet;
//}

std::shared_ptr<Model::Entity> Model::Model::addBorder() {
    static float x = -4;
    static float y = 2.875;
    static unsigned int number = 0;
    if (number == 33){
        x = -4;
        y = -2.875;
    } else if (number == 66){
        return nullptr;
    }
    auto border = std::make_shared<Border>(Border(x, y, 0.25, 0.25));
    x += 0.25;
    number++;
    this->scrollingEntities.push_back(border);
    return border;
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
    for (auto scrollingEntity: this->scrollingEntities) {
        if (!scrollingEntity->isDestroyed())
            toKeep.push_back(scrollingEntity);
    }
    this->scrollingEntities = toKeep;
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
    for (auto scrollingEntity: scrollingEntities){
        scrollingEntity->update(totalTime);
        if (collision(player, scrollingEntity)){
            if (player->canBeHit(totalTime)) {
                player->hit(scrollingEntity->getDamage());
            }
        }
    }
    for (auto AI: AIShips) {
        AI->update(totalTime);
    }
    // To add: Collitionhandling in een functie steken and aiShips, die kunnen dan ook gehit worden door een kogel van de speler
    // daardoor is die functie voor collition handig
}
