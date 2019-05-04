#ifndef IDLE_ACTION_BT_NODE_H
#define IDLE_ACTION_BT_NODE_H

#include "BaseBTNode.h"


class IdleBTNode : public BaseBTNode
{
public:
    IdleBTNode(std::shared_ptr< Blackboard > bb);
    virtual ~IdleBTNode();

    // Inherited via BaseBTNode
    virtual void initialize() override;
    virtual StatusType process() override;
    virtual void terminate() override;
    virtual void addNode(std::unique_ptr<BaseBTNode> newNode) override;
};

#endif // !IDLE_ACTION_BT_NODE_H