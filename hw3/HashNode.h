/**
* Title: Hash Node
* Author : Isil Unveren
* ID: 22202444
* Section : 2
* Homework : 3
* Description : In this class a type of node is implemented. This node holds an item with its name and its condition.
*/
#ifndef HashNode_h
#define HashNode_h
#include <iostream>
using namespace std;

class HashNode {
public:
    HashNode(){
        item = "";
        cond = "E";
    }
    void setCond(string newCond){
        if(newCond == "E" || newCond == "O" || newCond == "D"){
            cond = newCond;
        }
    }
    void setItem(string newItem){
        item = newItem;
    }
    string getCond(){
        return cond;
    }
    
    string getItem(){
        return item;
    }
    
private:
    string item;
    string cond;
    
};
#endif
