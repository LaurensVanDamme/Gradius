//
// Created by laurens on 11/18/17.
//

#include "View.h"
#include "Entity.h"
#include "Player.h"
#include "../Model/World.h"
#include "Transformation.h"


View::View::View() {}

View::View::View(unsigned int windowWidth, unsigned int windowHeight, std::weak_ptr<Model::World> model): Observer(model){
    // Create a window where the game will be shown
    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(windowWidth, windowHeight), "Gradius");
    // Initialize the only Transformation object
    Transformation::getInstance()->updateWindowSize(windowWidth, windowHeight);
}

void View::View::addViewEntity(std::shared_ptr<Model::Entity> entity) {
    std::string pathToTexture = "../Textures/";
    sf::Vector2u imageCount(0,0);
    float switchTime = 0;
    // Check the type of entity and get the right texture and (if present) animation
    if (entity->getType() == "PlayerShip"){
        if (auto ent = std::dynamic_pointer_cast<Model::Ship>(entity)) {
            auto ventity = std::make_shared<Player>(ent, "../Textures/Night Raider sprites.png",
                                                           sf::Vector2u(4,2), 0.15);
            ent->attach(ventity);
            this->entities.push_back(ventity);
            return;
        }
    } else if (entity->getType() == "AIShooter"){
        pathToTexture += "F5S3.png";
    } else if (entity->getType() == "Border"){
        pathToTexture += "rock.png";
    } else if (entity->getType() == "Bullet"){
        pathToTexture += "beam1.png";
    } else if (entity->getType() == "AIBullet"){
        pathToTexture += "beam2.png";
    } else if (entity->getType() == "Obstacle") {
        pathToTexture += "rock.png";
    } else if (entity->getType() == "AIFollower") {
        pathToTexture += "Follower.png";
    }
    auto ventity = std::make_shared<Entity>(entity, pathToTexture, imageCount, switchTime);
    // Link subject and observer
    entity->attach(ventity);
    // Add the View::Entity to the view
    this->entities.push_back(ventity);
}

///----------Tijdelijk----------///

sf::Text getFPS(sf::Font font) {
    static sf::Clock clock;
    float cTime = clock.getElapsedTime().asSeconds();
    clock.restart();
    int fps = std::round(1 / cTime);

    std::string str = "FPS: " + std::to_string(fps);
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setString(str);
    return text;
}

///-------einde tijdelijk-------///

void View::View::updateView(float deltaTime) {
    window->clear(sf::Color(150, 150, 150));
    // If there are things to draw, draw them
    if (this->entities.size() == 0) {
        sf::Texture texture;
        texture.loadFromFile("../Textures/Game Over.png");
        sf::RectangleShape background;
        background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
        background.setTexture(&texture);
        window->draw(background);
    } else if (this->entities.size() == 1) {

    } else{
        // Go over every entity in the view and draw it if it isn't destroyed
        std::vector<std::shared_ptr<Entity>> toKeep;
        for (auto entity: this->entities) {
            if (!entity->isDestroyed()) {
                entity->draw(window, deltaTime);
                toKeep.push_back(entity);
            }
        }
        this->entities = toKeep;
    }
    ///----------Tijdelijk----------///
    sf::Font font;
    font.loadFromFile("arial.ttf");
    window->draw(getFPS(font));
    ///-------Einde tijdelijk-------///
    // Display the updated view in the window
    window->display();
}

void View::View::checkForEvents(sf::Event event) {
    while (window->pollEvent(event))
    {
        // Check which event we have to handle
        switch (event.type){
            case sf::Event::Closed:
                window->close();
                break;
        }
    }
}

void View::View::update(OP::Event& event) {
    // If the event is an addEntity event handle it
    if (event.type == OP::Event::AddedEntity){
        this->addViewEntity(event.addedEntity.entity);
    }
}

bool View::View::isWindowOpen() {
    return window->isOpen();
}
