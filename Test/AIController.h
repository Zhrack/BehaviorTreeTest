#ifndef AI_CONTROLLER_H
#define AI_CONTROLLER_H

#include "Blackboard.h"
#include "Dog.h"
#include "BTState.h"
#include "BaseBTNode.h"

#include <memory>

/// <summary>
/// This class manages the Behavior Tree and its blackboard.
/// It builds the BT inside the initialize() function.
/// Every update, it receives a vector of actors and sequentially pass them to the blackboard as data to work on for the next BT cycle.
/// </summary>
class AIController
{
public:
    AIController();
    ~AIController();

    /// <summary>
    /// Initializes this instance and costructs the Behavior Tree.
    /// </summary>
    void initialize();

    /// <summary>
    /// Updates the the input actors with a new cycle of BT for every element in the vector.
    /// </summary>
    /// <param name="actors">The actors.</param>
    void update(std::vector<Dog*>& actors);

    void terminate();

    /// <summary>
    /// Clears the data by actor identifier.
    /// </summary>
    /// <param name="actorID">The actor identifier.</param>
    void clearDataByActorID(unsigned int actorID);

private:
    /// <summary>
    /// The blackboard that supports stateful data for the BT.
    /// </summary>
    Blackboard mBlackBoard;
    /// <summary>
    /// The root node of the Behavior Tree.
    /// </summary>
    std::unique_ptr< BaseBTNode > mRootNode;
};


#endif // !AI_CONTROLLER_H