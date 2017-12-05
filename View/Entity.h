//
// Created by laurens on 11/20/17.
//

#ifndef GRADIUS_VIEWENTITY_H
#define GRADIUS_VIEWENTITY_H

#include "Animation.h"
#include "../ObserverPattern/Observer.h"
#include "../ObserverPattern/Event.h"
#include <SFML/Graphics.hpp>
#include <memory>

namespace Model {
    class Entity;
}

namespace View {

    class Transformation;

    class Entity: public OP::Observer {
    public:

        Entity();
        Entity(std::weak_ptr<Model::Entity> entity, std::string pathToTexture, sf::Vector2u imageCount, float switchTime);

        void update(OP::Event& event) override;

        bool isDestroyed() const;

        virtual void draw(std::unique_ptr<sf::RenderWindow>& window, float deltaTime);



    protected:
        std::shared_ptr<sf::Texture> texture;
        sf::RectangleShape body;
        Animation animation;
        unsigned int row;
        bool animationEnabled;
        bool destroyed;
    };

}


#endif //GRADIUS_VIEWENTITY_H
