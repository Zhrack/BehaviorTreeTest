#ifndef AI_CONTROLLER_H
#define AI_CONTROLLER_H

/// <summary>
/// This class manages the Behavior Tree and its blackboard.
/// It builds the BT 
/// It receives a vector of actors and sequentially pass them to the blackboard as data to work on for the BT
/// </summary>
class AIController
{
public:
    AIController();
    ~AIController();
};


#endif // !AI_CONTROLLER_H