 
#include "CompositeBTNode.h"


CompositeBTNode::CompositeBTNode() :
   BaseBTNode(),
    mChildren()
{
}

CompositeBTNode::~CompositeBTNode()
{
}


void CompositeBTNode::addNode(BaseBTNode* newNode)
{
    std::unique_ptr<BaseBTNode> node(newNode);
    this->mChildren.push_back(std::move(node));
}
