 
#include "BaseBTNode.h"

unsigned int BaseBTNode::nextID = 0;


BaseBTNode::BaseBTNode() :
    mID(nextID++)
{
}

BaseBTNode::~BaseBTNode()
{
}
