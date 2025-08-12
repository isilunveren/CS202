//
//  AdjacentNode.h
//  202hw4
//
//  Created by IŞIL ÜNVEREN on 14.05.2025.
//
#ifndef AdjacentNode_h
#define AdjacentNode_h
#include "Node.h"
#include <string>
class AdjacentNode {
public:
    double edgeWeight;
    Node* nodeAdj;
    AdjacentNode* next;
    AdjacentNode(){
        edgeWeight = 0.0;
        nodeAdj = nullptr;
        next = nullptr;
    }
};
#endif
