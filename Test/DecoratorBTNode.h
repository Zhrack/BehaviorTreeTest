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
    DecoratorBTNode(std::shared_ptr< Blackboard > bb);
    virtual ~DecoratorBTNode();

    // Inherited via BaseBTNode
    virtual void initialize() = 0;
    virtual StatusType process() = 0;
    virtual void terminate() = 0;

    /// <summary>
    /// Adds the node.
    /// </summary>
    /// <param name="newNode">The new node.</param>
    virtual void addNode(std::unique_ptr<BaseBTNode> newNode) override;

protected:
    std::unique_ptr<BaseBTNode> mChild;

};

#endif // !DECORATOR_BT_NODE_H
