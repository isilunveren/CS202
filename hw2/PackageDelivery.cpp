/**
Author : Isil Unveren
ID: 22202444
Section : 2
Homework : 2
Description : This file is implementation file of package delivery system. It initially reads the txt files to get information of packages and drones and put them into heap in its constructor. Then by using task class in the simulation method and it manages tasks.
*/
#include "PackageDelivery.h"
#include "Task.h"
#include <iostream>
#include <fstream>
#include <sstream>


PackageDelivery::PackageDelivery(const string droneFile, const string packageFile){
    dronesHeap = new Heap<Drone>();
    packagesHeap = new Heap<Package>();
    
    ifstream drones(droneFile);
    ifstream packages(packageFile);
    
    drones >> droneCount;
    
    for (int i = 0; i < droneCount && i < 50; i++){
        double id;
        double battery;
        double speed;
        drones >> id >> battery >> speed;
        Drone newDrone(id, battery, speed);
        dronesHeap->insertItem(newDrone);
        
    }
    
    packages >> packageCount;
    
    for(int i = 0; i < packageCount && i < 50; i++){
        double id;
        double posX;
        double posY;
        double weight;
        double priority;
        packages >> id >> posX >> posY >> weight >> priority;
        Package newPackage(id, posX, posY, weight, priority);
        packagesHeap->insertItem(newPackage);
    }
    
    drones.close();
    packages.close();
}
PackageDelivery::~PackageDelivery() {
    delete dronesHeap;
    delete packagesHeap;
}

void PackageDelivery::simulation(){
    Task newTask;
    newTask.doTask(this);
}
