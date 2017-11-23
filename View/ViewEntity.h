//
// Created by laurens on 11/20/17.
//

#ifndef GRADIUS_VIEWENTITY_H
#define GRADIUS_VIEWENTITY_H

#include <SFML/Graphics.hpp>
#include "Animation.h"

class Entity;
class Transformation;

class ViewEntity {
public:

    ViewEntity(Entity* entity, std::string pathToTexture, sf::Vector2u imageCount, float switchTime);


    void update(Transformation* trans, float deltaTime);


    void draw(sf::RenderWindow* window);


private:
    sf::Texture texture;
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    Entity* entity;
    bool animationEnabled;
};


#endif //GRADIUS_VIEWENTITY_H
