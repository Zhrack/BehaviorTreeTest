#ifndef REPEATER_UNTIL_FAIL_BT_NODE_H
#define REPEATER_UNTIL_FAIL_BT_NODE_H

#include "DecoratorBTNode.h"


/// <summary>
/// Repeater decorator for the BT. Return SUCCESS only on FAILURE of child node.
/// </summary>
/// <seealso cref="DecoratorBTNode" />
class RepeaterUntilFailBTNode : public DecoratorBTNode
{
public:
    RepeaterUntilFailBTNode();
    virtual ~RepeaterUntilFailBTNode();

    // Inherited via DecoratorBTNode
    virtual StatusType process(Blackboard& blackBoard) override;
};

#endif // !REPEATER_UNTIL_FAIL_BT_NODE_H
