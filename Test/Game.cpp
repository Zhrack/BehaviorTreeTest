#include "pch.h"
#include "Game.h"

#include <iostream>
#include <chrono>
#include <thread>

Game::Game() :
    mExit(false)
{
}


Game::~Game()
{
}


void Game::initialize(unsigned int numDogs)
{
    // insert some dogs
    mActors.clear();

    for (unsigned int i = 0; i < numDogs; ++i)
    {
        mActors.push_back(new Dog(Constants::dogNamePrefix + std::to_string(i)));
    }

    mAiController.initialize();
}

void Game::loop()
{
    this->initialize();

    while (!mExit)
    {
        // get input from the player...

        // update other subsystems...
        mAiController.update(mActors);
        std::this_thread::sleep_for(std::chrono::milliseconds(Constants::sleepBetweenStepsMilli));

        // render our beautiful dogs...
    }

    this->terminate();
}

void Game::terminate()
{
    for (auto a : mActors)
    {
        delete a;
        a = nullptr;
    }
    mActors.clear();
}

void Game::exitGame()
{
    this->mExit = true;
}