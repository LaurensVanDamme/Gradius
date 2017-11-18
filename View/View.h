//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_VIEW_H
#define GRADIUS_VIEW_H

#include <SFML/Graphics.hpp>

class Model;

class View {
public:
    View();
    View(unsigned int windowWidth, unsigned int windowHeight, Model* model);


    sf::RenderWindow *getWindow() const;

    void updateView();

private:
    Model* model;
    sf::RenderWindow * window;
};


#endif //GRADIUS_VIEW_H
