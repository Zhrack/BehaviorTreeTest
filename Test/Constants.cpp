 
#include "Constants.h"

/// <summary>
/// The minimum energy for dogs.
/// </summary>
const int Constants::minEnergy = 0;
/// <summary>
/// The maximum energy for dogs.
/// </summary>
const int Constants::maxEnergy = 100;
/// <summary>
/// The energy threshold for condition nodes.
/// </summary>
const int Constants::energyThreshold = 20;
/// <summary>
/// The energy step by which energy level is modified.
/// </summary>
const int Constants::energyStep = 4;

/// <summary>
/// The minimum boredom for dogs.
/// </summary>
const int Constants::minBoredom = 0;
/// <summary>
/// The maximum boredom for dogs.
/// </summary>
const int Constants::maxBoredom = 100;
/// <summary>
/// The boredom thresholdfor condition nodes.
/// </summary>
const int Constants::boredomThreshold = 80;
/// <summary>
/// The boredom step by which boredom level is modified.
/// </summary>
const int Constants::boredomStep = 4;

/// <summary>
/// The current bt state key on the BlackBoard.
/// </summary>
const std::string Constants::currentBTState = std::string("currentBTState");

/// <summary>
/// The sleep between steps in milliseconds.
/// </summary>
const int Constants::sleepBetweenStepsMilli = 500;

/// <summary>
/// The dog name prefix.
/// </summary>
const std::string Constants::dogNamePrefix = "DOG_";

/// <summary>
/// The number dogs to be simulated.
/// </summary>
const int Constants::numDogs = 5;

/// <summary>
/// Whether starting values for dogs are random or start maxed out.
/// </summary>
const bool Constants::randomInitialStates = true;