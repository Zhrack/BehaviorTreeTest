#ifndef BLACKBOARD_H
#define BLACKBOARD_H

#include <unordered_map>

/// <summary>
/// A generic blackboard to store values by string.
/// </summary>
class Blackboard
{
public:
    Blackboard();
    ~Blackboard();

    /// <summary>
    /// Adds a new key-value pair.
    /// </summary>
    /// <param name="key">The key.</param>
    /// <param name="value">The value.</param>
    void addValue(const std::string& key, void* value);

    /// <summary>
    /// Clears the blackboard.
    /// </summary>
    void clear();

private:
    std::unordered_map<std::string, void*> mData;
};

#endif // !BLACKBOARD_H
