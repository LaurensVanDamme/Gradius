//
// Created by laurens on 11/15/17.
//

#include "Player.h"

Player::Player() {

}

Player::Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed):
        animation(texture, imageCount, switchTime), speed(speed){
    row = 0;
    // Create a body for the player with a texture
    body.setSize(sf::Vector2f(200, 300));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(600, 400);
    body.setTexture(texture);
}

void Player::update(float deltaTime) {
    sf::Vector2f movement(0.0, 0.0);
    // Check which movement the player must do
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        movement.x -= speed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        movement.x += speed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        movement.y -= speed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        movement.y += speed * deltaTime;
    // Update the texture and move the player
    animation.update(row, deltaTime);
    body.setTextureRect(animation.uvRect);
    body.move(movement);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(body);
}

const sf::Vector2f &Player::getBodyPosition() const {
    return body.getPosition();
}
