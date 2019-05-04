#include "pch.h"
#include "Blackboard.h"

#include "BTState.h"

Blackboard::Blackboard() :
    mData()
{
}


Blackboard::~Blackboard()
{
    mData.clear();
}

void Blackboard::addValue(const std::string& key, void * value)
{
    if (mData.count(key) > 0)
    {
        this->removeValue(key);
    }
    mData.insert({ key, value });
}

void* Blackboard::get(const std::string& key)
{
    if (mData.count(key) > 0)
    {
        return mData[key];
    }

    return nullptr;
}

bool Blackboard::removeValue(const std::string& key)
{
    if (mData.erase(key) > 0)
    {
        return true;
    }
    return false;
}

void Blackboard::cleanAllByNodeID(unsigned int nodeID)
{
    BTState* btState = static_cast<BTState*>(this->get(Constants::currentBTState));
    for (unsigned int i = 0; i < btState->numActors; ++i)
    {
        auto x = this->get(std::to_string(nodeID) + "_" + std::to_string(i));
        if (x != nullptr)
        {
            delete x;
            x = nullptr;
        }
    }
}
