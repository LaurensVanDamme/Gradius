//
// Created by laurens on 11/30/17.
// Based on: https://stackoverflow.com/questions/11452760/singleton-c-template-class
//

#ifndef GRADIUS_SINGLTON_H
#define GRADIUS_SINGLTON_H

template<typename T>
class Singleton {
public:
    static T* getInstance(){
        if (!instance){
            Singleton::instance = new T;
        }
        return Singleton::instance;
    }

    virtual ~Singleton(){
        delete instance;
    }

private:
    static T* instance;
};

template<typename T> T* Singleton<T>::instance = nullptr;


#endif //GRADIUS_SINGLTON_H
