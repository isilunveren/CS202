/*
* Author : Isil Unveren
* ID: 22202444
* Section : 2
* Homework : 4
*/

#ifndef QUEUE_H
#define QUEUE_H

class Node;

class QueueNode {
public:
    Node* nodePtr;
    QueueNode* next;
    
    QueueNode(Node* node);
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;
    
public:
    Queue();
    ~Queue();
    
    void enqueue(Node* node);
    Node* dequeue();
    bool isEmpty();
};

#endif
