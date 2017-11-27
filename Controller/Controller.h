//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_CONTROLLER_H
#define GRADIUS_CONTROLLER_H

namespace Model {
    class Model;
}

namespace View {
    class View;
}

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
        Model::Model *model;
        View::View *view;
        Stopwatch *stopwatch;
    };

}


#endif //GRADIUS_CONTROLLER_H
