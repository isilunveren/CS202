/*
* Author : Isil Unveren
* ID: 22202444
* Section : 2
* Homework : 4
*/

#ifndef ADJACENT_NODE_H
#define ADJACENT_NODE_H
class Node;

class AdjacentNode {
public:
    double edgeWeight;
    Node* nodePtr;
    AdjacentNode* next;
    
    AdjacentNode(Node* node, double weight);
};

#endif 
