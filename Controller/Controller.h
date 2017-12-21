//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_CONTROLLER_H
#define GRADIUS_CONTROLLER_H

#include "../View/View.h"
#include "../Model/World.h"
#include <memory>

namespace Ctrl {

    class Controller {
    public:

    /**
     * @brief Makes a game with model and view
     */
        Controller(std::string jsonFile = "");

    /**
     * @brief Starts the game loop
     */
        void run();

    /**
     * @brief Checks for input of the user
     */
        void getUserInput();

    /**
     * @brief Ends the game
     */
        void endGame();

    private:
        std::shared_ptr<Model::World> world;
        std::shared_ptr<View::View> view;
    };

}


#endif //GRADIUS_CONTROLLER_H
