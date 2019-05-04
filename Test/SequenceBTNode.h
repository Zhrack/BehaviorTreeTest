#ifndef SEQUENCE_BT_NODE_H
#define SEQUENCE_BT_NODE_H

#include "CompositeBTNode.h"

class SequenceBTNode : public CompositeBTNode
{
public:
    SequenceBTNode(std::shared_ptr< Blackboard > bb);
    virtual ~SequenceBTNode();

    // Inherited via CompositeBTNode
    virtual void initialize() override;
    /// <summary>
    /// Processes this instance.
    /// </summary>
    /// <returns>A StatusType value.</returns>
    virtual StatusType process() override;
    virtual void terminate() override;
};

#endif // !SEQUENCE_BT_NODE_H
