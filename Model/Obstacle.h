//
// Created by laurens on 11/27/17.
//

#ifndef GRADIUS_OBSTACLE_H
#define GRADIUS_OBSTACLE_H

#include "Entity.h"

namespace Model {

    class Obstacle: public Entity {
    public:

        /**
        * @brief Initialize a Model::Obstacle object
        */
        Obstacle()= default;

        Obstacle(float x, float y, float height, float width);

        /**
        * @brief Update the obstacle with the given time
        */
        void update(float time) override;

    };

}


#endif //GRADIUS_OBSTACLE_H
