//
//  Queue.h
//  202hw1
//
//  Created by IŞIL ÜNVEREN on 2.03.2025.
//
#ifndef Queue_h
#define Queue_h

#include "Node.h"

template <typename ItemType>
class Queue{
public:
    
    Queue(){
        first = nullptr;
        last = nullptr;
        count = 0;
    }
    
    Queue(const Queue& other){
        if(other.first == nullptr){
            first = nullptr;
            last = nullptr;
            count = 0;
        }
        else{
            Node<ItemType>* cur = other.front;
            while(cur != nullptr){
                enqueue(cur-> item);
                cur = cur -> next;
            }
        }
    }
    
    ~Queue(){
        while (front != nullptr){
            dequeue();
        }
    }
    
    void enqueue(ItemType& anItem){
        Node<ItemType>* newItem = new Node<ItemType>(anItem);
        if(first == nullptr){
            first = newItem;
            last = newItem;
        }
        else{
            last -> nextNodePtr = newItem;
            last = newItem;
        }
        count ++;
    }
    
    void dequeue(){
        if(front == nullptr) return;
        else{
            Node<ItemType>* holdFirst = first;
            first = first.nextNodePtr;
            if (first == nullptr){
                last = nullptr;
            }
            holdFirst.nextNodePtr = nullptr;
            delete holdFirst;
            count --;
        }
    }
    
    bool isEmpty() const {
        if(first == nullptr){
            return true;
        }
        return false;
    }
    
    Node<ItemType>* peekFront() const{
        return first;
    }

    Node<ItemType>* peekBack() const{
        return last;
    }
    
    int getItemCount() const{
        return count;
    }
private:
    Node<ItemType>* last;
    Node<ItemType>* first;
    int count;
};

#endif
