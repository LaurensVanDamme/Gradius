//
// Created by laurens on 11/18/17.
//

#include "../json.hpp"
#include "Entity.h"
#include "World.h"
#include "Border.h"
#include "AIFollower.h"
#include "AIShooter.h"
#include "../ObserverPattern/Event.h"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

void Model::World::loadLevel(std::string pathToJson) {
    this->destroyAll();
    this->entities = {};
    this->makeBorders();
    this->player = std::make_shared<PlayerShip>(0, 0, 0.6, 0.4, shared_from_this());
    this->entities.push_back(this->player);
    OP::Event event(OP::Event::AddedEntity);
    event.addedEntity.entity = this->player;
    this->notify(event);


    std::ifstream file(pathToJson);
    json j;
    file >> j;
    for (unsigned int i = 0; i < j["Timestamps"].size(); i++) {
        std::vector<std::string> types;
        std::vector<std::vector<float>> numbers;
        try { // Check if the timestamp is correct
            if (j["Timestamps"][i]["Time"] < 0) {
                throw 001;
            }
            for (unsigned int k = 0; k < j["Timestamps"][i]["Spawnlist"].size(); k++) {
                try {  // Check if it is a complete entity
                    // Type
                    if (j["Timestamps"][i]["Spawnlist"][k]["Type"] != "Obstacle" and
                        j["Timestamps"][i]["Spawnlist"][k]["Type"] != "AIShooter" and
                        j["Timestamps"][i]["Spawnlist"][k]["Type"] != "AIFollower")
                        throw 101;
                    // Size of vector of numbers
                    if (j["Timestamps"][i]["Spawnlist"][k]["Numbers"].size() != 4)
                        throw 102;
                    // The X coordinate
                    if (j["Timestamps"][i]["Spawnlist"][k]["Numbers"][0] < -5 or
                        j["Timestamps"][i]["Spawnlist"][k]["Numbers"][0] > 6)
                        throw 103;
                    // The Y coordinate
                    if (j["Timestamps"][i]["Spawnlist"][k]["Numbers"][1] < -3 or
                        j["Timestamps"][i]["Spawnlist"][k]["Numbers"][1] > 3)
                        throw 104;
                    // The width
                    if (j["Timestamps"][i]["Spawnlist"][k]["Numbers"][2] < 0 or
                        j["Timestamps"][i]["Spawnlist"][k]["Numbers"][2] > 4)
                        throw 105;
                    // The height
                    if (j["Timestamps"][i]["Spawnlist"][k]["Numbers"][3] < 0 or
                        j["Timestamps"][i]["Spawnlist"][k]["Numbers"][3] > 4)
                        throw 106;
                    // If everything is correct add them
                    std::vector<float> num;
                    for (auto &l : j["Timestamps"][i]["Spawnlist"][k]["Numbers"]) {
                        num.push_back(l);
                    }
                    types.push_back(j["Timestamps"][i]["Spawnlist"][k]["Type"]);
                    numbers.push_back(num);
                } catch (int error) {
                    switch (error) {
                        case 101:
                            std::cerr << "READ-ERROR: The type of entity nr. " << k + 1 << " in timestamp nr. " << i + 1
                                      << " is unknown!" << std::endl;
                            break;
                        case 102:
                            std::cerr << "READ-ERROR: Entity nr. " << k + 1 << "in timestamp nr. " << i + 1
                                      << " isn't complete!" << std::endl;
                            break;
                        case 103:
                            std::cerr << "READ-ERROR: The X coordinate of entity nr. " << k + 1 << " in timestamp nr. "
                                      << i + 1 << " is too small or to big!" << std::endl;
                            break;
                        case 104:
                            std::cerr << "READ-ERROR: The Y coordinate of entity nr. " << k + 1 << " in timestamp nr. "
                                      << i + 1 << " is too small or to big!" << std::endl;
                            break;
                        case 105:
                            std::cerr << "READ-ERROR: The width of entity nr. " << k + 1 << " in timestamp nr. "
                                      << i + 1 << " is too small or to big!" << std::endl;
                            break;
                        case 106:
                            std::cerr << "READ-ERROR: The height of entity nr. " << k + 1 << " in timestamp nr. "
                                      << i + 1 << " is too small or to big!" << std::endl;
                            break;
                        default:
                            std::cerr << "READ-ERROR: Unknown error in entity nr. " << k + 1 << " in timestamp nr. "
                                      << i + 1 << "!" << std::endl;
                            break;
                    }
                }
            }
            level.push(std::make_shared<Timestamp>(j["Timestamps"][i]["Time"], types, numbers));
        } catch (int error) {
            switch (error) {
                case 001:
                    std::cerr << "READ-ERROR: Timestamp nr." << i + 1 << " was negative!" << std::endl;
                    break;
                default:
                    std::cerr << "READ-ERROR: Unknown error in timestamp nr. " << i + 1 << "!" << std::endl;
                    break;
            }
        }
    }
}

std::shared_ptr<Model::PlayerShip> Model::World::getPlayer() {
    return player;
}

void Model::World::addBullet(float x, float y, float width, float height, bool AI) {
    auto bullet = std::make_shared<Bullet>(x, y, width, height, AI);
    this->entities.push_back(bullet);
    OP::Event event(OP::Event::AddedEntity);
    event.addedEntity.entity = bullet;
    this->notify(event);
}

void Model::World::updateWorld(float totalTime) {
    // Update all entities
    for (auto entity: entities) {
        entity->update(totalTime);
    }

    // Check for collisions
    for (auto e1: entities) {
        std::string type1 = e1->getType();
        for (auto e2: entities) {
            std::string type2 = e2->getType();
            if (type1 == "Bullet") {
                if (type2 == "Bullet" or type2 == "AIBullet" or type2 == "PlayerShip") {
                    continue;
                }
            } else if (type1 == "AIBullet") {
                if (type2.substr(0, 2) == "AI" or type2 == "Bullet") {
                    continue;
                }
            } else if (type1.substr(0, 2) == "AI") {
                if (type2.substr(0, 2) == "AI" or type2 == "Obstacle") {
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

    // Load entities from the level
    if (!level.empty()) {
        if (level.front()->getTime() <= totalTime) {
            for (unsigned int i = 0; i < level.front()->getTypes().size(); i++) {
                std::shared_ptr<Entity> entity;
                if (level.front()->getTypes()[i] == "Obstacle") {
                    entity = std::make_shared<Obstacle>(level.front()->getNumbers()[i][0],
                                                        level.front()->getNumbers()[i][1],
                                                        level.front()->getNumbers()[i][2],
                                                        level.front()->getNumbers()[i][3]);
                } else if (level.front()->getTypes()[i] == "AIShooter") {
                    entity = std::make_shared<AIShooter>(level.front()->getNumbers()[i][0],
                                                         level.front()->getNumbers()[i][1],
                                                         level.front()->getNumbers()[i][2],
                                                         level.front()->getNumbers()[i][3], shared_from_this());
                } else if (level.front()->getTypes()[i] == "AIFollower") {
                    entity = std::make_shared<Model::AIFollower>(level.front()->getNumbers()[i][0],
                                                                 level.front()->getNumbers()[i][1],
                                                                 level.front()->getNumbers()[i][2],
                                                                 level.front()->getNumbers()[i][3], shared_from_this());
                }
                this->entities.push_back(entity);
                OP::Event event(OP::Event::AddedEntity);
                event.addedEntity.entity = entity;
                this->notify(event);
            }
            level.pop();
        }
    } else {
        if (!this->player->isDestroyed() and this->entities.size() == 67) {
            this->destroyAll();
            OP::Event event(OP::Event::Won);
            this->notify(event);
        }
    }
}

bool Model::World::checkForEnd() {
    if (player->isDestroyed()) {
        this->destroyAll();
        return true;
    } else return level.empty() and this->entities.size() == 67;
}

void Model::World::destroyAll() {
    for (auto e: this->entities) {
        e->wrecked();
    }
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

bool Model::World::collision(std::shared_ptr<Model::Entity> e1, std::shared_ptr<Model::Entity> e2) {
    bool x = false;
    bool y = false;
    if (e1->getPositionX() > e2->getPositionX()) {
        if ((e1->getPositionX() - (e1->getWidth() / 2) - 0.005 <
             (e2->getPositionX() + (e2->getWidth() / 2) - 0.005))) {
            x = true;
        }
    } else {
        if ((e1->getPositionX() + (e1->getWidth() / 2) - 0.005 >
             (e2->getPositionX() - (e2->getWidth() / 2) - 0.005))) {
            x = true;
        }
    }
    if (e1->getPositionY() > e2->getPositionY()) {
        if ((e1->getPositionY() - (e1->getHeight() / 2) - 0.005 <
             (e2->getPositionY() + (e2->getHeight() / 2) - 0.005))) {
            y = true;
        }
    } else {
        if ((e1->getPositionY() + (e1->getHeight() / 2) - 0.005 >
             (e2->getPositionY() - (e2->getHeight() / 2) - 0.005))) {
            y = true;
        }
    }
    return x and y;
}


void Model::World::pushToCeilingQueue(unsigned int rows) {
    this->ceiling.push(rows);
}

void Model::World::pushToFloorQueue(unsigned int rows) {
    this->floor.push(rows);
}
