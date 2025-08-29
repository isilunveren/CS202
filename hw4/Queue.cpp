/*
* Author : Isil Unveren
* ID: 22202444
* Section : 2
* Homework : 4
*/

#include "Queue.h"
#include "Node.h"

QueueNode::QueueNode(Node* node) {
    nodePtr = node;
    next = nullptr;
}

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::enqueue(Node* node) {
    QueueNode* newNode = new QueueNode(node);
    
    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

Node* Queue::dequeue() {
    if (isEmpty()) {
        return nullptr;
    }
    
    Node* node = front->nodePtr;
    QueueNode* temp = front;
    
    front = front->next;
    
    if (front == nullptr) {
        rear = nullptr;
    }
    
    delete temp;
    return node;
}

bool Queue::isEmpty() {
    return (front == nullptr);
}
