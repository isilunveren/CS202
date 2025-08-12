//
//  Node.h
//  202hw4
//
//  Created by IŞIL ÜNVEREN on 14.05.2025.
//
#ifndef NODE_H
#define NODE_H
#include <string>
#include "AdjacentList.h"
using namespace std;
class Node {
public:
    string color;
    string name;
    
    AdjacentList* adjacents;

    Node(const string& status, const string& aName)
      : color(status), name(aName), adjacents(new AdjacentList())
    {}

    void addAdjacent(Node* adjNode, double weight) {
        adjacents->insert(adjNode, weight);
    }

    ~Node() {
        delete adjacents;
    }
};

#endif
