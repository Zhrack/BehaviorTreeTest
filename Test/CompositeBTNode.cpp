 
#include "CompositeBTNode.h"


CompositeBTNode::CompositeBTNode(std::shared_ptr< Blackboard > bb) :
   BaseBTNode(bb),
    mChildren()
{
}

CompositeBTNode::~CompositeBTNode()
{
}


void CompositeBTNode::addNode(std::unique_ptr<BaseBTNode> newNode)
{
    this->mChildren.push_back(std::move(newNode));
}
