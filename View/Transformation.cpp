//
// Created by laurens on 11/18/17.
//

#include "Transformation.h"

Transformation::Transformation() {

}

Transformation::Transformation(unsigned int windowWidth, unsigned int windowHeight):
    windowWidth(windowWidth), windowHeight(windowHeight) {

}

void Transformation::updateWindowSize(unsigned int windowWidth, unsigned int windowHeight) {
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
}

double Transformation::transformViaX(double x) {
    return (x / 8) * windowWidth;
}

double Transformation::transformViaY(double y) {
    return (y / 6) * windowHeight;
}


