//
// Created by laurens on 11/23/17.
//

#ifndef GRADIUS_SUBJECT_H
#define GRADIUS_SUBJECT_H

#include <memory>
#include <vector>

class Observer;

class Subject {
public:
    Subject();

    void attach(std::weak_ptr<Observer> observer);

    void notifyXCoor() const ;

    void notifyYCoor();

    void notifyDestroyed();

private:
    std::vector<std::weak_ptr<Observer>> observers;
};


#endif //GRADIUS_SUBJECT_H
