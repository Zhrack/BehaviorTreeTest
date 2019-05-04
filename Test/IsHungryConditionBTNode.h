#ifndef HUNGRY_BT_NODE_H
#define HUNGRY_BT_NODE_H

#include "BaseBTNode.h"


/// <summary>
/// Condition that checks the energy status of the Dog.
/// </summary>
/// <seealso cref="BaseBTNode" />
class IsHungryConditionBTNode : public BaseBTNode
{
public:
    IsHungryConditionBTNode(std::shared_ptr< Blackboard > bb);
    virtual ~IsHungryConditionBTNode();

    // Inherited via BaseBTNode
    /// <summary>
    /// Perform some setup work before calling process().
    /// </summary>
    virtual void initialize() override;

    /// <summary>
    /// Checks the level of hunger of the actor.
    /// </summary>
    /// <returns>
    /// The finishing status of the node, SUCCESS or FAILURE.
    /// </returns>
    virtual StatusType process() override;

    virtual void terminate() override;
    /// <summary>
    /// If called it will print an error to std::cout.
    /// </summary>
    /// <param name="newNode">.</param>
    virtual void addNode(std::unique_ptr<BaseBTNode> newNode) override;
};


#endif // !HUNGRY_BT_NODE_H