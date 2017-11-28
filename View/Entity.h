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

        Entity();
        Entity(Model::Entity *entity, std::string pathToTexture, sf::Vector2u imageCount, float switchTime);

//        void updateCoordinates(int x, int y);


        void updateXCoor() override;

        void updateYCoor() override;

        void updateDestroyed() override;

        bool isDestroyed() const;


        virtual void draw(sf::RenderWindow *window, float deltaTime);



    protected:
        sf::Texture texture;
        sf::RectangleShape body;
        Animation animation;
        unsigned int row;
        bool animationEnabled;
        bool destroyed;
    };

}


#endif //GRADIUS_VIEWENTITY_H
