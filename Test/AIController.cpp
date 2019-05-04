#include "pch.h"
#include "AIController.h"

#include "Constants.h"
#include "Dog.h"
#include <iostream>

#include "SelectorBTNode.h"
#include "SequenceBTNode.h"
#include "InverterBTNode.h"
#include "isBoredConditionBTNode.h"
#include "IsHungryConditionBTNode.h"
#include "IdleBTNode.h"
#include "PlayBTNode.h"
#include "EatBTNode.h"

AIController::AIController() :
    mBlackBoard(new Blackboard()),
    mRootNode(nullptr)
{
    mBlackBoard->addValue(Constants::currentBTState, new BTState());
}


AIController::~AIController()
{
    BTState* state = static_cast<BTState*>(mBlackBoard->get(Constants::currentBTState));
    if (state != nullptr)
    {
        delete state;
        state = nullptr;
        mBlackBoard->removeValue(Constants::currentBTState);
    }
}

void AIController::initialize()
{
    // build behavior tree
    mRootNode.reset(new SelectorBTNode(mBlackBoard));

    // ------------------- IDLE BRANCH
    std::unique_ptr<SequenceBTNode> idleSequence(new SequenceBTNode(mBlackBoard));

    std::unique_ptr<IsBoredConditionBTNode> isBoredIdleCondition(new IsBoredConditionBTNode(mBlackBoard));
    std::unique_ptr<IsHungryConditionBTNode> isHungryIdleCondition(new IsHungryConditionBTNode(mBlackBoard));

    std::unique_ptr<IdleBTNode> idleAction(new IdleBTNode(mBlackBoard));

    // add to idle sequence
    idleSequence->addNode(std::move(isHungryIdleCondition));
    idleSequence->addNode(std::move(isBoredIdleCondition));
    idleSequence->addNode(std::move(idleAction));

    mRootNode->addNode(std::move(idleSequence));

    // ------------------- PLAY BRANCH
    std::unique_ptr<SequenceBTNode> playSequence(new SequenceBTNode(mBlackBoard));

    std::unique_ptr<IsHungryConditionBTNode> isHungryPlayCondition(new IsHungryConditionBTNode(mBlackBoard));
    
    std::unique_ptr<PlayBTNode> playAction(new PlayBTNode(mBlackBoard));

    // add to play sequence
    playSequence->addNode(std::move(isHungryPlayCondition));
    playSequence->addNode(std::move(playAction));

    mRootNode->addNode(std::move(playSequence));

    // ------------------- EAT BRANCH

    std::unique_ptr<EatBTNode> eatAction(new EatBTNode(mBlackBoard));

    // add to play sequence
    //playSequence->addNode(std::move(isHungryPlayCondition));
    //playSequence->addNode(std::move(playAction));

    mRootNode->addNode(std::move(eatAction));

}

void AIController::update(std::vector<Dog*>& actors)
{
    // TODO: Save. Insert all actors inside it.
    // TODO: insert a "currentDog" for the next run of BT. 
    BTState* btState = static_cast<BTState*>(mBlackBoard->get(Constants::currentBTState));
    btState->numActors = actors.size();

    // run BT for currentDog
    std::string resultText;
    for (auto it = actors.begin(); it != actors.end(); ++it)
    {
        // update currentDog value
        btState->currentDog = *it;
        auto result = mRootNode->process();

        switch (result)
        {
        case FAILURE:
            resultText = "FAILURE";
            break;
        case SUCCESS:
            resultText = "SUCCESS";
            break;
        case RUNNING:
            resultText = "RUNNING";
            break;
        default:
            break;
        }

        std::cout << "BT for dog " << (*it)->getName() << " returns " << resultText << std::endl;
    }
}

void AIController::terminate()
{
}
