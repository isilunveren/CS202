/*
* Author : Isil Unveren
* ID: 22202444
* Section : 2
* Homework : 4
*/

#include "AdjacentNode.h"
#include "Node.h"

AdjacentNode::AdjacentNode(Node* node, double weight) {
    nodePtr = node;
    edgeWeight = weight;
    next = nullptr;
}
