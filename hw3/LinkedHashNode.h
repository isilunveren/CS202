/**
* Title: Linked Hash Node
* Author : Isil Unveren
* ID: 22202444
* Section : 2
* Homework : 3
* Description : In this class a type of linked list node is implemented in order to items of hash table.
*/
#ifndef LinkedHashNode_h
#define LinkedHashNode_h

#include <string>
#include <iostream>
using namespace std;

class LinkedHashNode {
public:
    LinkedHashNode(){
        next = nullptr;
        item = "";
    }
    ~LinkedHashNode(){
        next = nullptr;
    }

    void setItem(string newItem){
        item = newItem;
    }
    LinkedHashNode* getNext(){
        return next;
    }
    void setNext(LinkedHashNode* newNext){
        next = newNext;
    }

    
    string getItem(){
        return item;
    }
    
    
private:
    LinkedHashNode* next;
    string item;
};
#endif
