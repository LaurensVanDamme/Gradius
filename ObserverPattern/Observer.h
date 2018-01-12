//
// Created by laurens on 11/23/17.
// Based on: https://stackoverflow.com/questions/2225162/observer-design-pattern-in-c
//

#ifndef GRADIUS_OBSERVER_H
#define GRADIUS_OBSERVER_H

#include "Event.h"
#include <memory>

namespace OP { // Observer Pattern

    class Subject;

    class Observer {
    public:
        Observer()= default;

        explicit Observer(std::weak_ptr<Subject> subject);

        virtual void update(Event& event)=0;

    protected:
        std::weak_ptr<Subject> subject;
    };

}


#endif //GRADIUS_OBSERVER_H
