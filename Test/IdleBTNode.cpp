#include "pch.h"
#include "IdleBTNode.h"

#include "Dog.h"
#include "BTState.h"
#include "NodeActorAIState.h"

#include <iostream>


IdleBTNode::IdleBTNode(std::shared_ptr< Blackboard > bb) : 
    BaseBTNode(bb)
{
}


IdleBTNode::~IdleBTNode()
{
    
}

void IdleBTNode::initialize()
{
}

StatusType IdleBTNode::process()
{
    BTState* btState = static_cast<BTState*>(mBlackboard->get(Constants::currentBTState));

    Dog* dog = btState->currentDog;

    // increase boredom and decrease hunger
    dog->setBoredom(dog->getBoredom() + Constants::boredomStep);
    dog->setHunger(dog->getHunger() - Constants::hungerStep);

    std::cout << dog->getName() + " is waiting for you. (" << dog->getHunger() << ", " << dog->getBoredom() << ")" << std::endl;
    
    // check for thresholds
    if (dog->getBoredom() > Constants::maxBoredom || 
        dog->getHunger() < Constants::minHunger)
    {
        return StatusType::SUCCESS;
    }

    return StatusType::RUNNING;
}

void IdleBTNode::terminate()
{
}

void IdleBTNode::addNode(std::unique_ptr<BaseBTNode> newNode)
{
    std::cout << "ERROR::IdleBTNode: A node is being added to a leaf node!" << std::endl;
}
