#ifndef PLAY_ACTION_BT_NODE_H
#define PLAY_ACTION_BT_NODE_H

#include "LeafErrorBTNode.h"


/// <summary>
/// Action node that perform the Play activity
/// </summary>
/// <seealso cref="BaseBTNode" />
class PlayBTNode : public LeafErrorBTNode
{
public:
    PlayBTNode();
    virtual ~PlayBTNode();

    // Inherited via BaseBTNode
    virtual StatusType process(Blackboard& blackBoard) override;
};

#endif //! PLAY_ACTION_BT_NODE_H
