//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_TRANSFORMATION_H
#define GRADIUS_TRANSFORMATION_H


namespace View {

    class Transformation {
    private:
        Transformation();

    public:
        static Transformation *getTransformation();

        void updateWindowSize(unsigned int windowWidth, unsigned int windowHeight);

        float transformViaX(float x);

        float transformViaY(float y);

        float transformWidth(float width);

        float transformHeight(float height);

    private:

        static Transformation *instance;
        unsigned int windowWidth;
        unsigned int windowHeight;
    };

}

#endif //GRADIUS_TRANSFORMATION_H
