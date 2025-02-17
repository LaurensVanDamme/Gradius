//
// Created by laurens on 11/23/17.
// Based on: https://stackoverflow.com/questions/2225162/observer-design-pattern-in-c
//

#ifndef GRADIUS_SUBJECT_H
#define GRADIUS_SUBJECT_H


#include <memory>
#include <vector>

namespace OP {  // Observer Pattern

    class Observer;
    class Event;

    class Subject {
    public:
        Subject()= default;

        void attach(std::weak_ptr<Observer> observer);

        void notify(Event& event) const;

        virtual ~Subject();

    private:
        std::vector<std::weak_ptr<Observer>> observers;
    };

}


#endif //GRADIUS_SUBJECT_H
