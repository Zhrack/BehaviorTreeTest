#ifndef BLACKBOARD_H
#define BLACKBOARD_H

#include <unordered_map>
#include <memory>

/// <summary>
/// A blackboard to store key-values pairs. 
/// A template could generalize it, but it's not needed.
/// </summary>
class Blackboard
{
public:
    Blackboard();
    ~Blackboard();

    /// <summary>
    /// Adds a new key-value pair. If already present, it is overwritten.
    /// </summary>
    /// <param name="key">The key.</param>
    /// <param name="value">The value.</param>
    void addValue(const std::string& key, void* value);

    /// <summary>
    /// Gets the specified value.
    /// </summary>
    /// <param name="key">The key.</param>
    /// <returns>The value or nullptr if not found.</returns>
    void* get(const std::string& key);

    /// <summary>
    /// Removes the value.
    /// </summary>
    /// <param name="key">The key of the value to be removed.</param>
    /// <returns>True if successfully removed, false otherwise.</returns>
    bool removeValue(const std::string& key);

private:
    /// <summary>
    /// The data structure.
    /// </summary>
    std::unordered_map<
        std::string, 
        void* > mData;
};

#endif // !BLACKBOARD_H
