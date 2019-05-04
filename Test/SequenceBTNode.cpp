#include "pch.h"
#include "SequenceBTNode.h"

#include "Constants.h"
#include "Dog.h"
#include "NodeActorAIState.h"

#include <string>
#include <iostream>

SequenceBTNode::SequenceBTNode(std::shared_ptr< Blackboard > bb) :
    CompositeBTNode(bb)
{
}


SequenceBTNode::~SequenceBTNode()
{
    mBlackboard->cleanAllByNodeID(mID);
}

void SequenceBTNode::initialize()
{
}

StatusType SequenceBTNode::process()
{
    Dog* currentDog = static_cast<Dog*>(mBlackboard->get(Constants::currentDog));
    if (currentDog == nullptr)
    {
        std::cout << "ERROR::SequenceBTNode: CurrentDog is nullptr" << std::endl;
        return StatusType::FAILURE;
    }
    // retrieve node state data for this actor
    auto stateID = std::make_pair(mID, currentDog->getID());
    NodeActorAIState* state = static_cast<NodeActorAIState*>(mBlackboard->get(stateID));
    if (state == nullptr)
    {
        // first time using this actor
        state = new NodeActorAIState(mID);
        mBlackboard->addValue(stateID, state);
    }

    // check to see if last iteration with this actor was RUNNING
    unsigned int i = 0;
    if (state->mRunningChild > -1)
    {
        i = state->mRunningChild;
        state->mRunningChild = -1;
    }


    for (; i < mChildren.size(); ++i)
    {
        auto result = mChildren[i]->process();

        switch (result)
        {
        case StatusType::FAILURE:
            return result;
        case StatusType::RUNNING:
            // save current index of running children to BB
            state->mRunningChild = i;
            return result;
            break;
        default:
        case StatusType::SUCCESS:
            // do nothing
            break;
        }
    }
}

void SequenceBTNode::terminate()
{
}
