#include "pch.h"
#include "IsHungryBTNode.h"

#include <iostream>


IsHungryBTNode::IsHungryBTNode()
{
}


IsHungryBTNode::~IsHungryBTNode()
{
}

void IsHungryBTNode::initialize()
{
}

statusType IsHungryBTNode::process()
{
    return statusType();
}

void IsHungryBTNode::terminate()
{
}

void IsHungryBTNode::addNode(std::unique_ptr<BaseBTNode> newNode)
{
    std::cout << "ERROR: A node is being added to a leaf node!" << std::endl;
    throw -1;
}
