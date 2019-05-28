#ifndef BORED_BT_NODE_H
#define BORED_BT_NODE_H

#include "LeafErrorBTNode.h"


/// <summary>
/// Condition that checks the boredom status of the Dog.
/// </summary>
/// <seealso cref="BaseBTNode" />
class IsBoredConditionBTNode : public LeafErrorBTNode
{
public:
    IsBoredConditionBTNode();
    virtual ~IsBoredConditionBTNode();

    // Inherited via BaseBTNode

    /// <summary>
    /// Checks the level of boredom of the actor.
    /// </summary>
    /// <returns>
    /// The finishing status of the node, SUCCESS or FAILURE.
    /// </returns>
    virtual StatusType process(Blackboard& blackBoard) override;
};

#endif // !BORED_BT_NODE_H