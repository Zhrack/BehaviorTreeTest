 
#include "IsHungryConditionBTNode.h"
#include "Dog.h"

#include "BTState.h"

#include <iostream>

IsHungryConditionBTNode::IsHungryConditionBTNode() :
    LeafErrorBTNode()
{
}

IsHungryConditionBTNode::~IsHungryConditionBTNode()
{
}

StatusType IsHungryConditionBTNode::process(Blackboard& blackBoard)
{
    BTState* btState = static_cast<BTState*>(blackBoard.get(Constants::currentBTState));

    if (btState->currentDog->getEnergy() < Constants::energyThreshold)
    {
        return StatusType::SUCCESS;
    }

    return StatusType::FAILURE;
}
