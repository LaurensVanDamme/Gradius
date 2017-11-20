#include <SFML/Graphics.hpp>
#include <time.h>

#include "Player.h"
#include "View/ViewEntity.h"
#include "Model/Ship.h"

#include "Controller/Controller.h"
#include "View/View.h"
#include "Model/Model.h"

#include <iostream>
using namespace std;

int main()
{
    clock_t lastTime;
    lastTime = clock();
    float deltaTime;
    Model model;
    View view(1200, 800, &model);

    //------------ start Test ------------//

    Ship* player = new Ship(0, 0, 1, 0.66666, 10, 2);
    model.setPlayer(player);
    ViewEntity* test1 = new ViewEntity(player, "../Textures/Night Raider sprites.png", sf::Vector2u(4,1), 0.3);
    view.addViewEntity(test1);

    //------------- End Test -------------//


    // Let the program loop until shut down
    while (view.isWindowOpen())
    {
        deltaTime = float(clock() - lastTime) / CLOCKS_PER_SEC;
        lastTime = clock();
        sf::Event event;
        view.checkForEvents(event);
        view.updateView(deltaTime);
//        cout << deltaTime << "   " << "" << endl;
    }

    return 0;
}

/*static const float VIEW_HEIGHT = 1200.0f;
void resizeView(const sf::RenderWindow& window, sf::View& view){
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}


int main()
{
    float deltaTime;
    sf::Clock clock;

    sf::RenderWindow window(sf::VideoMode(1200, 800), "Gradius - Main Menu");  // Create a window

    sf::View view(sf::Vector2f(0.0, 0.0), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

    sf::Texture shipTexture;
    shipTexture.loadFromFile("../Textures/Night Raider sprites.png");

    Player player1(&shipTexture, sf::Vector2u(4,1), 0.25, 400.0);

    // Let the program loop until shut down
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        cout << deltaTime << endl;
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    resizeView(window, view);
                    break;
            }
        }

        player1.update(deltaTime);
//        view.setCenter(player1.getBodyPosition());de

        window.clear(sf::Color(150, 150, 150));
        window.setView(view);
        player1.draw(window);
        window.display();
    }

    return 0;
} */