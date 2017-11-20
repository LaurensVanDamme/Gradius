//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_TRANSFORMATION_H
#define GRADIUS_TRANSFORMATION_H


class Transformation {
public:
    Transformation();
    Transformation(unsigned int windowWidth, unsigned int windowHeight);

    void updateWindowSize(unsigned int windowWidth, unsigned int windowHeight);

    float transformViaX(float x);

    float transformViaY(float y);

    float transformWidth(float width);

    float transformHeight(float height);

private:
    unsigned int windowWidth;
    unsigned int windowHeight;
};


#endif //GRADIUS_TRANSFORMATION_H
