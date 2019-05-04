#include "pch.h"
#include "AIController.h"


AIController::AIController() :
    mBlackBoard(new Blackboard())
{
}


AIController::~AIController()
{
}

void AIController::update(const std::vector<Dog>& actors)
{
    // TODO: Save. Insert all actors inside it.
    // TODO: insert a "currentDog" for the next run of BT. 

    // run BT for currentDog
}
