#include <SFML/Graphics.hpp>
#include "Animation.h"

int main()
{
    float deltaTime;
    sf::Clock clock;

    sf::RenderWindow window(sf::VideoMode(1200, 800), "Gradius - Main Menu");  // Create a window
    sf::RectangleShape ship(sf::Vector2f(200.0, 300.0));  // Create a rectangle where the ship is displayed
    ship.setPosition(600, 400);  // Place the ship somewhere in the window
    // Give the ship the right texture
    sf::Texture shipTexture;
    shipTexture.loadFromFile("../Night Raider sprites.png");
    ship.setTexture(&shipTexture);
    // Create an animation for the ship
    Animation shipAnimation1(&shipTexture, sf::Vector2u(4,1), 0.5);

    // Let the program loop until shut down
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        shipAnimation1.update(0, deltaTime);  // Update the animation of the ship
        ship.setTextureRect(shipAnimation1.uvRect);  // Set the new picture in the rectangle

        window.clear(sf::Color(150, 150, 150));
        window.draw(ship);
        window.display();
    }

    return 0;
}