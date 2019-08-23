#ifndef INVERTER_BT_NODE_H
#define INVERTER_BT_NODE_H

#include "DecoratorBTNode.h"


/// <summary>
/// Inverter decorator for the BT.
/// </summary>
/// <seealso cref="DecoratorBTNode" />
class InverterBTNode : public DecoratorBTNode
{
public:
    InverterBTNode();
    virtual ~InverterBTNode();

    // Inherited via DecoratorBTNode
    /// <summary>
    /// Processes this instance.
    /// </summary>
    /// <returns>A StatusType value.</returns>
    virtual StatusType process(Blackboard& externalBB) override;
};

#endif // !INVERTER_BT_NODE_H
