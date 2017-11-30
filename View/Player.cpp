//
// Created by laurens on 11/27/17.
//

#include "Player.h"
#include "../Model/Ship.h"
#include "Transformation.h"
#include "../Controller/Stopwatch.h"

View::Player::Player(Model::Ship *entity, const std::string &pathToTexture, const sf::Vector2u &imageCount,
                     float switchTime) : Entity(entity, pathToTexture, imageCount, switchTime) {
    subject = entity;
}

void View::Player::draw(sf::RenderWindow *window, float deltaTime) {
    Transformation* trans = Transformation::getInstance();
    if (!this->subject->canBeHit(Ctrl::Stopwatch::getInstance()->getTotalTime(), false)){
        this->row = 1;
    } else {
        this->row = 0;
    }
    Entity::draw(window, deltaTime);
    float x = -3.5f;
    float y = trans->transformViaY(2.475);
    sf::Texture texture;
    texture.loadFromFile("../Textures/Hearth.png");
    sf::Vector2f size(trans->transformWidth(0.3), trans->transformHeight(0.3));

    for (unsigned int i = 0; i < this->subject->getHealt(); i++){
        sf::RectangleShape hearth(size);
        hearth.setTexture(&texture);
        hearth.setOrigin(hearth.getSize() / 2.0f);
        hearth.setPosition(sf::Vector2f(trans->transformViaX(x), y));
        window->draw(hearth);
        x += 0.35;
    }
}
