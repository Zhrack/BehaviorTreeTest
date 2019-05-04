#ifndef AI_CONTROLLER_H
#define AI_CONTROLLER_H

#include "Blackboard.h"
#include "Dog.h"

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

    void update(const std::vector<Dog>& actors);

private:
    std::shared_ptr< Blackboard > mBlackBoard;
};


#endif // !AI_CONTROLLER_H