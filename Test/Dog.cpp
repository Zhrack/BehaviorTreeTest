 
#include "Dog.h"

unsigned int Dog::nextID = 0;

Dog::Dog(const std::string& name, int hunger, int boredom) :
    mName(name),
    mEnergy(hunger),
    mBoredom(boredom),
    mID(nextID++)
{
}


Dog::~Dog()
{
}

std::string Dog::getName() const
{
    return mName;
}

int Dog::getEnergy() const
{
    return mEnergy;
}

int Dog::getBoredom() const
{
    return mBoredom;
}

unsigned int Dog::getID() const
{
    return mID;
}

void Dog::setEnergy(int value)
{
    this->mEnergy = value;
}

void Dog::setBoredom(int value)
{
    this->mBoredom = value;
}
