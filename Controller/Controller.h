//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_CONTROLLER_H
#define GRADIUS_CONTROLLER_H

class Model;
class View;

class Controller {
public:
    Controller();
    Controller(Model* model, View* view);
    void checkForEvents(float deltaTime);
private:
    Model* model;
    View* view;

};


#endif //GRADIUS_CONTROLLER_H
