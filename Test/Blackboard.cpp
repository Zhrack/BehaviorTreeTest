 
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

void Blackboard::cleanAllByActorID(unsigned int actorID)
{
    int* nodes = static_cast<int*>(this->get(Constants::numBTnodes));
    for (int i = 0; i < *nodes; ++i)
    {
        this->removeValue(std::to_string(i) + "_" + std::to_string(actorID));
    }
}
