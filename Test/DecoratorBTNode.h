#ifndef DECORATOR_BT_NODE_H
#define DECORATOR_BT_NODE_H

#include "BaseBTNode.h"

/// <summary>
/// Base class for Decorator-type nodes.
/// Since they cann't have multiple children, they derive directly from BaseBTNode.
/// </summary>
/// <seealso cref="BaseBTNode" />
class DecoratorBTNode : public BaseBTNode
{
public:
    DecoratorBTNode();
    virtual ~DecoratorBTNode();

    // Inherited via BaseBTNode
    virtual StatusType process(Blackboard& blackBoard) = 0;

    /// <summary>
    /// Adds the node.
    /// </summary>
    /// <param name="newNode">The new node.</param>
    virtual void addNode(BaseBTNode* newNode) override;

protected:
    std::unique_ptr<BaseBTNode> mChild;

};

#endif // !DECORATOR_BT_NODE_H
