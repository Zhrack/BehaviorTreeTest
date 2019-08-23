#ifndef COMPOSITE_BT_NODE_H
#define COMPOSITE_BT_NODE_H

#include "BaseBTNode.h"

#include <memory>
#include <vector>

/// <summary>
/// Provides the functionalities to add new nodes, other functions implementations are forwarded to derived classes.
/// </summary>
/// <seealso cref="BaseBTNode" />
class CompositeBTNode : public BaseBTNode
{
public:
    CompositeBTNode();
    virtual ~CompositeBTNode();

    // Inherited via BaseBTNode
    virtual StatusType process(Blackboard& externalBB) = 0;

    virtual void addNode(BaseBTNode* newNode) override;

protected:
    std::vector< std::unique_ptr<BaseBTNode> > mChildren;
};


#endif // !COMPOSITE_BT_NODE_H