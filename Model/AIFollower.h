//
// Created by laurens on 12/6/17.
//

#ifndef GRADIUS_FOLLOWER_H
#define GRADIUS_FOLLOWER_H

#include "Ship.h"

namespace Model {

    class AIFollower: public Ship {
    public:

        /**
        * @brief Initialize a Model::AIFollower object
        */
        AIFollower()= default;

        AIFollower(float x, float y, float width, float height, std::weak_ptr<World> world);

        /**
        * @brief Updates the aifollower with the given time
        */
        void update(float time) override ;

    private:

        /**
        * @brief Check if the y coordinate is valid and change it if needed
        */
        void checkCoorY() override;
    };

}


#endif //GRADIUS_FOLLOWER_H
