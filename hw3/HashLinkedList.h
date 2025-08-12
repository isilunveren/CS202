/**
* Title: Hash Linked List
* Author : Isil Unveren
* ID: 22202444
* Section : 2
* Homework : 3
* Description : In this class a type of linked list is implemented. This linked list holds items that have same hash code. There are methods that insert item, remove item, and search item in this class.
*/
#ifndef HashLinkedList_h
#define HashLinkedList_h
#include "LinkedHashNode.h"
#include <iostream>
using namespace std;

class HashLinkedList {
private:
    LinkedHashNode* first;
    int itemCount;
public:
    HashLinkedList(){
        first = nullptr;
        itemCount = 0;
    }
    ~HashLinkedList() {
      LinkedHashNode* cur = first;
      while (cur) {
        LinkedHashNode* nxt = cur->getNext();
        delete cur;
        cur = nxt;
      }
    }
    int getItemCount(){
        return itemCount;
    }
    
    bool insertItem(string itemName){
        bool isInserted = false;
        if(first == nullptr){
            LinkedHashNode* newNode = new LinkedHashNode();
            first = newNode;
            newNode -> setItem(itemName);
            newNode -> setNext(nullptr);
            itemCount ++;
            isInserted = true;
        }
        else if(!doesExist(itemName)){
            LinkedHashNode* curNode = first;
            while(curNode->getNext() != nullptr){
                curNode = curNode -> getNext();
            }
            LinkedHashNode* newNode = new LinkedHashNode();
            curNode -> setNext(newNode);
            newNode -> setItem(itemName);
            newNode -> setNext(nullptr);
            itemCount ++;
            isInserted = true;
        }
        return isInserted;
    }
    
    bool removeItem(string itemName){
        bool isRemoved = false;
        if(first == nullptr) return isRemoved;
        LinkedHashNode* curNode = first;
        
        while(curNode->getNext() != nullptr){
            if(curNode -> getNext() -> getItem() == itemName){
                LinkedHashNode* holdNode = curNode -> getNext();
                curNode -> setNext(holdNode->getNext());
                holdNode -> setNext(nullptr);
                delete holdNode;
                itemCount --;
                isRemoved = true;
                break;
            }
        }
        return isRemoved;
    }
    bool doesExist(string itemName){
        bool found = false;
        if(first == nullptr) return false;
        
        LinkedHashNode* curNode = first;
        while (curNode != nullptr && !found){
            if (curNode -> getItem() == itemName){
                found = true;
            }
            else{
                curNode = curNode -> getNext();
            }
        }
        return found;
    }

};
#endif
