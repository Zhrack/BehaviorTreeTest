 
#include "isBoredConditionBTNode.h"

#include "Dog.h"
#include "Constants.h"

#include <iostream>

IsBoredConditionBTNode::IsBoredConditionBTNode() :
    LeafErrorBTNode()
{
}


IsBoredConditionBTNode::~IsBoredConditionBTNode()
{
}

StatusType IsBoredConditionBTNode::process(Blackboard& externalBB)
{
    Dog* currentDog = static_cast<Dog*>(externalBB.get(Constants::currentDog));

    if (currentDog->getBoredom() > Constants::boredomThreshold)
    {
        return StatusType::SUCCESS;
    }

    return StatusType::FAILURE;
}
