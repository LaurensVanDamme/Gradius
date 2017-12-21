//
// Created by laurens on 11/30/17.
// Based on: https://stackoverflow.com/questions/11452760/singleton-c-template-class
//

#ifndef GRADIUS_SINGLTON_H
#define GRADIUS_SINGLTON_H



template<typename T>
class Singleton {
    public:

    /**
    * @brief Returns the only instance of this class
    */
        static T* getInstance(){
            // If the instance doesn't exist make one
            if (!instance){
                Singleton::instance = new T;
            }  // else return the only one
            return Singleton::instance;
        }

    /**
    * @brief Deletes the only instance of this class
    */
        virtual ~Singleton(){
            delete instance;
        }

    private:
        static T* instance;
};

template<typename T> T* Singleton<T>::instance = nullptr;


#endif //GRADIUS_SINGLTON_H
