#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

using IDPair = std::pair<unsigned int, unsigned int>;

struct Constants
{
    static const int minHunger;
    static const int maxHunger;
    static const int hungryThreshold;

    static const int minBoredom;
    static const int maxBoredom;
    static const int boredomThreshold;

    static const IDPair currentDog;
    static const IDPair numberActors;
};

#endif // !CONSTANTS_H
