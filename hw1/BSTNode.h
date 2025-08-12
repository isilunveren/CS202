//
//  BSTNode.h
//  202hw1
//
//  Created by IŞIL ÜNVEREN on 3.03.2025.
//
#ifndef BSTNode_h
#define BSTNode_h

class BSTNode {
public:
    int key;
    BSTNode* leftChildPtr;
    BSTNode* rightChildPtr;
    
    BSTNode(){
        key = 0;
        leftChildPtr = nullptr;
        rightChildPtr = nullptr;
    }
    
    BSTNode(int value, BSTNode* left, BSTNode* right) {
        key = value;
        leftChildPtr = left;
        rightChildPtr = right;
    }

    ~BSTNode (){
        leftChildPtr = nullptr;
        rightChildPtr = nullptr;
    }
};

#endif;
