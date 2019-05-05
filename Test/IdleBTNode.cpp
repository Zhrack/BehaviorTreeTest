 
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

    StatusType result = StatusType::RUNNING;

    // increase boredom and decrease hunger
    dog->setBoredom(dog->getBoredom() + Constants::boredomStep);
    dog->setEnergy(dog->getEnergy() - Constants::energyStep);
    
    // check for thresholds
    if (dog->getBoredom() > Constants::maxBoredom)
    {
        dog->setBoredom(Constants::maxBoredom);
        result =  StatusType::SUCCESS;
    }
    if (dog->getEnergy() < Constants::minEnergy)
    {
        dog->setEnergy(Constants::minEnergy);
        result =  StatusType::SUCCESS;
    }

    std::cout << dog->getName() + " is waiting for you. (Energy " << dog->getEnergy() << ", Boredom " << dog->getBoredom() << ")" << std::endl;

    return result;
}

void IdleBTNode::terminate()
{
}

void IdleBTNode::addNode(std::unique_ptr<BaseBTNode> newNode)
{
    std::cout << "ERROR::IdleBTNode: A node is being added to a leaf node!" << std::endl;
}
