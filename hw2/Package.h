/**
Author : Isil Unveren
ID: 22202444
Section : 2
Homework : 2
Description : This class for the object of package which contains id,  position, weight, and priority value as instance variables. This class also contains default constructor, copy constructor, constructor, some getter and setter methods and operator overloadings.
*/
#ifndef Package_h
#define Package_h
class Package {
private:
    int ID;
    int desX;
    int desY;
    int priority;
    int weight;
    
public:
    Package() : ID(0), desX(0), desY(0), priority(0), weight(0) {}
    
    Package(double anID, double posX, double posY, double givenWeight, double givenPriority){
        ID = anID;
        desX = posX;
        desY = posY;
        weight = givenWeight;
        priority = givenPriority;
        
    }
    Package(const Package& other) {
        ID = other.ID;
        desX = other.desX;
        desY = other.desY;
        weight = other.weight;
        priority = other.priority;
    }
    
    double getID(){
        return ID;
    }
    double getPosX(){
        return desX;
    }
    double getPosY(){
        return desY;
    }
    double getPriority(){
        return priority;
    }
    double getWeight(){
       return weight;
    }
    bool operator==(Package& other){
        if (other.getPriority() == priority) return true;
        return false;
    }
    bool operator>(Package& other){
        if (priority > other.getPriority()) return true;
        return false;
    }
    bool operator<(Package& other){
        if (priority < other.getPriority()) return true;
        return false;
    }
    bool operator>=(Package& other){
        if (priority >= other.getPriority()) return true;
        return false;
    }
    bool operator<=(Package& other){
        if (priority <= other.getPriority()) return true;
        return false;
    }

};
#endif
