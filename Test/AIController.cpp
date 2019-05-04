#include "pch.h"
#include "AIController.h"

#include "Constants.h"

AIController::AIController() :
    mBlackBoard(new Blackboard()),
    mRootNode(nullptr)
{
    mBlackBoard->addValue(Constants::currentBTState, new BTState());
}


AIController::~AIController()
{
    BTState* state = static_cast<BTState*>(mBlackBoard->get(Constants::currentBTState));
    if (state != nullptr)
    {
        delete state;
        state = nullptr;
        mBlackBoard->removeValue(Constants::currentBTState);
    }
}

void AIController::initialize()
{
    // build behavior tree
    mRootNode.reset(nullptr);
}

void AIController::update(std::vector<Dog*>& actors)
{
    // TODO: Save. Insert all actors inside it.
    // TODO: insert a "currentDog" for the next run of BT. 
    BTState* btState = static_cast<BTState*>(mBlackBoard->get(Constants::currentBTState));
    btState->numActors = actors.size();

    // run BT for currentDog
    for (auto it = actors.begin(); it != actors.end(); ++it)
    {
        // update currentDog value
        btState->currentDog = *it;
        mRootNode->process();
    }
}

void AIController::terminate()
{
}
