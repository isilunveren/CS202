/**
Author : Isil Unveren
ID: 22202444
Section : 2
Homework : 2
Description : This method is a queue class. It is implemented because of cool down process. It holds cooling down drones and packages that are assigned to these drones.
*/
#ifndef QUEUE_H
#define QUEUE_H

#include "Drone.h"
#include "Package.h"

class Queue {
private:
    struct Node {
        Drone drone;
        Package package;  // store by value
        int cooldownTick;
        Node* next;

        Node(Drone d, const Package& p, int tick) : drone(d), package(p), cooldownTick(tick), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int size;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(Drone d, Package p, int tick) {
        Node* newNode = new Node(d, p, tick);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    Package peekTopPackage(){
        return front->package;
    }
    
    void dequeue() {
        if (isEmpty()) return;
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;

        if (size == 0) {
            rear = nullptr;
        }
    }

    Drone dequeueDrone() {
        if (isEmpty()) return Drone(-1, 0, 0);
        Drone droneData = front->drone;
        dequeue();
        return droneData;
    }

    Package dequeuePackage() {
        if (isEmpty()) {
            return Package();
        }
        Package packageData = front->package;
        dequeue();
        return packageData;
    }

    int peekCooldownTick() {
        return isEmpty() ? -1 : front->cooldownTick;
    }
};

#endif
