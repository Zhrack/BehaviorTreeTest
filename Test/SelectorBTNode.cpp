 
#include "SelectorBTNode.h"

#include "Constants.h"
#include "BTState.h"
#include "Dog.h"
#include "NodeActorAIState.h"

#include <string>
#include <iostream>

SelectorBTNode::SelectorBTNode() :
    CompositeBTNode()
{
}


SelectorBTNode::~SelectorBTNode()
{
}

StatusType SelectorBTNode::process(Blackboard& blackBoard)
{
    BTState* btState = static_cast<BTState*>(blackBoard.get(Constants::currentBTState));

    // retrieve node state data for this actor
    auto dogID = btState->currentDog->getID();
    auto stateID = std::to_string(mID) + "_" + std::to_string(dogID);
    NodeActorAIState* state = static_cast<NodeActorAIState*>(blackBoard.get(stateID));
    if (state == nullptr)
    {
        // first time using this actor
        state = new NodeActorAIState(mID);
        blackBoard.addValue(stateID, state);
    }

    // check to see if last iteration with this actor was RUNNING
    unsigned int i = 0;
    if (state->mRunningChild > -1)
    {
        i = state->mRunningChild;
        state->mRunningChild = -1;
    }
    
    StatusType result = StatusType::FAILURE;
    for (; i < mChildren.size(); ++i)
    {        
        result = mChildren[i]->process(blackBoard);

        switch (result)
        {
        case StatusType::SUCCESS:
            return result;
        case StatusType::RUNNING:
            // save current index of running children to BB
            state->mRunningChild = i;
            return result;
            break;
        default:
        case StatusType::FAILURE:
            // do nothing
            break;
        }
    }

    return result;
}
