 
#include "BaseBTNode.h"

unsigned int BaseBTNode::nextID = 0;


BaseBTNode::BaseBTNode(std::shared_ptr< Blackboard > bb) :
    mBlackboard(bb),
    mID(nextID++)
{
}


BaseBTNode::~BaseBTNode()
{
    mBlackboard->cleanAllByNodeID(mID);
}
