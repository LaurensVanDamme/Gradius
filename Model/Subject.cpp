//
// Created by laurens on 11/23/17.
//

#include "Subject.h"
#include "../View/Observer.h"

Subject::Subject() {

}

void Subject::attach(Observer *observer) {
    observers.push_back(observer);
}

void Subject::notify() {
    for (auto observer: observers){
        observer->update();
    }
}
