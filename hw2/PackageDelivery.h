/**
Author : Isil Unveren
ID: 22202444
Section : 2
Homework : 2
Description : This file is header file of package delivery system. It uses task class in order to manage that system and also it has heap of drones and packages
*/
#ifndef PackageDelivery_h
#define PackageDelivery_h
#include "Drone.h"
#include "Package.h"
#include "Heap.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class PackageDelivery {
public:
    
    PackageDelivery(const string droneFile, const string packageFile);
    ~PackageDelivery();
    void simulation();
    
    int droneCount;
    int packageCount;
    Heap<Drone> *dronesHeap;
    Heap<Package> *packagesHeap;

};
#endif
