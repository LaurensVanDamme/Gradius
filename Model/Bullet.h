//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_BULLET_H
#define GRADIUS_BULLET_H

#include "Entity.h"

namespace Model {

    class Bullet : public Entity {
    public:

        Bullet();

        Bullet(float x, float y, float height, float width, float speed, bool AI);


        const std::string &getType() const override;


        unsigned int getDamage() const override;


        void update(float time) override;

    private:
        bool AI;
    };

}


#endif //GRADIUS_BULLET_H
