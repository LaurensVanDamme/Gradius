//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_BULLET_H
#define GRADIUS_BULLET_H

#include "Entity.h"

namespace Model {

    class Bullet : public Entity {
    public:

        /**
        * @brief Initialize a Model::Bullet object
        */
        Bullet()= default;

        Bullet(float x, float y, float width, float height, bool AI);

        /**
        * @brief Updates the bullet with the given time
        */
        void update(float time) override;

    private:
        bool AI{false};
    };

}


#endif //GRADIUS_BULLET_H
