#ifndef AI_CONTROLLER_H
#define AI_CONTROLLER_H

#include "Blackboard.h"
#include "Dog.h"
#include "BTState.h"
#include "BaseBTNode.h"

#include <memory>

/// <summary>
/// This class manages the Behavior Tree and its blackboard.
/// It builds the BT.
/// Every update, it receives a vector of actors and sequentially pass them to the blackboard as data to work on for the next BT round.
/// </summary>
class AIController
{
public:
    AIController();
    ~AIController();

    void initialize();

    void update(std::vector<Dog*>& actors);

    void terminate();

private:
    std::shared_ptr< Blackboard > mBlackBoard;
    std::unique_ptr< BaseBTNode > mRootNode;
};


#endif // !AI_CONTROLLER_H