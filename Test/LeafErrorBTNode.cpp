#include "LeafErrorBTNode.h"

#include <iostream>


LeafErrorBTNode::LeafErrorBTNode()
{
}


LeafErrorBTNode::~LeafErrorBTNode()
{
}

void LeafErrorBTNode::addNode(BaseBTNode* newNode)
{
    newNode;
    std::cout << "ERROR::LeafErrorBTNode: A node is being added to a leaf node!" << std::endl;
}
