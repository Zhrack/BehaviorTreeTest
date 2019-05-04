#ifndef HUNGRY_BT_NODE_H
#define HUNGRY_BT_NODE_H

#include "BaseBTNode.h"


/// <summary>
/// 
/// </summary>
/// <seealso cref="BaseBTNode" />
class IsHungryBTNode : public BaseBTNode
{
public:
    IsHungryBTNode();
    virtual ~IsHungryBTNode();

    // Inherited via BaseBTNode
    virtual void initialize() override;
    virtual statusType process() override;
    virtual void terminate() override;
    /// <summary>
    /// If called it will throw an exception. A crash is really visible so it will force the user to control the node he's using.
    /// </summary>
    /// <param name="newNode">The new node.</param>
    virtual void addNode(std::unique_ptr<BaseBTNode> newNode) override;
};


#endif // !HUNGRY_BT_NODE_H