#ifndef NODE_ACTOR_AI_STATE_H
#define NODE_ACTOR_AI_STATE_H

/// <summary>
/// Small data structure to store mutable informations for a given (node, Dog) pair inside the BlackBoard.
/// </summary>
struct NodeActorAIState
{
    NodeActorAIState(int nodeID);

    /// <summary>
    /// The ID of the associated BT node.
    /// </summary>
    unsigned int mID;

    /// <summary>
    /// The index of the running child. If the last iteration didn't return RUNNING, this is -1.
    /// </summary>
    unsigned int mRunningChild;
};

#endif // !NODE_ACTOR_AI_STATE_H
