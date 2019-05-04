#ifndef PLAY_ACTION_BT_NODE_H
#define PLAY_ACTION_BT_NODE_H

#include "BaseBTNode.h"


/// <summary>
/// Action node that perform the Play activity
/// </summary>
/// <seealso cref="BaseBTNode" />
class PlayBTNode : public BaseBTNode
{
public:
    PlayBTNode(std::shared_ptr< Blackboard > bb);
    virtual ~PlayBTNode();

    // Inherited via BaseBTNode
    virtual void initialize() override;
    virtual StatusType process() override;
    virtual void terminate() override;
    virtual void addNode(std::unique_ptr<BaseBTNode> newNode) override;
};

#endif //! PLAY_ACTION_BT_NODE_H
