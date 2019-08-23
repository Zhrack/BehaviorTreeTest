 
#include "EatBTNode.h"

#include "Dog.h"
#include "BTState.h"
#include "NodeActorAIState.h"

#include <iostream>

EatBTNode::EatBTNode() :
    LeafErrorBTNode()
{
}


EatBTNode::~EatBTNode()
{
}

StatusType EatBTNode::process(Blackboard& externalBB)
{
    Dog* dog = static_cast<Dog*>(externalBB.get(Constants::currentDog));

    StatusType result = StatusType::RUNNING;

    // increase boredom and decrease hunger
    dog->setEnergy(dog->getEnergy() + Constants::energyStep);

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

    std::cout << dog->getName() + " EATS! (Energy " << dog->getEnergy() << ", Boredom " << dog->getBoredom() << ")" << std::endl;

    return result;
}
