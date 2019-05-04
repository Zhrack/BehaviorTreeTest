#include "pch.h"
#include "Blackboard.h"

#include "Constants.h"

Blackboard::Blackboard()
{
}


Blackboard::~Blackboard()
{
    mData.clear();
}

void Blackboard::addValue(const std::pair<unsigned int, unsigned int>& key, void * value)
{
    if (mData.count(key) > 0)
    {
        this->removeValue(key);
    }
    mData.insert({ key, value });
}

void* Blackboard::get(const std::pair<unsigned int, unsigned int>& key)
{
    if (mData.count(key) > 0)
    {
        return mData[key];
    }

    return nullptr;
}

bool Blackboard::removeValue(const std::pair<unsigned int, unsigned int>& key)
{
    if (mData.erase(key) > 0)
    {
        return true;
    }
    return false;
}

void Blackboard::cleanAllByNodeID(unsigned int nodeID)
{
    unsigned int* numActors = static_cast<unsigned int*>(this->get(Constants::numberActors));
    for (unsigned int i = 0; i < *numActors; ++i)
    {
        auto pair = std::make_pair(nodeID, i);
        auto x = this->get(pair);
        if (x != nullptr)
        {
            delete x;
            x = nullptr;
        }
    }
}
