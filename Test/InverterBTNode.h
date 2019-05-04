#ifndef INVERTER_BT_NODE_H
#define INVERTER_BT_NODE_H

#include "DecoratorBTNode.h"


class InverterBTNode : public DecoratorBTNode
{
public:
    InverterBTNode(std::shared_ptr< Blackboard > bb);
    virtual ~InverterBTNode();

    // Inherited via DecoratorBTNode
    virtual void initialize() override;
    /// <summary>
    /// Processes this instance.
    /// </summary>
    /// <returns>A StatusType value.</returns>
    virtual StatusType process() override;
    virtual void terminate() override;
};

#endif // !INVERTER_BT_NODE_H
