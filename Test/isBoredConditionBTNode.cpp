 
#include "isBoredConditionBTNode.h"

#include "Dog.h"
#include "BTState.h"

#include <iostream>

IsBoredConditionBTNode::IsBoredConditionBTNode() :
    LeafErrorBTNode()
{
}


IsBoredConditionBTNode::~IsBoredConditionBTNode()
{
}

StatusType IsBoredConditionBTNode::process(Blackboard& blackBoard)
{
    BTState* btState = static_cast<BTState*>(blackBoard.get(Constants::currentBTState));

    if (btState->currentDog->getBoredom() > Constants::boredomThreshold)
    {
        return StatusType::SUCCESS;
    }

    return StatusType::FAILURE;
}
