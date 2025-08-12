/**
Author : Isil Unveren
ID: 22202444
Section : 2
Homework : 2
Description : This file is header file of heap class, this heap class works as max heap and it is used in order to hold packages and drones in delivery system
*/
#ifndef Heap_h
#define Heap_h
#include <iostream>
using namespace std;

template <typename ItemType>
class Heap {
public:
    Heap(){
        size = 0;
        items = new ItemType[50];
    }
    ~Heap(){
        delete[] items;
    }
    
    bool isEmpty(){
        if(size == 0) return true;
        return false;
    }
    void insertItem( ItemType& newItem){
        items[size++] = newItem;
        int curIndex = size - 1;
        int parentIndex = (curIndex - 1)/2;
        while (curIndex > 0 && items[curIndex] > items[parentIndex]){
            swap(curIndex, parentIndex);
            curIndex = parentIndex;
            parentIndex = (curIndex - 1)/2;
        }
    }
    void removeTop(){
        if(!isEmpty()){
            items[0] = items [size - 1];
            size --;
            heapify(0);
        }
    }
    void removeItem(int position){
        if(!isEmpty()){
            items[position] = items [size - 1];
            size --;
            heapify(position);
        }
    }
    void swap(int a, int b){
        ItemType temp = items[a];
        items[a] = items[b];
        items[b] = temp;
    }
    void heapify(int curIndex){
        int leftChild = 2 * curIndex + 1;
        int rightChild = 2 * curIndex + 2;
        int largest = curIndex;

        if (leftChild < size && items[leftChild] > items[largest]) {
            largest = leftChild;
        }
        if (rightChild < size && items[rightChild] > items[largest]) {
            largest = rightChild;
        }

        if (largest != curIndex) {
            swap(largest, curIndex);
            heapify(largest);
        }
        
    }
    ItemType peekRoot(){
        return items[0];
    }
    
    ItemType* items;
    int size;
};
#endif
