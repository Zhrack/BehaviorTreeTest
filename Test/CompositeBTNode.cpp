#include "pch.h"
#include "CompositeBTNode.h"


CompositeBTNode::CompositeBTNode() :
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
