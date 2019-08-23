 
#include "SelectorBTNode.h"

#include "Constants.h"
#include "Dog.h"

#include <string>
#include <iostream>

SelectorBTNode::SelectorBTNode() :
    CompositeBTNode()
{
}


SelectorBTNode::~SelectorBTNode()
{
}

StatusType SelectorBTNode::process(Blackboard& externalBB)
{
    Dog* dog = static_cast<Dog*>(externalBB.get(Constants::currentDog));
    auto currentRunningChild = static_cast<int*>(mBlackboard.get(Constants::currentChildRunning + std::to_string(dog->getID())));

    if (!currentRunningChild)
    {
        mBlackboard.addValue(Constants::currentChildRunning + std::to_string(dog->getID()), new int(-1));
        currentRunningChild = static_cast<int*>(mBlackboard.get(Constants::currentChildRunning + std::to_string(dog->getID())));
    }

    // check to see if last iteration with this actor was RUNNING
    unsigned int i = 0;
    if (*currentRunningChild > -1)
    {
        i = *currentRunningChild;
        *currentRunningChild = -1;
    }
    
    StatusType result = StatusType::FAILURE;
    for (; i < mChildren.size(); ++i)
    {        
        result = mChildren[i]->process(externalBB);

        switch (result)
        {
        case StatusType::SUCCESS:
            return result;
        case StatusType::RUNNING:
            // save current index of running children to BB
            *currentRunningChild = i;
            return result;
        default:
        case StatusType::FAILURE:
            // do nothing
            break;
        }
    }

    return result;
}
