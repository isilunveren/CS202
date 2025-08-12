//
//  CyberAttackContainment.h
//  202hw4
//
//  Created by IŞIL ÜNVEREN on 14.05.2025.
//
#ifndef CYBERATTACKCONTAINMENT_H
#define CYBERATTACKCONTAINMENT_H
#include <string>
using namespace std;
class CyberAttackContainment {
public:
    CyberAttackContainment(const string& inputFile);
    ~CyberAttackContainment();
    void nodeStatuses();
    void computeConnectedZones();
};

#endif
