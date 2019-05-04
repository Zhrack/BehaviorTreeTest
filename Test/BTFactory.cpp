#include "pch.h"
#include "BTFactory.h"


BTFactory::BTFactory()
{
}


BTFactory::~BTFactory()
{
}

std::unique_ptr<BaseBTNode> BTFactory::getDogBehavior()
{
    return std::unique_ptr<BaseBTNode>();
}