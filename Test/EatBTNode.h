#ifndef EAT_ACTION_BT_NODE_H
#define EAT_ACTION_BT_NODE_H

#include "BaseBTNode.h"


class EatBTNode : public BaseBTNode
{
public:
    EatBTNode(std::shared_ptr< Blackboard > bb);
    virtual ~EatBTNode();

    // Inherited via BaseBTNode
    virtual void initialize() override;
    virtual StatusType process() override;
    virtual void terminate() override;
    virtual void addNode(std::unique_ptr<BaseBTNode> newNode) override;
};

#endif
