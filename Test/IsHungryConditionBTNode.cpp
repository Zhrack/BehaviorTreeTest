#include "pch.h"
#include "IsHungryConditionBTNode.h"

#include <iostream>


IsHungryConditionBTNode::IsHungryConditionBTNode()
{
}

IsHungryConditionBTNode::~IsHungryConditionBTNode()
{
}

void IsHungryConditionBTNode::initialize()
{
}

statusType IsHungryConditionBTNode::process()
{
    return statusType();
}

void IsHungryConditionBTNode::terminate()
{
}

void IsHungryConditionBTNode::addNode(std::unique_ptr<BaseBTNode> newNode)
{
    std::cout << "ERROR: A node is being added to a leaf node!" << std::endl;
    throw -1;
}
