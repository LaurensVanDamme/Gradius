//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_ENTITY_H
#define GRADIUS_ENTITY_H

#include "../ObserverPattern/Subject.h"

namespace Model {

    class Entity: public OP::Subject {
    public:

        /**
        * @brief Initialize a Model::Entity object
        */
        Entity()= default;

        Entity(float x, float y, float height, float width);

        /**
        * @brief Return the x coordinate
        */
        float getPositionX() const;

        /**
        * @brief Return the y coordinate
        */
        float getPositionY() const;

        /**
        * @brief Return the Height of the entity
        */
        float getHeight() const;

        /**
        * @brief Return the Width of the entity
        */
        float getWidth() const;

        /**
        * @brief Return the speed of the entity
        */
        float getSpeed() const;

        /**
        * @brief Return the health of the entity
        */
        unsigned int getHealth() const;

        /**
        * @brief Return the amount of damage the entity does
        */
        unsigned int getDamage() const;

        /**
        * @brief Return the type of the entity
        */
        const std::string &getType() const;

        /**
        * @brief Returns if the entity is destroyed or not
        */
        bool isDestroyed() const;

        /**
        * @brief Moves the entity up in the coordinate system
        */
        void moveUp();

        /**
        * @brief Moves the entity down in the coordinate system
        */
        void moveDown();

        /**
        * @brief Moves the entity right in the coordinate system
        */
        void moveRight();

        /**
        * @brief Moves the entity left in the coordinate system
        */
        void moveLeft();

        /**
        * @brief Destroys the entity
        */
        void wrecked();

        /**
        * @brief Subtracts the damage from the health of the entity
        */
        void hit(unsigned int damage);

        /**
        * @brief Returns if the entity can be hit
        */
        virtual bool canBeHit(float time, bool hit);

        /**
        * @brief Updates the entity with the given time
        */
        virtual void update(float time)=0;

    protected:

        /**
        * @brief Check if the x coordinate is valid and change it if needed
        */
        virtual void checkCoorX();

        /**
        * @brief Check if the y coordinate is valid and change it if needed
        */
        virtual void checkCoorY();


    protected:
        float x{};
        float y{};
        float speed{};
        unsigned int health{};
        unsigned int damage{};
        std::string type;

    private:
        float height{};
        float width{};
        bool destroyed{false};
    };

}


#endif //GRADIUS_ENTITY_H
