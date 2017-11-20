//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_ENTITY_H
#define GRADIUS_ENTITY_H

class Entity {
public:
/**
\n    Returns the x coordinate of the entity
*/
    double getPositionX() const;

/**
\n    Returns the y coordinate of the entity
*/
    double getPositionY() const;

/**
\n    Updates the x coordinate of the entity by a new x coordinate
*/
    void updatePositionX(double newPositionX);

/**
\n    Updates the y coordinate of the entity by a new y coordinate
*/
    void updatePositionY(double newPositionY);


    float getHeight() const;


    float getWidth() const;
private:
    double x;
    double y;
    float height;
    float width;
};


#endif //GRADIUS_ENTITY_H
