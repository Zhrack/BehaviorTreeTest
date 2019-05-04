#ifndef BORED_BT_NODE_H
#define BORED_BT_NODE_H

#include "BaseBTNode.h"


class IsBoredConditionBTNode : public BaseBTNode
{
public:
    IsBoredConditionBTNode(std::shared_ptr< Blackboard > bb);
    virtual ~IsBoredConditionBTNode();

    // Inherited via BaseBTNode
    /// <summary>
    /// Perform some setup work before calling process().
    /// </summary>
    virtual void initialize() override;

    /// <summary>
    /// Checks the level of boredom of the actor.
    /// </summary>
    /// <returns>
    /// The finishing status of the node, SUCCESS or FAILURE.
    /// </returns>
    virtual StatusType process() override;
    virtual void terminate() override;

    /// <summary>
    /// If called it will print an error on std::cout.
    /// </summary>
    /// <param name="newNode">.</param>
    virtual void addNode(std::unique_ptr<BaseBTNode> newNode) override;
};

#endif // !BORED_BT_NODE_H