#include "pch.h"
#include "Game.h"


Game::Game() :
    mExit(false)
{
}


Game::~Game()
{
}


void Game::initialize(int numDogs)
{
    // insert some dogs
    mActors.clear();

    for (unsigned int i = 0; i < numDogs; ++i)
    {
        mActors.push_back(Dog("dog" + std::to_string(i)));
    }
}

void Game::loop()
{
    this->initialize();

    while (!mExit)
    {
        // get input from the player...

        // update other subsystems...
        aiController.update(mActors);

        // render our beautiful dogs...
    }

    this->terminate();
}

void Game::terminate()
{
}

void Game::exitGame()
{
    this->mExit = true;
}