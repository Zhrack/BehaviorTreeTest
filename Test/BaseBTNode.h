#ifndef BASE_BT_NODE_H
#define BASE_BT_NODE_H

#include <memory>
#include <vector>

#include "Blackboard.h"

/// <summary>
/// Possible return statuses of a BT node.
/// </summary>
enum StatusType
{
    FAILURE = 0,
    SUCCESS,
    RUNNING
};

/// <summary>
/// Based on the composite pattern, with children-related operations designed for uniformity.
/// This is the base class for the hierarchy and defines the interface for the Behavior Tree.
/// </summary>
class BaseBTNode
{
public:
    BaseBTNode(std::shared_ptr< Blackboard > bb);
    virtual ~BaseBTNode();

    /// <summary>
    /// Perform some setup work before calling process().
    /// </summary>
    virtual void initialize() = 0;

    /// <summary>
    /// Processes this node.
    /// </summary>
    /// <returns>The finishing status of the node.</returns>
    virtual StatusType process() = 0;

    /// <summary>
    /// Perform cleanup duties if necessary.
    /// </summary>
    virtual void terminate() = 0;

    /// <summary>
    /// Adds the node to children list.
    /// </summary>
    /// <param name="newNode">The new node.</param>
    virtual void addNode(std::unique_ptr<BaseBTNode> newNode) = 0;

protected:
    /// <summary>
    /// Refcounted reference to the AIController's BlackBoard
    /// </summary>
    std::shared_ptr< Blackboard > mBlackboard;

    /// <summary>
    /// Static data member to generate IDs for the nodes.
    /// </summary>
    static unsigned int nextID;

    /// <summary>
    /// The ID of this node. Used to store and retrieve data on the BlackBoard.
    /// </summary>
    unsigned int mID;
};


#endif // !BASE_BT_NODE_H