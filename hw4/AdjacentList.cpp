/*
* Author : Isil Unveren
* ID: 22202444
* Section : 2
* Homework : 4
*/

#include "AdjacentList.h"
#include "Node.h"

AdjacentList::AdjacentList() {
    head = nullptr;
}

AdjacentList::~AdjacentList() {
    AdjacentNode* current = head;
    while (current != nullptr) {
        AdjacentNode* next = current->next;
        delete current;
        current = next;
    }
}

void AdjacentList::insert(Node* newAdj, double weight) {
    AdjacentNode* newNode = new AdjacentNode(newAdj, weight);
    
    if (head == nullptr) {
        head = newNode;
    }
    else {
        AdjacentNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void AdjacentList::remove(Node* nodeToRemove) {
    if (head == nullptr) {
        return;
    }
    if (head->nodePtr == nodeToRemove) {
        AdjacentNode* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    AdjacentNode* current = head;
    while (current->next != nullptr && current->next->nodePtr != nodeToRemove) {
        current = current->next;
    }
    if (current->next != nullptr) {
        AdjacentNode* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}
