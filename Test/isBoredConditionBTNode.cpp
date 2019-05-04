 
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

    // retrieve node state data for this actor
    auto stateID = std::make_pair(mID, btState->currentDog->getID());

    if (btState->currentDog->getBoredom() > Constants::boredomThreshold)
    {
        return StatusType::FAILURE;
    }

    return StatusType::SUCCESS;
}

void IsBoredConditionBTNode::terminate()
{
}

void IsBoredConditionBTNode::addNode(std::unique_ptr<BaseBTNode> newNode)
{
    std::cout << "ERROR::isBoredConditionBTNode: A node is being added to a leaf node!" << std::endl;
}