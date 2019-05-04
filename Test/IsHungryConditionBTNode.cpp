#include "pch.h"
#include "IsHungryConditionBTNode.h"
#include "Dog.h"

#include "BTState.h"

#include <iostream>

IsHungryConditionBTNode::IsHungryConditionBTNode(std::shared_ptr< Blackboard > bb) :
    BaseBTNode(bb)
{
}

IsHungryConditionBTNode::~IsHungryConditionBTNode()
{
}

void IsHungryConditionBTNode::initialize()
{
}

StatusType IsHungryConditionBTNode::process()
{
    BTState* btState = static_cast<BTState*>(mBlackboard->get(Constants::currentBTState));

    // retrieve node state data for this actor
    auto stateID = std::make_pair(mID, btState->currentDog->getID());

    if (btState->currentDog->getHunger() < Constants::hungryThreshold)
    {
        return StatusType::FAILURE;
    }

    return StatusType::SUCCESS;
}

void IsHungryConditionBTNode::terminate()
{
}

void IsHungryConditionBTNode::addNode(std::unique_ptr<BaseBTNode> newNode)
{
    std::cout << "ERROR::IsHungryConditionBTNode: A node is being added to a leaf node!" << std::endl;
}
