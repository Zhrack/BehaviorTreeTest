#ifndef COMPOSITE_BT_NODE_H
#define COMPOSITE_BT_NODE_H

#include "BaseBTNode.h"

#include <memory>
#include <vector>

/// <summary>
/// Adds the functionalities to add new nodes, other functions implementations are forwarded to derived classes.
/// </summary>
/// <seealso cref="BaseBTNode" />
class CompositeBTNode : public BaseBTNode
{
public:
    CompositeBTNode(std::shared_ptr< Blackboard > bb);
    virtual ~CompositeBTNode();

    // Inherited via BaseBTNode
    virtual void initialize() = 0;
    virtual StatusType process() = 0;
    virtual void terminate() = 0;

    virtual void addNode(std::unique_ptr<BaseBTNode> newNode) override;

protected:
    std::vector< std::unique_ptr<BaseBTNode> > mChildren;
};


#endif // !COMPOSITE_BT_NODE_H