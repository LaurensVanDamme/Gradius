//
// Created by laurens on 11/18/17.
//

#include "Transformation.h"


View::Transformation::Transformation() {

}

void View::Transformation::updateWindowSize(unsigned int windowWidth, unsigned int windowHeight) {
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
}

float View::Transformation::transformViaX(float x) {
    if (x >= 0){
        return ((x / 4) * (windowWidth / 2)) + (windowWidth / 2);
    } else {
        return (windowWidth / 2) - ((-x / 4) * (windowWidth / 2));
    }
}

float View::Transformation::transformViaY(float y) {
    if (y <= 0){
        return ((-y / 3) * (windowHeight / 2)) + (windowHeight / 2);
    } else {
        return (windowHeight / 2) - ((y / 3) * (windowHeight / 2));
    }
}

float View::Transformation::transformWidth(float width) {
    return (width / 8) * windowWidth;
}

float View::Transformation::transformHeight(float height) {
    return (height / 6) * windowHeight;
}


