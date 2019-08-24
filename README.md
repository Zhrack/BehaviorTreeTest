# BehaviorTreeTest

This Project is a small test written mainly during a weekend, with some cleanup and refactoring later.

Data is managed through a BlackBoard on every node for internal data, plus an external BB for the rest.

As a test, I simulated dogs, with 3 possible actions: Idle, Play and Eat. 
Each one modifies 2 parameters: boredom and energy.

A tree is built and simulated, with randomized initial states for every dog.
