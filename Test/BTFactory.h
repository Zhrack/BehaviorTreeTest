#ifndef BT_FACTORY_H
#define BT_FACTORY_H

#include "BaseBTNode.h"
#include <memory>

class BTFactory
{
public:
    BTFactory();
    ~BTFactory();

    std::unique_ptr<BaseBTNode> getDogBehavior();
};


#endif // !BT_FACTORY_H