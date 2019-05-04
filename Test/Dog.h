#ifndef DOG_H
#define DOG_H

#include <string>

/// <summary>
/// Data structure for dogs.
/// Also a good boi. :)
/// </summary>
class Dog
{
public:
    Dog(const std::string& name, int hunger = 100, int boredom = 0);
    ~Dog();
    
    // Getters
    std::string getName() const;
    int getHunger() const;
    int getBoredom() const;

    // Setters
    void setHunger(int value);
    void setBoredom(int value);

private:
    /// <summary>
    /// The name of the doggo. Also its identifier.
    /// </summary>
    std::string mName;
    /// <summary>
    /// The hunger level.
    /// </summary>
    int mHunger;
    /// <summary>
    /// The boredom level.
    /// </summary>
    int mBoredom;
};

#endif // !DOG_H
