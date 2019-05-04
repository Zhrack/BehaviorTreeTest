#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

struct Constants
{
    static const int minEnergy;
    static const int maxEnergy;
    static const int hungerThreshold;
    static const int hungerStep;

    static const int minBoredom;
    static const int maxBoredom;
    static const int boredomThreshold;
    static const int boredomStep;

    static const std::string currentBTState;

    // misc settings
    static const int sleepBetweenStepsMilli;
    static const std::string dogNamePrefix;
    static const int numDogs;
};

#endif // !CONSTANTS_H
