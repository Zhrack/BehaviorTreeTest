 
#include "InverterBTNode.h"


InverterBTNode::InverterBTNode() :
    DecoratorBTNode()
{
}


InverterBTNode::~InverterBTNode()
{
}

StatusType InverterBTNode::process(Blackboard& blackBoard)
{
    auto result = mChild->process(blackBoard);

    switch (result)
    {
    case FAILURE:
        return StatusType::SUCCESS;
        break;
    case RUNNING:
    case SUCCESS:
    default:
        return StatusType::FAILURE;
        break;
    }
}
