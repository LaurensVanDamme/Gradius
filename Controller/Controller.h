//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_CONTROLLER_H
#define GRADIUS_CONTROLLER_H

class Model;
class View;
class Stopwatch;

class Controller {
public:
    Controller(std::string jsonFile = "");

    void run();

    void checkForEvents();
private:
    Model* model;
    View* view;
    Stopwatch* stopwatch;
};


#endif //GRADIUS_CONTROLLER_H
