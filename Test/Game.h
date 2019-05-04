#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Dog.h"
#include "AIController.h"


/// <summary>
/// Base class that represents the entire game.
/// </summary>
class Game
{
public:
    Game();
    ~Game();

    /// <summary>
    /// Where the update loop is performed.
    /// </summary>
    void loop();

    /// <summary>
    /// Sets the game to terminate at the end of the current loop.
    /// </summary>
    void exitGame();
private:
    /// <summary>
    /// Performs some initialization work before starting the loop.
    /// </summary>
    /// <param name="numDogs">The number of dogs to simulate.</param>
    void initialize(unsigned int numDogs = 5);

    /// <summary>
    /// Clean up point before destructor is called.
    /// </summary>
    void terminate();

private:
    /// <summary>
    /// Controls the status of the overral application
    /// </summary>
    bool mExit;

    /// <summary>
    /// Vector of actors to be simulated
    /// </summary>
    std::vector<Dog*> mActors;

    /// <summary>
    /// Instance of the AiController.
    /// </summary>
    AIController mAiController;

};

#endif // !GAME_H