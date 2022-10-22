/*
* File: Node.cpp
* Author: David Neufeld
* Date: 2022/10/21
*/

#include "Node.h"

Node::Node(int ID) {
    nodeID = ID;
}

int Node::getID() {
    return nodeID;
}

std::vector<Node*> Node::getConnectedNodes() {
    return connectedNodes;
}

void Node::connectNode(Node* n) {
    if (nodeID != n->getID()) {
        connectedNodes.push_back(n);
    }
}