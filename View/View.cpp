//
// Created by laurens on 11/18/17.
//

#include "View.h"

View::View() {

}

View::View(unsigned int windowWidth, unsigned int windowHeight, Model *model): model(model){
    window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Gradius - Main Menu");
}

sf::RenderWindow *View::getWindow() const {
    return window;
}
