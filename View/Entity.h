//
// Created by laurens on 11/20/17.
//

#ifndef GRADIUS_VIEWENTITY_H
#define GRADIUS_VIEWENTITY_H

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Observer.h"

namespace Model {
    class Entity;
}

namespace View {

    class Transformation;

    class Entity: public Observer {
    public:

        Entity(Model::Entity *entity, std::string pathToTexture, sf::Vector2u imageCount, float switchTime);

//        void updateCoordinates(int x, int y);


        void updateXCoor();

        void updateYCoor();


        void draw(sf::RenderWindow *window, float deltaTime);


    private:
        sf::Texture texture;
        sf::RectangleShape body;
        Animation animation;
        unsigned int row;
        bool animationEnabled;
    };

}


#endif //GRADIUS_VIEWENTITY_H
