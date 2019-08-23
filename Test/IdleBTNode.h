#ifndef IDLE_ACTION_BT_NODE_H
#define IDLE_ACTION_BT_NODE_H

#include "LeafErrorBTNode.h"


/// <summary>
/// Action node that perform the Idle activity
/// </summary>
/// <seealso cref="BaseBTNode" />
class IdleBTNode : public LeafErrorBTNode
{
public:
    IdleBTNode();
    virtual ~IdleBTNode();

    // Inherited via BaseBTNode
    virtual StatusType process(Blackboard& externalBB) override;
};

#endif // !IDLE_ACTION_BT_NODE_H
