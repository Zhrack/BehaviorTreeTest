 
#include "RepeaterUntilFailBTNode.h"


RepeaterUntilFailBTNode::RepeaterUntilFailBTNode() :
    DecoratorBTNode()
{
}


RepeaterUntilFailBTNode::~RepeaterUntilFailBTNode()
{
}

StatusType RepeaterUntilFailBTNode::process(Blackboard& blackBoard)
{
    auto result = mChild->process(blackBoard);

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

