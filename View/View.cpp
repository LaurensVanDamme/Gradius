//
// Created by laurens on 11/18/17.
//

#include "View.h"
#include "Entity.h"


View::View::View() {

}

View::View::View(unsigned int windowWidth, unsigned int windowHeight, Model::Model *model): model(model){
    window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Gradius - Main Menu");
    transformation = Transformation::getTransformation();
    transformation->updateWindowSize(windowWidth, windowHeight);
}

void View::View::addViewEntity(Model::Entity *entity, const std::string& pathToTexture, sf::Vector2u imageCount, float switchTime) {
    Entity* ventity = new Entity(entity, pathToTexture, imageCount, switchTime);
    entity->attach(ventity);
    this->entities.push_back(ventity);
}

//----------Tijdelijk----------//

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

//-------einde tijdelijk-------//

void View::View::updateView(float deltaTime) {
    window->clear(sf::Color(150, 150, 150));
    // Go over every entity in the view update it and draw it on the window
    for (auto entity: this->entities){
        entity->draw(window, deltaTime);
    }
    //----------Tijdelijk----------//
    sf::Font font;
    font.loadFromFile("arial.ttf");
    window->draw(getFPS(font));
    //-------Einde tijdelijk-------//
    window->display();
}

void View::View::checkForEvents(sf::Event event) {
    while (window->pollEvent(event))
    {
        switch (event.type){
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::Resized:
                transformation->updateWindowSize(window->getSize().x, window->getSize().y);
                break;
        }
    }
}

bool View::View::isWindowOpen() {
    return window->isOpen();
}

View::View::~View() {
//    for (auto entity: this->entities){
//        delete entity;
//    }
}
