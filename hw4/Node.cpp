/*
* Author : Isil Unveren
* ID: 22202444
* Section : 2
* Homework : 4
*/

#include "Node.h"
#include "AdjacentList.h"

Node::Node(const string& nodeName, const string& nodeType) {
    name = nodeName;
    type = nodeType;
    isInfected = false;
    securityPatchTime = 0;
    malwareTime = 0;
    visited = false;
    parent = nullptr;
    nodeID = -1;
    adjacents = new AdjacentList();
}

Node::~Node() {
    delete adjacents;
}

void Node::addAdjacent(Node* adjNode, double weight) {
    adjacents->insert(adjNode, weight);
}

void Node::removeAdjacent(Node* nodeToRemove) {
    adjacents->remove(nodeToRemove);
}
