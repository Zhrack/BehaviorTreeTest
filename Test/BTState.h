#ifndef BT_STATE_H
#define BT_STATE_H

#include "Constants.h"
#include "Dog.h"

/// <summary>
/// Stores BT-level of data.
/// </summary>
struct BTState
{
    Dog* currentDog;

    unsigned int numActors;
};

#endif // !BT_STATE_H
