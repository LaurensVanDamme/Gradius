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

float Transformation::transformViaX(float x) {
    if (x >= 0){
        return ((x / 4) * (windowWidth / 2)) + (windowWidth / 2);
    } else {
        return (x / 4) * (windowWidth / 2);
    }
}

float Transformation::transformViaY(float y) {
    if (y >= 0){
        return ((y / 3) * (windowHeight / 2)) + (windowHeight / 2);
    } else {
        return (y / 3) * (windowHeight / 2);
    }
}

float Transformation::transformWidth(float width) {
    return (width / 8) * windowWidth;
}

float Transformation::transformHeight(float height) {
    return (height / 6) * windowHeight;
}


