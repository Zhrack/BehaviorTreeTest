 
#include "IdleBTNode.h"

#include "Dog.h"
#include "Constants.h"

#include <iostream>


IdleBTNode::IdleBTNode() : 
    LeafErrorBTNode()
{
}


IdleBTNode::~IdleBTNode()
{
    
}

StatusType IdleBTNode::process(Blackboard& externalBB)
{
    Dog* dog = static_cast<Dog*>(externalBB.get(Constants::currentDog));

    StatusType result = StatusType::RUNNING;

    // increase boredom and decrease hunger SLIGHTLY
    dog->setBoredom(dog->getBoredom() + static_cast<int>(Constants::boredomStep / 2));
    dog->setEnergy(dog->getEnergy() - static_cast<int>(Constants::energyStep / 2));
    
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
