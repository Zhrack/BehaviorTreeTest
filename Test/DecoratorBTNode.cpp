 
#include "DecoratorBTNode.h"

#include <iostream>

DecoratorBTNode::DecoratorBTNode() :
    BaseBTNode(),
    mChild(nullptr)
{
}


DecoratorBTNode::~DecoratorBTNode()
{
}

void DecoratorBTNode::addNode(BaseBTNode* newNode)
{
    if (mChild)
    {
        std::cout << "ERROR::DecoratorBTNode: Trying to add multiple children" << std::endl;
        return;
    }

    mChild.reset(newNode);
}
