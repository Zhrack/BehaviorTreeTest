#ifndef SELECTOR_BT_NODE_H
#define SELECTOR_BT_NODE_H

#include "CompositeBTNode.h"


/// <summary>
/// Selector node for the BT.
/// </summary>
/// <seealso cref="CompositeBTNode" />
class SelectorBTNode : public CompositeBTNode
{
public:
    SelectorBTNode();
    virtual ~SelectorBTNode();

    // Inherited via CompositeBTNode
    /// <summary>
    /// Processes this instance.
    /// </summary>
    /// <returns>A StatusType value.</returns>
    virtual StatusType process(Blackboard& externalBB) override;
};

#endif // !SELECTOR_BT_NODE_H
