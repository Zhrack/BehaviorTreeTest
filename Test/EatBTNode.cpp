 
#include "EatBTNode.h"

#include "Dog.h"
#include "BTState.h"
#include "NodeActorAIState.h"

#include <iostream>

EatBTNode::EatBTNode(std::shared_ptr< Blackboard > bb) :
    BaseBTNode(bb)
{
}


EatBTNode::~EatBTNode()
{
}

void EatBTNode::initialize()
{
}

StatusType EatBTNode::process()
{
    BTState* btState = static_cast<BTState*>(mBlackboard->get(Constants::currentBTState));

    Dog* dog = btState->currentDog;

    StatusType result = StatusType::RUNNING;

    // increase boredom and decrease hunger
    dog->setEnergy(dog->getEnergy() + Constants::hungerStep);

    // check for thresholds
    if (dog->getEnergy() < Constants::minEnergy)
    {
        dog->setEnergy(Constants::minEnergy);
        result =  StatusType::SUCCESS;
    }
    else if (dog->getEnergy() > Constants::maxEnergy)
    {
        dog->setEnergy(Constants::maxEnergy);
        result =  StatusType::SUCCESS;
    }

    std::cout << dog->getName() + " eats! (Energy " << dog->getEnergy() << ", Boredom " << dog->getBoredom() << ")" << std::endl;

    return result;
}

void EatBTNode::terminate()
{
}

void EatBTNode::addNode(std::unique_ptr<BaseBTNode> newNode)
{
    std::cout << "ERROR::EatBTNode: A node is being added to a leaf node!" << std::endl;
}
