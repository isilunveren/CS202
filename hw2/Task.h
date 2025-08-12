/**
Author : Isil Unveren
ID: 22202444
Section : 2
Homework : 2
Description : This file is header file of Task class which manages actual delivering system with its various methods making calculations of distance, effective speed, time and roundings and also it holds tick as instance variable.
*/
#ifndef Task_h
#define Task_h
#include "Drone.h"
#include "Package.h"
#include "Heap.h"
#include "PackageDelivery.h"
#include "Queue.h"


class Task {
  
public:
    Task();
    void doTask(PackageDelivery* newDelivery);
    void findHighestPriorityPackage(Drone& drone, int packageIndex, PackageDelivery* packageDelivery);
    double findDistance(Drone drone, Package package);
    double findEffectiveSpeed (Drone drone, Package package);
    double timeRequired (Drone drone, Package package);
    double truncate(double num);
    int tick;
    
};

#endif
