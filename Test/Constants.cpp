#include "pch.h"
#include "Constants.h"

const int Constants::minHunger = 0;
const int Constants::maxHunger = 100;
const int Constants::hungryThreshold = 20;

const int Constants::minBoredom = 0;
const int Constants::maxBoredom = 100;
const int Constants::boredomThreshold = 80;

const IDPair Constants::currentBTState = std::make_pair(-1, -1);