/**
* Title: Hash Table Improved
* Author : Isil Unveren
* ID: 22202444
* Section : 2
* Homework : 3
* Description : In this class a type of hash table is implemented. This hash table inserts items into array of linked lists according to computed hash
* values and this class uses separate chaining method to handle collisions.
*/
#include <string>
#include <iostream>
#include "HashTableImproved.h"
using namespace std;

HashTableImproved :: HashTableImproved(){}

HashTableImproved :: HashTableImproved (string fileName){
    ifstream file(fileName);
    string item;

    while (getline(file, item)){
        if (item.empty())
            continue;        
        insert(item);
    }
    
    file.close();
}

HashTableImproved :: ~HashTableImproved() {
  delete[] table;
}

int HashTableImproved :: hashFunction(string anItem){
    int hashCode = 0;
    for (int i  = 0; i < anItem.length(); i++){
        hashCode += anItem[i];
    }
    hashCode = hashCode % SIZE;
    return hashCode;
}
void HashTableImproved :: insert(string newItem){
    if(table[hashFunction(newItem)].doesExist(newItem)){
        cout << newItem << " could not be inserted." << endl;
        return;
    }
    table[hashFunction(newItem)].insertItem(newItem);
    cout << newItem << " is registered as a weak spot." << endl;
}
void HashTableImproved :: remove(string itemToRemove){
    if(!(table[hashFunction(itemToRemove)].doesExist(itemToRemove))) {
        cout << itemToRemove << " is not present." << endl;
        return;
    }
    table[hashFunction(itemToRemove)].removeItem(itemToRemove);
    cout << itemToRemove << " is deleted." << endl;
    
}
bool HashTableImproved :: search(string itemName){
    if (table[hashFunction(itemName)].doesExist(itemName)){
        cout << itemName << " is a weak spot." << endl;
        return true;
    }
    else {
        cout << itemName << " is not a weak spot." << endl;
        return false;
    }
}

int HashTableImproved :: numberOfCollisions(int hashCode){
    int collisions = 0;
    collisions = table[hashCode].getItemCount();
    return collisions;
}

int HashTableImproved :: getSize(){
    return SIZE;
}

void HashTableImproved :: getCollisions(int size){
    SIZE = size;
    ifstream in("ListofParts.txt");
    string part;
    
    while (getline(in, part)) {
        if (part.empty())
            continue;
        insert(part);
    }
    for(int i = 0; i < SIZE; i++){
        cout << numberOfCollisions(i) << endl;
    }
}
