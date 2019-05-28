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
    BaseBTNode();
    virtual ~BaseBTNode();

    /// <summary>
    /// Processes this node.
    /// </summary>
    /// <returns>The finishing status of the node.</returns>
    virtual StatusType process(Blackboard& blackBoard) = 0;

    /// <summary>
    /// Adds the node to children list.
    /// </summary>
    /// <param name="newNode">The new node.</param>
    virtual void addNode(BaseBTNode* newNode) = 0;

protected:
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