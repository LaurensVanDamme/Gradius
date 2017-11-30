//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_CONTROLLER_H
#define GRADIUS_CONTROLLER_H

#include "../View/View.h"
#include "../Model/Model.h"
#include <memory>

namespace Ctrl {

    class Stopwatch;

    class Controller {
    public:
        Controller(std::string jsonFile = "");

        void run();

        void checkForEvents();

        void makeBorders();

        void endGame();

    private:
        std::unique_ptr<Model::Model> model;
        std::unique_ptr<View::View> view;
    };

}


#endif //GRADIUS_CONTROLLER_H
