//
//  AdjacentList.h
//  202hw4
//
//  Created by IŞIL ÜNVEREN on 14.05.2025.
//
//
#ifndef AdjacentList_h
#define AdjacentList_h
#include "AdjacentNode.h"
#include "Node.h"
#include <string>

class AdjacentList {
public:
    AdjacentNode* first;
    int itemCount;
    
    AdjacentList(){
        first = nullptr;
        itemCount = 0;
    }
    void insert(Node* newAdj, double weight){
        AdjacentNode* newNode = new AdjacentNode();
        newNode->nodeAdj = newAdj;
        newNode->edgeWeight = weight;
        if (!first) {
            first = newNode;
        } else {
            AdjacentNode* cur = first;
            while (cur->next) cur = cur->next;
            cur->next = newNode;
        }
        itemCount++;
    }
    
    void remove(Node* nodeToRemove){
        while (first && first->nodeAdj->name == nodeToRemove->name) {
            AdjacentNode* temp = first;
            first = first->next;
            delete temp;
            itemCount--;
        }
        AdjacentNode* cur = first;
        while (cur && cur->next) {
            if (cur->next->nodeAdj->name == nodeToRemove->name) {
                AdjacentNode* temp = cur->next;
                cur->next = temp->next;
                delete temp;
                itemCount--;
            } else {
                cur = cur->next;
            }
        }
    }
};
#endif
