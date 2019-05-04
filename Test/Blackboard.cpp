#include "pch.h"
#include "Blackboard.h"


Blackboard::Blackboard()
{
}


Blackboard::~Blackboard()
{
}

void Blackboard::addValue(const std::string & key, void * value)
{
    mData.insert({ key, value });
}

void Blackboard::clear()
{
    mData.clear();
}
