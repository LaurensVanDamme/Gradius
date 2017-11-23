//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_VIEW_H
#define GRADIUS_VIEW_H

#include <SFML/Graphics.hpp>
#include "Transformation.h"
#include <vector>

namespace Model {
    class Model;
}

namespace View {

    class ViewEntity;


    class View {
    public:
        View();

        View(unsigned int windowWidth, unsigned int windowHeight, Model::Model *model);

        void addViewEntity(ViewEntity *entity);

        void checkForEvents(sf::Event event);

        void updateView(float deltaTime);

        bool isWindowOpen();

        virtual ~View();

    private:
        Model::Model *model;
        sf::RenderWindow *window;
        Transformation *transformation;
        std::vector<ViewEntity *> entities;
    };

}


#endif //GRADIUS_VIEW_H
