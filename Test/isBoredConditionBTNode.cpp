#include "pch.h"
#include "isBoredConditionBTNode.h"

#include "Dog.h"
#include "Constants.h"

#include <iostream>

isBoredConditionBTNode::isBoredConditionBTNode(std::shared_ptr< Blackboard > bb) :
    BaseBTNode(bb)
{
}


isBoredConditionBTNode::~isBoredConditionBTNode()
{
}

void isBoredConditionBTNode::initialize()
{
}

StatusType isBoredConditionBTNode::process()
{
    Dog* currentDog = static_cast<Dog*>(mBlackboard->get("currentDog"));

    if (currentDog == nullptr)
    {
        std::cout << "ERROR::isBoredConditionBTNode: No currentDog found." << std::endl;
        return StatusType::FAILURE;
    }

    if (currentDog->getBoredom() > Constants::boredomThreshold)
    {
        return StatusType::FAILURE;
    }

    return StatusType::SUCCESS;
}

void isBoredConditionBTNode::terminate()
{
}

void isBoredConditionBTNode::addNode(std::unique_ptr<BaseBTNode> newNode)
{
    std::cout << "ERROR::isBoredConditionBTNode: A node is being added to a leaf node!" << std::endl;
}