#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Dog.h"


class Game
{
public:
    Game();
    ~Game();

    // where the update loop is performed
    void loop();

    // set the game to terminate at the end of the current loop
    void exitGame();
private:
    // perform some initialization work before starting loop
    void initialize(int numDogs = 5);

    // clean up point before destructor is called
    void terminate();

private:
    // controls the status of the overral application
    bool mExit;

    // TODO: vectors of Dogs
    std::vector<Dog> mActors;
    // TODO: instance of AIController
};

#endif // !GAME_H