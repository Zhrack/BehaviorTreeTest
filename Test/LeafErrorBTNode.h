#ifndef LEAF_ERROR_BT_NODE_H
#define LEAF_ERROR_BT_NODE_H

#include "BaseBTNode.h"

class LeafErrorBTNode : public BaseBTNode
{
public:
    LeafErrorBTNode();
    virtual ~LeafErrorBTNode();

    // Inherited via BaseBTNode
    virtual void addNode(BaseBTNode* newNode) override;
};

#endif // !LEAF_ERROR_BT_NODE_H
