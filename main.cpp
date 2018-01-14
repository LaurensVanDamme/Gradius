

#include <cstdio>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "Controller/Controller.h"

int main(int argc, char *argv[])
{
    srand (time(NULL)); // Initialize the random function
    Ctrl::Controller game; // Create a game
    game.run();
    return 0;
}