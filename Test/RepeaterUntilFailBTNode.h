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
    RepeaterUntilFailBTNode(std::shared_ptr< Blackboard > bb);
    virtual ~RepeaterUntilFailBTNode();

    // Inherited via DecoratorBTNode
    virtual void initialize() override;
    virtual StatusType process() override;
    virtual void terminate() override;
};

#endif // !REPEATER_UNTIL_FAIL_BT_NODE_H
