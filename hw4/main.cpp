//
//  main.cpp
//  hw4
//
//  Created by IŞIL ÜNVEREN on 15.05.2025.
//

#include <iostream>
#include "CyberAttackContainment.h"
int main() {
    CyberAttackContainment cac("network.txt");
    cout<<endl;
    cac.nodeStatuses();
    cout<<endl;
    cac.computeConnectedZones();
    return 0;
}
