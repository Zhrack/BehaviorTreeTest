#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

using IDPair = std::pair<unsigned int, unsigned int>;

struct Constants
{
    static const int minHunger;
    static const int maxHunger;
    static const int hungerThreshold;
    static const int hungerStep;

    static const int minBoredom;
    static const int maxBoredom;
    static const int boredomThreshold;
    static const int boredomStep;

    static const std::string currentBTState;
};

#endif // !CONSTANTS_H
