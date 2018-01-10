//
// Created by laurens on 12/3/17.
//

#ifndef GRADIUS_AISHIP_H
#define GRADIUS_AISHIP_H

#include "Ship.h"

namespace Model {

    class AIShooter: public Ship {
    public:


        /**
        * @brief Initialize a Model::AIShooter object
        */
        AIShooter()= default;

        AIShooter(float x, float y, float width, float height, std::weak_ptr<World> world);

        /**
        * @brief Updates the aishooter with the given time
        */
        void update(float time) override ;

    private:

        /**
        * @brief Check if the x coordinate is valid and change it if needed
        */
        void checkCoorX() override;

        /**
        * @brief Check if the y coordinate is valid and change it if needed
        */
        void checkCoorY() override;

    private:
        float lastTimeDown{};
        float lastTimeUp{};
        float yAcceleration{};
        int timesUp{};
        int timesDown{};
        bool goingDown{false};
        bool goingUp{false};

    };

}


#endif //GRADIUS_AISHIP_H
