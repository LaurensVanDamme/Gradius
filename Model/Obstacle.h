//
// Created by laurens on 11/27/17.
//

#ifndef GRADIUS_OBSTACLE_H
#define GRADIUS_OBSTACLE_H

#include "Entity.h"

namespace Model {

    class Obstacle: public Entity {
    public:
        Obstacle();

        Obstacle(float x, float y, float height, float width, float speed);


        virtual const std::string &getType() const override;


        virtual unsigned int getDamage() const override;


        void update(float time) override;

    };

}


#endif //GRADIUS_OBSTACLE_H
