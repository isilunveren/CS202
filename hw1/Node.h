//
//  Node.h
//  202hw1
//
//  Created by IŞIL ÜNVEREN on 2.03.2025.
//
#ifndef Node_h
#define Node_h

template <typename ItemType>
class Node {
public:
    ItemType item;
    Node <ItemType>* nextNodePtr;
    
    Node(){
        nextNodePtr = nullptr;
    }
    
    Node(ItemType& anItem){
        item = anItem;
        nextNodePtr = nullptr;
    }
    
    Node(ItemType& anItem, Node<ItemType>* next){
        item = anItem;
        nextNodePtr = next;
    }
    
    ~Node(){
        delete nextNodePtr;
        nextNodePtr = nullptr;
    }
};
#endif

