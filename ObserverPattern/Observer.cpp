//
// Created by laurens on 11/23/17.
//

#include "Observer.h"
#include "Subject.h"

OP::Observer::Observer() {

}

OP::Observer::Observer(std::weak_ptr<Subject> subject): subject(subject) {
}
