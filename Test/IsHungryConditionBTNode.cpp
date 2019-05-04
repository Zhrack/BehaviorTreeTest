#include "pch.h"
#include "IsHungryConditionBTNode.h"
#include "Dog.h"

#include "Constants.h"

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
    Dog* currentDog = static_cast<Dog*>(mBlackboard->get("currentDog"));
    
    if (currentDog == nullptr)
    {
        std::cout << "ERROR::IsHungryConditionBTNode: No currentDog found." << std::endl;
        return StatusType::FAILURE;
    }

    if (currentDog->getHunger() < Constants::hungryThreshold)
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