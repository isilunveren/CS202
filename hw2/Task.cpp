/**
Author : Isil Unveren
ID: 22202444
Section : 2
Homework : 2
Description :This file is implementation file of Task class which manages actual delivering system with its various methods namely with doTask method and othrs that make calculations of distance, effective speed, time and roundings and also it holds tick as instance variable.
*/
#include "Task.h"
#include <cmath> 
#include <iostream>

int MAX_PACKAGE_WEIGHT = 10;
double WEIGHT_FACTOR = 0.2;
double BATTERY_FACTOR = 0.3;
int COOLDOWN_PERIOD = 5;
double MAX_BATTERY = 300.0;

Task::Task(){
    tick = 0;
}

void Task::doTask(PackageDelivery* newDelivery){
    
    Queue coolingQueue;

    while (!newDelivery->packagesHeap->isEmpty() || !coolingQueue.isEmpty()) {

        while (!coolingQueue.isEmpty() && coolingQueue.peekCooldownTick() <= tick) {
            
            Package delayedPackage = coolingQueue.peekTopPackage();
            Drone cooledDrone = coolingQueue.dequeueDrone();

            newDelivery->dronesHeap->insertItem(cooledDrone);
            newDelivery->packagesHeap->insertItem(delayedPackage);

        }

        if (newDelivery->dronesHeap->isEmpty() && !coolingQueue.isEmpty()) {
            tick = coolingQueue.peekCooldownTick();
            continue;
        }

        if (newDelivery->packagesHeap->isEmpty() && coolingQueue.isEmpty()) {
            break;
        }

        if (newDelivery->dronesHeap->isEmpty()) {
            tick++;
            continue;
        }

        Drone curDrone = newDelivery->dronesHeap->peekRoot();
        newDelivery->dronesHeap->removeTop();

        if (newDelivery->packagesHeap->isEmpty()) {
            tick++;
            continue;
        }

        Package curPackage = newDelivery->packagesHeap->peekRoot();
        newDelivery->packagesHeap->removeTop();
        
        double time = timeRequired(curDrone, curPackage);

        if(time <= curDrone.getBatteryLife()) {
            curDrone.setPosition(curPackage.getPosX(), curPackage.getPosY());
            int tenTimesBattery = (curDrone.getBatteryLife())*10;
            int tenTimesTime = time*10;
            int newBatteryTimesTen = tenTimesBattery - tenTimesTime;
            curDrone.setBattery(newBatteryTimesTen/10.0);
            
            newDelivery->dronesHeap->insertItem(curDrone);
            std::cout << "Drone " << curDrone.getID() << " Package " << curPackage.getID()
                      << " at tick " << tick << " (delivery time: " << time
                      << ", battery life: " << curDrone.getBatteryLife() << ")" << std::endl;
            tick++;

        }
        else {
            curDrone.setBattery(MAX_BATTERY);
            curDrone.setPosition(0, 0);
            coolingQueue.enqueue(curDrone, curPackage, tick + COOLDOWN_PERIOD);

            std::cout << "Drone " << curDrone.getID() << " Package " << curPackage.getID()
                      << " at tick " << tick << " cool down" << std::endl;
            tick++;
        }
    }
}

double Task::findDistance(Drone drone, Package package) {
    double dx = drone.getPosX() - package.getPosX();
    double dy = drone.getPosY() - package.getPosY();
    double distance = sqrt((dx * dx) + (dy * dy));
    
    return truncate(distance);
}

double Task::findEffectiveSpeed(Drone drone, Package package) {

    double effectiveSpeed = (drone.getSpeed() * (1.0 - WEIGHT_FACTOR * (package.getWeight() / MAX_PACKAGE_WEIGHT)))* (1.0 - BATTERY_FACTOR * (1.0 - (drone.getBatteryLife() / MAX_BATTERY)));

    return truncate(effectiveSpeed);
}

double Task::timeRequired(Drone drone, Package package) {
    double distance = findDistance(drone, package);
    double effectiveSpeed = findEffectiveSpeed(drone, package);
    truncate(distance);
    truncate(effectiveSpeed);
    double time = distance / effectiveSpeed;

    return truncate(time);
}

void Task::findHighestPriorityPackage(Drone& drone, int packageIndex, PackageDelivery* packageDelivery){
    int highestPriorityIndex = packageIndex;
    int leftChild = 2 * highestPriorityIndex + 1;
    int rightChild = 2 * highestPriorityIndex + 2;
    
    if(packageDelivery->packagesHeap->items[highestPriorityIndex] == packageDelivery->packagesHeap->items[leftChild]){
        if(timeRequired(drone, packageDelivery->packagesHeap->items[highestPriorityIndex]) >
           timeRequired(drone, packageDelivery->packagesHeap->items[leftChild])){
            highestPriorityIndex = leftChild;
        }
    }
    if(packageDelivery->packagesHeap->items[highestPriorityIndex] == packageDelivery->packagesHeap->items[rightChild]){
        if(timeRequired(drone, packageDelivery->packagesHeap->items[highestPriorityIndex]) >
           timeRequired(drone, packageDelivery->packagesHeap->items[rightChild])){
            highestPriorityIndex = rightChild;
        }
    }
    if(highestPriorityIndex == packageIndex){
        return;
    }
    else {
        return findHighestPriorityPackage(drone, highestPriorityIndex, packageDelivery);
    }
}

double Task::truncate(double num){
    return ((int)(num * 10)) / 10.0;
}
