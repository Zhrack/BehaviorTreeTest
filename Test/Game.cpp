 
#include "Game.h"
#include "Constants.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <random>

Game::Game() :
    mExit(false)
{
}


Game::~Game()
{
}


void Game::initialize(unsigned int numDogs)
{
    
    mActors.clear();

    // insert some dogs

    // I know, I know, random_device and Marsenne Twister are overkill. I like overkill sometimes... :)
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distEnergy(Constants::minEnergy, static_cast<int>(std::nextafter(Constants::maxEnergy, INT_MAX)));
    std::uniform_int_distribution<int> distBoredom(Constants::minBoredom, static_cast<int>(std::nextafter(Constants::maxBoredom, INT_MAX)));

    for (unsigned int i = 0; i < numDogs; ++i)
    {
        int energy = 0;
        int boredom = 0;

        if (Constants::randomInitialStates)
        {
            // randomly generate initial levels
            energy = distEnergy(mt);
            boredom = distBoredom(mt);
        }
        else
        {
            // use fixed values
            energy = Constants::maxEnergy;
            boredom = Constants::minBoredom;
        }

        mActors.push_back(new Dog(Constants::dogNamePrefix + std::to_string(i), energy, boredom));
    }

    mAiController.initialize();
}

void Game::loop()
{
    this->initialize(Constants::numDogs);

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
    }
    mActors.clear();
}

void Game::exitGame()
{
    this->mExit = true;
}