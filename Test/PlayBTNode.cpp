 
#include "PlayBTNode.h"

#include "Dog.h"
#include "BTState.h"
#include "NodeActorAIState.h"

#include <iostream>

PlayBTNode::PlayBTNode() :
    LeafErrorBTNode()
{
}


PlayBTNode::~PlayBTNode()
{
}


StatusType PlayBTNode::process(Blackboard& blackBoard)
{
    BTState* btState = static_cast<BTState*>(blackBoard.get(Constants::currentBTState));

    Dog* dog = btState->currentDog;

    StatusType result = StatusType::RUNNING;

    // decrease boredom and decrease hunger
    dog->setBoredom(dog->getBoredom() - Constants::boredomStep * 2);
    dog->setEnergy(dog->getEnergy() - Constants::energyStep * 2); // faster


    // check for thresholds
    if (dog->getBoredom() < Constants::minBoredom)
    {
        dog->setBoredom(Constants::minBoredom);
        result = StatusType::SUCCESS;
    }
    if (dog->getEnergy() < Constants::minEnergy)
    {
        dog->setEnergy(Constants::minEnergy);
        result = StatusType::SUCCESS;
    }

    std::cout << dog->getName() + " PLAYS with the ball! (Energy " << dog->getEnergy() << ", Boredom " << dog->getBoredom() << ")" << std::endl;

    return result;
}
