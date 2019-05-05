 
#include "InverterBTNode.h"


InverterBTNode::InverterBTNode(std::shared_ptr< Blackboard > bb) :
    DecoratorBTNode(bb)
{
}


InverterBTNode::~InverterBTNode()
{
}

void InverterBTNode::initialize()
{
}

StatusType InverterBTNode::process()
{
    auto result = mChild->process();

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

void InverterBTNode::terminate()
{
}
