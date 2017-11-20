//
// Created by laurens on 11/18/17.
//

#include "View.h"


View::View() {

}

View::View(unsigned int windowWidth, unsigned int windowHeight, Model *model): model(model){
    window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Gradius - Main Menu");
    transformation = Transformation(windowWidth, windowHeight);
}

void View::updateView() {

}
