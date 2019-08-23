#ifndef EAT_ACTION_BT_NODE_H
#define EAT_ACTION_BT_NODE_H

#include "LeafErrorBTNode.h"


/// <summary>
/// Action node that perform the Eat activity.
/// </summary>
/// <seealso cref="BaseBTNode" />
class EatBTNode : public LeafErrorBTNode
{
public:
    EatBTNode();
    virtual ~EatBTNode();

    // Inherited via LeafErrorBTNode
    virtual StatusType process(Blackboard& externalBB) override;
};

#endif
