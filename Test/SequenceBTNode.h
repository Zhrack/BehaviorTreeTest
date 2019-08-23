#ifndef SEQUENCE_BT_NODE_H
#define SEQUENCE_BT_NODE_H

#include "CompositeBTNode.h"

/// <summary>
/// Sequencer node for the BT.
/// </summary>
/// <seealso cref="CompositeBTNode" />
class SequenceBTNode : public CompositeBTNode
{
public:
    SequenceBTNode();
    virtual ~SequenceBTNode();

    // Inherited via CompositeBTNode
    /// <summary>
    /// Processes this instance.
    /// </summary>
    /// <returns>A StatusType value.</returns>
    virtual StatusType process(Blackboard& externalBB) override;
};

#endif // !SEQUENCE_BT_NODE_H
