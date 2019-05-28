 
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
    mData.insert({ key, std::make_unique<void*>(value) });
}

void* Blackboard::get(const std::string& key)
{
    if (mData.count(key) > 0)
    {
        return mData[key].get();
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
        this->removeValue(std::to_string(nodeID) + "_" + std::to_string(i));
    }
}
