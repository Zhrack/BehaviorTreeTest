 
#include "RepeaterUntilFailBTNode.h"


RepeaterUntilFailBTNode::RepeaterUntilFailBTNode(std::shared_ptr< Blackboard > bb) :
    DecoratorBTNode(bb)
{
}


RepeaterUntilFailBTNode::~RepeaterUntilFailBTNode()
{
}

void RepeaterUntilFailBTNode::initialize()
{
}

StatusType RepeaterUntilFailBTNode::process()
{
    auto result = mChild->process();

    switch (result)
    {
    case FAILURE:
        return StatusType::SUCCESS;
        break;
    case SUCCESS:
    case RUNNING:
    default:
        return StatusType::RUNNING;
        break;
    }
}

void RepeaterUntilFailBTNode::terminate()
{
}
