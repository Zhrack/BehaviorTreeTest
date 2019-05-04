#include "pch.h"
#include "Game.h"


Game::Game() :
    mExit(false)
{
}


Game::~Game()
{
}


void Game::initialize()
{
}

void Game::loop()
{
    this->initialize();

    while (!mExit)
    {

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