/**
* Title: Hash Table Improved
* Author : Isil Unveren
* ID: 22202444
* Section : 2
* Homework : 3
* Description : In this class a type of hash table is implemented. This hash table inserts items into array of linked lists according to computed hash
* values and this class uses separate chaining method to handle collisions.
*/
#ifndef HashTableImproved_h
#define HashTableImproved_h
#include "HashLinkedList.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class HashTableImproved {
public:
    HashTableImproved();
    ~HashTableImproved();
    HashTableImproved(string fileName);
    int hashFunction(string anItem);
    void insert(string newItem);
    void remove(string itemToRemove);
    bool search(string itemName);
    int numberOfCollisions(int hashCode);
    int getSize();
    void getCollisions(int size);
private:
    int SIZE = 100;
    HashLinkedList* table = new HashLinkedList[SIZE];
    
};
#endif
