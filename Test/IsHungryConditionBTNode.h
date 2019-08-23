#ifndef HUNGRY_BT_NODE_H
#define HUNGRY_BT_NODE_H

#include "LeafErrorBTNode.h"


/// <summary>
/// Condition that checks the energy status of the Dog.
/// </summary>
/// <seealso cref="BaseBTNode" />
class IsHungryConditionBTNode : public LeafErrorBTNode
{
public:
    IsHungryConditionBTNode();
    virtual ~IsHungryConditionBTNode();

    // Inherited via BaseBTNode

    /// <summary>
    /// Checks the level of hunger of the actor.
    /// </summary>
    /// <returns>
    /// The finishing status of the node, SUCCESS or FAILURE.
    /// </returns>
    virtual StatusType process(Blackboard& externalBB) override;
};


#endif // !HUNGRY_BT_NODE_H