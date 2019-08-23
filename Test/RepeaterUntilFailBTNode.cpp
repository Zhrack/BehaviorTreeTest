 
#include "RepeaterUntilFailBTNode.h"


RepeaterUntilFailBTNode::RepeaterUntilFailBTNode() :
    DecoratorBTNode()
{
}


RepeaterUntilFailBTNode::~RepeaterUntilFailBTNode()
{
}

StatusType RepeaterUntilFailBTNode::process(Blackboard& externalBB)
{
    auto result = mChild->process(externalBB);

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

