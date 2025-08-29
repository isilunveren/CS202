/*
* Author : Isil Unveren
* ID: 22202444
* Section : 2
* Homework : 4
*/

#include "CyberAttackContainment.h"
#include "Node.h"
#include "AdjacentList.h"
#include "Queue.h"
#include <iostream>
#include <fstream>
#include <string>

CyberAttackContainment::CyberAttackContainment(const string inputFile) {
    ifstream inFile(inputFile);
    if (!inFile) {
        exit(1);
    }

    inFile >> nodeCount;
    inFile.ignore();
    nodes = new Node*[nodeCount];

    for (int i = 0; i < nodeCount; i++) {
        string name, type;
        inFile >> name >> type;
        nodes[i] = new Node(name, type);
    }

    int connectionCount = 0;

    string firstNode, secondNode;
    double weight;
    
    //put each item into graph by looking at adjacent nodes and edge weights
    while (inFile >> firstNode >> secondNode >> weight) {
        Node* first = findNode(firstNode);
        Node* second = findNode(secondNode);
        if (first && second) {
            first->addAdjacent(second, weight);
            second->addAdjacent(first, weight);
            connectionCount++;
        }
    }
    inFile.close();
    cout << nodeCount << " nodes and " << connectionCount << " connections are loaded." << endl;
    simulateAttackAndDefense();
}

CyberAttackContainment::~CyberAttackContainment() {
    for (int i = 0; i < nodeCount; i++) {
        delete nodes[i];
    }
    delete[] nodes;
}

Node* CyberAttackContainment::findNode(const string& name) {
    for (int i = 0; i < nodeCount; i++) {
        if (nodes[i]->name == name) {
            return nodes[i];
        }
    }
    return nullptr;
}

void CyberAttackContainment::simulateAttackAndDefense() {
    for (int i = 0; i < nodeCount; i++) {
        nodes[i]->securityPatchTime = 0;
        nodes[i]->malwareTime = 0;
        nodes[i]->visited = false;
        nodes[i]->parent = nullptr;
    }
    computeSecurityPatchTimes();
    computeMalwarePropagationTimes();
    determineNodeStatuses();
    removeInfectedToSecuredEdges();
}

void CyberAttackContainment::computeSecurityPatchTimes() {
    for (int i = 0; i < nodeCount; i++) {
        if (nodes[i]->type == "dispatcher") {
            nodes[i]->securityPatchTime = 0;
            bfsSecurityPropagation(nodes[i]);
        }
    }
}

void CyberAttackContainment::bfsSecurityPropagation(Node* startNode) {
    //make all nodes unvisited
    for (int i = 0; i < nodeCount; i++) {
        nodes[i]->visited = false;
    }
    Queue queue;
    startNode->visited = true;
    queue.enqueue(startNode);
    while (!queue.isEmpty()) {
        Node* current = queue.dequeue();
        AdjacentNode* adj = current->adjacents->head;
        while (adj) {
            Node* adjNode = adj->nodePtr;
            double weight = adj->edgeWeight;

            double newTime = current->securityPatchTime + weight;

            //if it is not visited or there is a shorter route change it
            if (!adjNode->visited || newTime < adjNode->securityPatchTime) {
                adjNode->securityPatchTime = newTime;

                if (!adjNode->visited) {
                    adjNode->visited = true;
                    queue.enqueue(adjNode);
                }
            }
            adj = adj->next;
        }
    }
}

void CyberAttackContainment::computeMalwarePropagationTimes() {
        //make all nodes' malware time -1 in order to indicate that they are unvisited
        for (int i = 0; i < nodeCount; i++) {
            nodes[i]->malwareTime = -1;
        }

        Queue queue;
        for (int i = 0; i < nodeCount; i++) {
            if (nodes[i]->type == "malware") {
                nodes[i]->malwareTime = 0;
                queue.enqueue(nodes[i]);
            }
        }
    
    //BFS operation to compute malware times
        while (!queue.isEmpty()) {
            Node* current = queue.dequeue();
            AdjacentNode* adj = current->adjacents->head;
            while (adj) {
                Node* hold = adj->nodePtr;
                if (hold->malwareTime == -1) {
                    hold->malwareTime = current->malwareTime + 1;
                    queue.enqueue(hold);
                }
                adj = adj->next;
            }
        }
}
void CyberAttackContainment::bfsMalwarePropagation(Node* startNode) {
    //initially make all nodes unvisited
        for (int i = 0; i < nodeCount; i++) {
            nodes[i]->visited = false;
        }
        Queue queue;
        startNode->visited     = true;
        startNode->malwareTime = 0;
        queue.enqueue(startNode);
        while (!queue.isEmpty()) {
            Node* current = queue.dequeue();
            AdjacentNode* adj = current->adjacents->head;
            while (adj) {
                Node* adjNode = adj->nodePtr;
                if (!adjNode->visited) {
                    adjNode->malwareTime = current->malwareTime + 1;
                    adjNode->visited     = true;
                    queue.enqueue(adjNode);
                }
                adj = adj->next;
            }
        }
}

void CyberAttackContainment::determineNodeStatuses() {
    for (int i = 0; i < nodeCount; i++) {
        if (nodes[i]->type == "dispatcher") {
            nodes[i]->isInfected = false;
        }
        else if (nodes[i]->type == "malware") {
            nodes[i]->isInfected = true;
        }
        else {
            if (nodes[i]->malwareTime < nodes[i]->securityPatchTime) {
                nodes[i]->isInfected = true;
            } else {
                nodes[i]->isInfected = false;
            }
        }
    }
}

void CyberAttackContainment::removeInfectedToSecuredEdges() {
    for (int i = 0; i < nodeCount; i++) {
        Node* nodeI = nodes[i];
        
        //if one of the adjacent nodes are infected and other is not break connection
        if (nodeI->isInfected) {
            AdjacentNode* adj = nodeI->adjacents->head;
            while (adj) {
                Node* adjNode = adj->nodePtr;
                AdjacentNode* nextAdj = adj->next;
                if (!adjNode->isInfected) {
                    nodeI->removeAdjacent(adjNode);
                    adjNode->removeAdjacent(nodeI);
                }
                adj = nextAdj;
            }
        }
    }
}

void CyberAttackContainment::nodeStatuses() {
    cout << "Node states are:" << endl;

    Node** sortedNodes = new Node*[nodeCount];
    for (int i = 0; i < nodeCount; i++) {
        sortedNodes[i] = nodes[i];
    }

    for (int i = 0; i < nodeCount - 1; i++) {
        for (int j = i + 1; j < nodeCount; j++) {
            if (sortedNodes[i]->name > sortedNodes[j]->name) {
                Node* temp = sortedNodes[i];
                sortedNodes[i] = sortedNodes[j];
                sortedNodes[j] = temp;
            }
        }
    }
    for (int i = 0; i < nodeCount; i++) {
        cout << sortedNodes[i]->name << " ";
        if (sortedNodes[i]->isInfected) {
            cout << "infected" << endl;
        } else {
            cout << "secured" << endl;
        }
    }
    delete[] sortedNodes;
}

void CyberAttackContainment::computeConnectedZones() {
    for (int i = 0; i < nodeCount; i++) {
        nodes[i]->nodeID = -1;
        nodes[i]->visited = false;
    }
    int numberOfZones = 0;
    
    for (int i = 0; i < nodeCount; i++) {
        if (!nodes[i]->visited) {
            Queue queue;
            nodes[i]->visited = true;
            nodes[i]->nodeID = numberOfZones;
            queue.enqueue(nodes[i]);
            while (!queue.isEmpty()) {
                Node* current = queue.dequeue();
                AdjacentNode* adj = current->adjacents->head;
                while (adj) {
                    Node* adjNode = adj->nodePtr;
                    if (!adjNode->visited) {
                        adjNode->visited = true;
                        adjNode->nodeID = numberOfZones;
                        queue.enqueue(adjNode);
                    }
                    adj = adj->next;
                }
            }
            numberOfZones++;
        }
    }
    
    //allocating space for each zone and its adjacents
    Node*** zones = new Node**[numberOfZones];
    int* sizeOfZones = new int[numberOfZones];
    bool* isInfectedZone = new bool[numberOfZones];
    
    
    for (int i = 0; i < numberOfZones; i++) {
        zones[i] = new Node*[nodeCount];
        sizeOfZones[i] = 0;
        isInfectedZone[i] = false;
    }

    //looking at whether any of the adjacents is infected
    for (int i = 0; i < nodeCount; i++) {
        int compID = nodes[i]->nodeID;
        zones[compID][sizeOfZones[compID]++] = nodes[i];
        if (nodes[i]->isInfected) {
            isInfectedZone[compID] = true;
        }
    }
    
    //sorting alphabetically
    for (int i = 0; i < numberOfZones; i++) {
        for (int j = 0; j < sizeOfZones[i] - 1; j++) {
            for (int k = j + 1; k < sizeOfZones[i]; k++) {
                if (zones[i][j]->name > zones[i][k]->name) {
                    Node* temp = zones[i][j];
                    zones[i][j] = zones[i][k];
                    zones[i][k] = temp;
                }
            }
        }
    }

    //to sort connected ones alphabetically
    Node** roots = new Node*[numberOfZones];
    for (int i = 0; i < numberOfZones; i++) {
        roots[i] = zones[i][0];
    }

    //sort each connected zone according to their root's name
    for (int i = 0; i < numberOfZones - 1; i++) {
        for (int j = i + 1; j < numberOfZones; j++) {
            if (roots[i]->name > roots[j]->name) {
                Node* rootTemp = roots[i];
                roots[i] = roots[j];
                roots[j] = rootTemp;

                Node** tempZone = zones[i];
                zones[i] = zones[j];
                zones[j] = tempZone;

                int tempSize = sizeOfZones[i];
                sizeOfZones[i] = sizeOfZones[j];
                sizeOfZones[j] = tempSize;

                bool tempInfected = isInfectedZone[i];
                isInfectedZone[i] = isInfectedZone[j];
                isInfectedZone[j] = tempInfected;
            }
        }
    }

    cout << "Connected zones are:" << endl;
    
    for (int i = 0; i < numberOfZones; i++) {
        for (int j = 0; j < sizeOfZones[i]; j++) {
            cout << zones[i][j]->name;

            if (j < sizeOfZones[i] - 1) {
                cout << " ";
            }
        }
        if (isInfectedZone[i]) {
            cout << " infected" << endl;
        } else {
            cout << " secured" << endl;
        }
    }
    
    //clean up
    for (int i = 0; i < numberOfZones; i++) {
        delete[] zones[i];
    }
    delete[] zones;
    delete[] sizeOfZones;
    delete[] isInfectedZone;
    delete[] roots;
}
