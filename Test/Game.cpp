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
    auto it = mActors.begin();
    mActors.insert(it, numDogs);
}

void Game::loop()
{
    this->initialize();

    while (!mExit)
    {
        // TODO: AIController update()
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