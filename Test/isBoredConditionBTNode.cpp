 
#include "isBoredConditionBTNode.h"

#include "Dog.h"
#include "BTState.h"

#include <iostream>

IsBoredConditionBTNode::IsBoredConditionBTNode(std::shared_ptr< Blackboard > bb) :
    BaseBTNode(bb)
{
}


IsBoredConditionBTNode::~IsBoredConditionBTNode()
{
}

void IsBoredConditionBTNode::initialize()
{
}

StatusType IsBoredConditionBTNode::process()
{
    BTState* btState = static_cast<BTState*>(mBlackboard->get(Constants::currentBTState));

    if (btState->currentDog->getBoredom() > Constants::boredomThreshold)
    {
        return StatusType::SUCCESS;
    }

    return StatusType::FAILURE;
}

void IsBoredConditionBTNode::terminate()
{
}

void IsBoredConditionBTNode::addNode(std::unique_ptr<BaseBTNode> newNode)
{
    std::cout << "ERROR::isBoredConditionBTNode: A node is being added to a leaf node!" << std::endl;
}