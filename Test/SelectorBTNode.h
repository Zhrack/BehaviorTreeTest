#ifndef SELECTOR_BT_NODE_H
#define SELECTOR_BT_NODE_H

#include "CompositeBTNode.h"


class SelectorBTNode : public CompositeBTNode
{
public:
    SelectorBTNode(std::shared_ptr< Blackboard > bb);
    virtual ~SelectorBTNode();

    // Inherited via CompositeBTNode
    virtual void initialize() override;
    /// <summary>
    /// Processes this instance.
    /// </summary>
    /// <returns>A StatusType value.</returns>
    virtual StatusType process() override;
    virtual void terminate() override;
};

#endif // !SELECTOR_BT_NODE_H
