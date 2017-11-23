//
// Created by laurens on 11/23/17.
//

#ifndef GRADIUS_SUBJECT_H
#define GRADIUS_SUBJECT_H

#include <vector>

class Observer;

class Subject {
public:
    Subject();

    void attach(Observer* observer);

    void notify();
private:
    std::vector<Observer*> observers;
};


#endif //GRADIUS_SUBJECT_H
