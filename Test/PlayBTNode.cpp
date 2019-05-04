#include "pch.h"
#include "PlayBTNode.h"

#include "Dog.h"
#include "BTState.h"
#include "NodeActorAIState.h"

#include <iostream>

PlayBTNode::PlayBTNode(std::shared_ptr< Blackboard > bb) :
    BaseBTNode(bb)
{
}


PlayBTNode::~PlayBTNode()
{
}

void PlayBTNode::initialize()
{
}

StatusType PlayBTNode::process()
{
    BTState* btState = static_cast<BTState*>(mBlackboard->get(Constants::currentBTState));

    Dog* dog = btState->currentDog;

    // increase boredom and decrease hunger
    dog->setBoredom(dog->getBoredom() - Constants::boredomStep * 2);
    dog->setEnergy(dog->getEnergy() - Constants::hungerStep * 2); // faster

    std::cout << dog->getName() + " plays with the ball! (Energy " << dog->getEnergy() << ", Boredom " << dog->getBoredom() << ")" << std::endl;

    // check for thresholds
    if (dog->getBoredom() < Constants::minBoredom)
    {
        dog->setBoredom(Constants::minBoredom);
        return StatusType::SUCCESS;
    }
    else if (dog->getEnergy() < Constants::minEnergy)
    {
        dog->setEnergy(Constants::minEnergy);
        return StatusType::SUCCESS;
    }

    return StatusType::RUNNING;
}

void PlayBTNode::terminate()
{
}

void PlayBTNode::addNode(std::unique_ptr<BaseBTNode> newNode)
{
    std::cout << "ERROR::PlayBTNode: A node is being added to a leaf node!" << std::endl;
}
