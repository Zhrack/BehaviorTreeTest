#include "pch.h"
#include "DecoratorBTNode.h"

#include <iostream>

DecoratorBTNode::DecoratorBTNode(std::shared_ptr< Blackboard > bb) :
    BaseBTNode(bb),
    mChild(nullptr)
{
}


DecoratorBTNode::~DecoratorBTNode()
{
}

void DecoratorBTNode::addNode(std::unique_ptr<BaseBTNode> newNode)
{
    if (mChild)
    {
        std::cout << "ERROR::DecoratorBTNode: Trying to add multiple children" << std::endl;
        return;
    }

    mChild = std::move(newNode);
}
