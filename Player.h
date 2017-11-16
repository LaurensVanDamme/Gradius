//
// Created by laurens on 11/15/17.
//

#ifndef GRADIUS_PLAYER_H
#define GRADIUS_PLAYER_H

#include <SFML/Graphics.hpp>
#include "Animation.h"


class Player {
public:
    Player();
    Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);//t

    const sf::Vector2f &getBodyPosition() const;

private:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
};


#endif //GRADIUS_PLAYER_H
