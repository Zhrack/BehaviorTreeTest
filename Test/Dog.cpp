#include "pch.h"
#include "Dog.h"

unsigned int Dog::nextID = 0;

Dog::Dog(const std::string& name, int hunger, int boredom) :
    mName(name),
    mHunger(hunger),
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

int Dog::getHunger() const
{
    return mHunger;
}

int Dog::getBoredom() const
{
    return mBoredom;
}

unsigned int Dog::getID() const
{
    return mID;
}

void Dog::setHunger(int value)
{
    this->mHunger = value;
}

void Dog::setBoredom(int value)
{
    this->mBoredom = value;
}
