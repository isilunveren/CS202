/*
* Author : Isil Unveren
* ID: 22202444
* Section : 2
* Homework : 4
*/

#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;
class AdjacentList;

class Node {
public:
    string name;
    string type;
    bool isInfected;
    double securityPatchTime;
    int malwareTime;
    bool visited;
    Node* parent;
    int nodeID;
    AdjacentList* adjacents;

    Node(const string& nodeName, const string& nodeType);
    ~Node();
    
    void addAdjacent(Node* adjNode, double weight);
    void removeAdjacent(Node* nodeToRemove);
};

#endif
