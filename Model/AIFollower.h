//
// Created by laurens on 12/6/17.
//

#ifndef GRADIUS_FOLLOWER_H
#define GRADIUS_FOLLOWER_H

#include "Ship.h"

namespace Model {

    class AIFollower: public Ship {
    public:

        AIFollower();

        AIFollower(float x, float y, float width, float height, const std::weak_ptr<World> &world);

        void update(float time) override ;

    private:

        void checkCoorY() override;
    };

}


#endif //GRADIUS_FOLLOWER_H
