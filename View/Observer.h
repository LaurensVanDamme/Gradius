//
// Created by laurens on 11/23/17.
//

#ifndef GRADIUS_OBSERVER_H
#define GRADIUS_OBSERVER_H

#include "../Model/Subject.h"

class Subject;

class Observer {
public:
    Observer();
    Observer(Subject* subject);

    virtual void update()=0;

protected:
    Subject* subject;
};


#endif //GRADIUS_OBSERVER_H
