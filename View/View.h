//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_VIEW_H
#define GRADIUS_VIEW_H

#include <SFML/Graphics.hpp>
#include "Transformation.h"

class Model;

class View {
public:
    View();
    View(unsigned int windowWidth, unsigned int windowHeight, Model* model);

    void updateView();

private:
    Model* model;
    sf::RenderWindow* window;
    Transformation transformation;
};


#endif //GRADIUS_VIEW_H
