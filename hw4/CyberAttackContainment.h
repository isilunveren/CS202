/*
* Author : Isil Unveren
* ID: 22202444
* Section : 2
* Homework : 4
*/

#ifndef CYBER_ATTACK_CONTAINMENT_H
#define CYBER_ATTACK_CONTAINMENT_H
#include <string>
#include <fstream>
using namespace std;

class Node;
class Queue;

class CyberAttackContainment {
private:
    Node** nodes;
    int nodeCount;

    void simulateAttackAndDefense();
    void computeSecurityPatchTimes();
    void computeMalwarePropagationTimes();
    void determineNodeStatuses();
    void removeInfectedToSecuredEdges();

    Node* findNode(const string& name);

    void bfsMalwarePropagation(Node* startNode);

    void bfsSecurityPropagation(Node* startNode);

public:
    CyberAttackContainment(const string inputFile);
    ~CyberAttackContainment();

    void nodeStatuses();

    void computeConnectedZones();
};

#endif
