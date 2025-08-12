/**
* Title: Hash Table
* Author : Isil Unveren
* ID: 22202444
* Section : 2
* Homework : 3
* Description : In this class a hash table is implemented. This hash table inserts items into array indexes according to computed hash
* values and this class uses quadratic probing method to handle collisions.
*/
#ifndef HashTable_h
#define HashTable_h
#include "HashNode.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class HashTable {
public:
    HashTable();
    HashTable(string fileName);
    int hashFunction(string anItem);
    void insert(string newItem);
    void remove(string itemToRemove);
    bool search(string itemName);
    
private:
    static const int SIZE = 201;
    HashNode table[SIZE];
    
};
#endif

