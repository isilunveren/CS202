/**
* Title: Hash Table
* Author : Isil Unveren
* ID: 22202444
* Section : 2
* Homework : 3
* Description : In this class a hash table is implemented. This hash table inserts items into array indexes according to computed hash
* values and this class uses quadratic probing method to handle collisions.
*/
#include "HashTable.h"
#include <fstream>
#include <string>
using namespace std;

HashTable :: HashTable(){
    for (int i = 0; i < SIZE; i++){
        HashNode newNode;
        newNode.setCond("E");
        table[i] = newNode;
    }
}


int HashTable :: hashFunction(string anItem){
    int hashCode = 0;
    for (int i  = 0; i < anItem.length(); i++){
        hashCode += anItem[i];
    }
    hashCode = hashCode % SIZE;
    return hashCode;
}


void HashTable :: insert(string newItem){
    int hashCode = hashFunction(newItem);
    if(table[hashCode].getCond() == "E" || table[hashCode].getCond() == "D"){
        table[hashCode].setItem(newItem);
        table[hashCode].setCond("O");
        cout << newItem << " is registered as a weak spot." << endl;
    }
    else {
        bool isInserted = false;
        for (int i = 1; i < SIZE; i++){
            hashCode += i*i;
            hashCode = hashCode % SIZE;
            if(table[hashCode].getCond() == "E" || table[hashCode].getCond() == "D"){
                table[hashCode].setItem(newItem);
                table[hashCode].setCond("O");
                isInserted = true;
                break;
            }
        }
        if(isInserted){
            cout << newItem << " is registered as a weak spot." << endl;
        }
        else{
            cout << newItem << " could not be inserted." << endl;
        }
    }
}
void HashTable :: remove(string itemToRemove){
    int hashCode = hashFunction(itemToRemove);
    bool isFound = false;
    for (int i = 0; i < SIZE && table[hashCode].getCond() != "E"; i++){
        if(table[hashCode].getItem() == itemToRemove){
            table[hashCode].setCond("D");
            table[hashCode].setItem("");
            isFound = true;
            break;
        }
        else{
            hashCode += i*i;
            hashCode = hashCode % SIZE;
        }
    }
    
    if(isFound){
        cout << itemToRemove << " is deleted." << endl;
    }
    else{
        cout << itemToRemove << " is not present." << endl;
    }
    
}
bool HashTable :: search(string itemName){
    int hashCode = hashFunction(itemName);
    bool isFound = false;
    for (int i = 0; i < SIZE && table[hashCode].getCond() != "E"; i++){
        if(table[hashCode].getItem() == itemName){
            isFound = true;
            break;
        }
        else{
            hashCode += i*i;
            hashCode = hashCode % SIZE;
        }
    }
    
    if(isFound){
        cout << itemName << " is a weak spot." << endl;
    }
    else{
        cout << itemName << " is not a weak spot." << endl;
    }
    return  isFound;
}
