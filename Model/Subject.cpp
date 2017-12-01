//
// Created by laurens on 11/23/17.
//

#include "../View/Observer.h"
#include "Subject.h"

Subject::Subject() {

}

void Subject::attach(std::weak_ptr<Observer> observer) {
    observers.push_back(observer);
}

void Subject::notifyXCoor() const{
    for (auto observer: observers){
        if(auto ob = observer.lock()){
            ob->updateXCoor();
        }
    }
}

void Subject::notifyYCoor(){
    for (auto observer: observers){
        if(auto ob = observer.lock()){
            ob->updateYCoor();
        }
    }
}

void Subject::notifyDestroyed() {
    for (auto observer: observers){
        if(auto ob = observer.lock()){
            ob->updateDestroyed();
        }
    }
}
