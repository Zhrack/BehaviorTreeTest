#include "pch.h"
#include "Dog.h"


Dog::Dog(const std::string& name, int hunger, int boredom) :
    mName(name),
    mHunger(hunger),
    mBoredom(boredom)
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

void Dog::setHunger(int value)
{
    this->mHunger = value;
}

void Dog::setBoredom(int value)
{
    this->mBoredom = value;
}
