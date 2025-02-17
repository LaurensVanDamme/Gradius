//
// Created by laurens on 11/23/17.
//

#include "Subject.h"
#include "Observer.h"

void OP::Subject::attach(std::weak_ptr<Observer> observer) {
    observers.push_back(observer);
}

void OP::Subject::notify(OP::Event& event) const {
    for (auto observer: this->observers){
        if(auto ob = observer.lock()){
            ob->update(event);
        }
    }
}

OP::Subject::~Subject() {

}
