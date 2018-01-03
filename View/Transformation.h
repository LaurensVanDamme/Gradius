//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_TRANSFORMATION_H
#define GRADIUS_TRANSFORMATION_H


#include "../Singleton.h"

namespace View {

    class Transformation: public Singleton<Transformation> {
        friend class Singleton<Transformation>;
    private:

    /**
    * @brief Initialize a View::Transformation object
    */
        Transformation()= default;

    public:

    /**
    * @brief Updates windowWidth and -Height for transformations
    */
        void updateWindowSize(unsigned int windowWidth, unsigned int windowHeight);

    /**
    * @brief Transforms the coordinate x to pixel x
    */
        float transformViaX(float x);

    /**
    * @brief Transforms the coordinate y to pixel y
    */
        float transformViaY(float y);

    /**
    * @brief Transforms the coordinate width to pixel width
    */
        float transformWidth(float width);

    /**
    * @brief Transforms he coordinate height to pixel height
    */
        float transformHeight(float height);

    private:
        unsigned int windowWidth;
        unsigned int windowHeight;
    };

}

#endif //GRADIUS_TRANSFORMATION_H
