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
    int getEnergy() const;
    int getBoredom() const;
    unsigned int getID() const;

    // Setters
    void setEnergy(int value);
    void setBoredom(int value);

private:
    /// <summary>
    /// The name of the doggo.
    /// </summary>
    std::string mName;
    /// <summary>
    /// The hunger level.
    /// </summary>
    int mEnergy;
    /// <summary>
    /// The boredom level.
    /// </summary>
    int mBoredom;
    /// <summary>
    /// Static data member to generate IDs for the dogs.
    /// </summary>
    static unsigned int nextID;

    /// <summary>
    /// The ID of this dog. Used to store and retrieve data on the BlackBoard.
    /// </summary>
    unsigned int mID;
};

#endif // !DOG_H
