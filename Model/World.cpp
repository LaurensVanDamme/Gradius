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
    // Destroy everything to make sure there is nothing left in the world
    this->destroyAll();
    this->entities = {};
    // Create everything to start the game
    this->makeBorders();
    this->player = std::make_shared<PlayerShip>(0, 0, 0.6, 0.4, shared_from_this()); // Create a new playership entity
    // Notify the observers that there is a new entity in the world
    this->entities.push_back(this->player);
    OP::Event event(OP::Event::AddedEntity);
    event.addedEntity.entity = this->player;
    this->notify(event);

    // Start reading in the level via a json file
    std::ifstream file(pathToJson);
    json j;
    file >> j;
    // Go over every timestamp in the level
    for (unsigned int i = 0; i < j["Timestamps"].size(); i++) {
        std::vector<std::string> types;
        std::vector<std::vector<float>> numbers;
        try { // Check if the timestamp is correct
            if (j["Timestamps"][i]["Time"] < 0) {
                throw 001;
            }
            // Go every entity in the level
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
                    // If everything is correct add them to the timestamp
                    std::vector<float> num;
                    for (auto &l : j["Timestamps"][i]["Spawnlist"][k]["Numbers"]) {
                        num.push_back(l);
                    }
                    types.push_back(j["Timestamps"][i]["Spawnlist"][k]["Type"]);
                    numbers.push_back(num);
                }
                    // Catch the error if there is one and give the right error message, then continue to the next entity
                catch (int error) {
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
            // If everything in the timestamp has been checked add the timestamp to the level
            level.push(std::make_shared<Timestamp>(j["Timestamps"][i]["Time"], types, numbers));
        }
            // Catch the error if there is one and give the right error message, then continue to the next timestamp
        catch (int error) {
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
    // Create a new bullet entity
    auto bullet = std::make_shared<Bullet>(x, y, width, height, AI);
    // Notify the observers that there is an new entity in the world
    this->entities.push_back(bullet);
    OP::Event event(OP::Event::AddedEntity);
    event.addedEntity.entity = bullet;
    this->notify(event);
}

void Model::World::updateWorld(float totalTime) {
    // Update all entities in the world
    for (auto &entity: entities) {
        entity->update(totalTime);
    }

    // Check for collision between the entities
    for (auto &e1: entities) {
        std::string type1 = e1->getType();
        for (auto &e2: entities) {
            std::string type2 = e2->getType();
            // Ignore special combinations
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
            // Check for collision
            if (e1 != e2 and this->collision(e1, e2)) {
                if (e1->canBeHit(totalTime, true)) {
                    e1->hit(e2->getDamage());
                }
            }
        }
    }

    // Delete all destroyed entities
    std::vector<std::shared_ptr<Entity>> toKeep;
    for (auto &entity: this->entities) {
        if (!entity->isDestroyed())
            toKeep.push_back(entity);
    }
    this->entities = toKeep;

    // Load entities from the level
    if (!level.empty()) { // Check if the queue isn't empty
        if (level.front()->getTime() <= totalTime) { // Check if the next timestamp can be added to the world
            // Add every entitie from the timestamp
            for (unsigned int i = 0; i < level.front()->getTypes().size(); i++) {
                std::shared_ptr<Entity> entity;
                // Check which type the entity has and create a new one
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
                // Add the new entity and notify the observers that there is a new entity in the world
                this->entities.push_back(entity);
                OP::Event event(OP::Event::AddedEntity);
                event.addedEntity.entity = entity;
                this->notify(event);
            }
            // Pop the timestamp from the queue
            level.pop();
        }
    }
        // If the queue is empty and the player is alive and there are exact 67 entities
        // (66 rocks on the top and bottom and the playership) norify the observers that the player has won
    else {
        if (!this->player->isDestroyed() and this->entities.size() == 67) {
            this->destroyAll();
            OP::Event event(OP::Event::Won);
            this->notify(event);
        }
    }
}

bool Model::World::checkForEnd() {
    // Check if the playership is destroyed or if the game has been won
    if (player->isDestroyed()) {
        this->destroyAll();
        return true;
    } else return level.empty() and this->entities.size() == 67;
}

void Model::World::destroyAll() {
    // Go over every entity and destroy it
    for (auto &e: this->entities) {
        e->wrecked();
    }
}

void Model::World::makeBorders() {
    // Initialize the spawn position of the first rock
    float x = -4.125f;
    float y = 2.875f;
    unsigned int number = 0;
    while (true) {
        // If there are 33 go to the bottom
        if (number == 33) {
            x = -4.125f;
            y = -2.875f;
        }
            // If there are 66, all rocks have been added
        else if (number == 66) {
            break;
        }
        // Create a new border entity
        auto border = std::make_shared<Border>(x, y, 0.25, 0.25);
        // Notify the observers that there is a new entity
        this->entities.push_back(border);
        OP::Event event(OP::Event::AddedEntity);
        event.addedEntity.entity = border;
        this->notify(event);
        // Move the spawn location a little bit to the right
        x += 0.25;
        number++;
    }
}

bool Model::World::collision(std::shared_ptr<Model::Entity> e1, std::shared_ptr<Model::Entity> e2) {
    bool x = false;
    bool y = false;
    // If entity 1 is on the right of entity 2
    if (e1->getPositionX() > e2->getPositionX()) {
        // If entity 1 his left side is more to the left than entity 2 his right side there is collision over x
        if ((e1->getPositionX() - (e1->getWidth() / 2) - 0.005 <
             (e2->getPositionX() + (e2->getWidth() / 2) - 0.005))) {
            x = true;
        }
    }
        // If entity 1 is on the left of entity 2
    else {
        // If entity 2 his left side is more to the left than entity 2 his right side there is collision over x
        if ((e1->getPositionX() + (e1->getWidth() / 2) - 0.005 >
             (e2->getPositionX() - (e2->getWidth() / 2) - 0.005))) {
            x = true;
        }
    }
    // If entity 1 is higher than entity 2
    if (e1->getPositionY() > e2->getPositionY()) {
        // If entity 1 his bottom side is lower than entity 2 his top side there is collision over y
        if ((e1->getPositionY() - (e1->getHeight() / 2) - 0.005 <
             (e2->getPositionY() + (e2->getHeight() / 2) - 0.005))) {
            y = true;
        }
    }
        // If entity 1 is lower than entity 2
    else {
        // If entity 2 his bottom side is lower than entity 1 his top side there is collision over y
        if ((e1->getPositionY() + (e1->getHeight() / 2) - 0.005 >
             (e2->getPositionY() - (e2->getHeight() / 2) - 0.005))) {
            y = true;
        }
    }
    return x and y;
}
