 
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
    mBlackBoard(),
    mRootNode(nullptr)
{
}


AIController::~AIController()
{
    BTState* state = static_cast<BTState*>(mBlackBoard.get(Constants::currentBTState));
    if (state != nullptr)
    {
        delete state;
        state = nullptr;
        mBlackBoard.removeValue(Constants::currentBTState);
    }
}

void AIController::initialize()
{
    int* numNodes = new int;
    mBlackBoard.addValue(Constants::currentBTState, new BTState());
    // build behavior tree
    mRootNode.reset(new SelectorBTNode());
    (*numNodes)++;

    // ------------------- IDLE BRANCH
    SequenceBTNode* idleSequence = new SequenceBTNode();
    (*numNodes)++;

    InverterBTNode* isHungryIdleInverterDecorator = new InverterBTNode();
    InverterBTNode* isBoredIdleInverterDecorator = new InverterBTNode();
    (*numNodes) += 2;

    // add to inverters
    isHungryIdleInverterDecorator->addNode(new IsHungryConditionBTNode());
    isBoredIdleInverterDecorator->addNode(new IsBoredConditionBTNode());
    (*numNodes) += 2;

    // add to idle sequence
    idleSequence->addNode(isHungryIdleInverterDecorator);
    idleSequence->addNode(isBoredIdleInverterDecorator);
    idleSequence->addNode(new IdleBTNode());
    (*numNodes)++;

    mRootNode->addNode(idleSequence);

    // ------------------- PLAY BRANCH
    SequenceBTNode* playSequence = new SequenceBTNode();
    (*numNodes)++;

    InverterBTNode* isHungryPlayInverterDecorator = new InverterBTNode();
    (*numNodes)++;

    // add to inverters
    isHungryPlayInverterDecorator->addNode(new IsHungryConditionBTNode());
    (*numNodes)++;

    // add to play sequence
    playSequence->addNode(isHungryPlayInverterDecorator);
    playSequence->addNode(new PlayBTNode());
    (*numNodes)++;

    mRootNode->addNode(playSequence);

    // ------------------- EAT BRANCH

    mRootNode->addNode(new EatBTNode());
    (*numNodes)++;

    mBlackBoard.addValue(Constants::numBTnodes, numNodes);
}

void AIController::update(std::vector<Dog*>& actors)
{
    BTState* btState = static_cast<BTState*>(mBlackBoard.get(Constants::currentBTState));
    btState->numActors = static_cast<unsigned int>(actors.size());

    std::cout << "---- NEW UPDATE CYCLE ----" << std::endl;
    std::cout << std::endl;

    // run BT for currentDog
    std::string resultText;
    for (auto it = actors.begin(); it != actors.end(); ++it)
    {
        // update currentDog value
        btState->currentDog = *it;
        auto result = mRootNode->process(mBlackBoard);

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

        std::cout << "BT for " << (*it)->getName() << " returns " << resultText << std::endl;
        std::cout << std::endl;
    }
}

void AIController::terminate()
{
}

void AIController::clearDataByActorID(unsigned int actorID)
{
    mBlackBoard.cleanAllByActorID(actorID);
}
