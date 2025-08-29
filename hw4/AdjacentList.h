/*
* Author : Isil Unveren
* ID: 22202444
* Section : 2
* Homework : 4
*/

#ifndef ADJACENT_LIST_H
#define ADJACENT_LIST_H
#include "AdjacentNode.h"

class AdjacentList {
public:
    AdjacentNode* head;
    
    AdjacentList();
    ~AdjacentList();
    
    void insert(Node* newAdj, double weight);
    void remove(Node* nodeToRemove);
};

#endif
