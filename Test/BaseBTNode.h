#ifndef BASE_BT_NODE_H
#define BASE_BT_NODE_H

#include <memory>
#include <vector>

enum statusType {
    FAILURE = 0,
    SUCCESS,
    RUNNING
};

class BaseBTNode
{
public:
    BaseBTNode();
    virtual ~BaseBTNode();

    /// <summary>
    /// Perform some setup work before calling process().
    /// </summary>
    virtual void initialize() = 0;

    /// <summary>
    /// Processes this node.
    /// </summary>
    /// <returns>The finishing status of the node.</returns>
    virtual statusType process() = 0;

    /// <summary>
    /// Perform cleanup duties if necessary.
    /// </summary>
    virtual void terminate() = 0;

    /// <summary>
    /// Adds the node to children list.
    /// </summary>
    /// <param name="newNode">The new node.</param>
    virtual void addNode(std::unique_ptr<BaseBTNode> newNode) = 0;
};


#endif // !BASE_BT_NODE_H