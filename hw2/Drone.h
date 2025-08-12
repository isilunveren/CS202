/**
Author : Isil Unveren
ID: 22202444
Section : 2
Homework : 2
Description : This class for the object of drone which contains id, battery life, position, and speed as instance variables. This class also contains default constructor, constructor, some getter and setter methods and operator overloadings.
*/
#ifndef Drone_h
#define Drone_h

class Drone {
private:
    int ID;
    double batteryLife; 
    double speed;
    double posX;
    double posY;
    
public:
    Drone() : ID(0), batteryLife(0), speed(0), posX(0), posY(0) {}
    
    Drone(double anID, double givenBatteryLife, double givenSpeed) {
        ID = anID;
        batteryLife = givenBatteryLife;
        speed = givenSpeed;
        posX = 0;
        posY = 0;
    }
    
    int getID() const {
        return ID;
    }
    
    double getBatteryLife() const {
        return batteryLife;
    }
    
    double getSpeed() {
        return speed;
    }
    
    double getPosX() {
        return posX;
    }
    
    double getPosY() {
        return posY;
    }
    
    void setPosition(double x, double y) {
        posX = x;
        posY = y;
    }
    
    void setSpeed(double updatedSpeed) {
        speed = updatedSpeed;
    }
    
    void setBattery(double updatedBattery) {
        batteryLife = updatedBattery;
    }
    
    bool operator==(const Drone& other) const {
        return (other.getBatteryLife() == batteryLife && other.getID() == ID);
    }
    
    bool operator>(const Drone& other) const {
        if (batteryLife > other.getBatteryLife()) return true;
        if (batteryLife == other.getBatteryLife()) return ID < other.getID();
        return false;
    }
    
    bool operator<(const Drone& other) const {
        if (batteryLife < other.getBatteryLife()) return true;
        if (batteryLife == other.getBatteryLife()) return ID > other.getID();
        return false;
    }
};

#endif

