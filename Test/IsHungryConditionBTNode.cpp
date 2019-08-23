 
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

StatusType IsHungryConditionBTNode::process(Blackboard& externalBB)
{
    Dog* currentDog = static_cast<Dog*>(externalBB.get(Constants::currentDog));

    if (currentDog->getEnergy() < Constants::energyThreshold)
    {
        return StatusType::SUCCESS;
    }

    return StatusType::FAILURE;
}
