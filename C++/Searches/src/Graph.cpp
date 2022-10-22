/*
* File: Graph.h
* Author: David Neufeld
* Date: 2022/10/21
*/

#include <iostream>
#include "Graph.h"

void Graph::createEdge(Node* n, Node* m) {
    std::vector<Node*>::iterator i;
    std::vector<Node*> v;
    v = n->getConnectedNodes();
    for (i = v.begin(); i != v.end(); ++i) {
        if ((*i)->getID() == m->getID()) {
            // Break for loop and continue as this function will either
            // a) form an edge between both nodes
            // b) complete a connection on both sides of the nodes
            // or c) do nothing as an edge already exists
            break;
        }
    }
    if (i == v.end()) {
        n->connectNode(m);
    }
    v = m->getConnectedNodes();
    for (i = v.begin(); i != v.end(); ++i) {
        if ((*i)->getID() == n->getID()) {
            // Break for loop and continue as this function will either
            // a) form an edge between both nodes
            // b) complete a connection on both sides of the nodes
            // or c) do nothing as an edge already exists
            break;
        }
    }
    if (i == v.end()) {
        m->connectNode(n);
    }
    for (i = graphNodes.begin(); i != graphNodes.end(); ++i) {
        if ((*i)->getID() == n->getID()) {
            break;
        }
    }
    if (i == graphNodes.end()) {
        graphNodes.push_back(n);
    }
    for (i = graphNodes.begin(); i != graphNodes.end(); ++i) {
        if ((*i)->getID() == m->getID()) {
            break;
        }
    }
    if (i == graphNodes.end()) {
        graphNodes.push_back(m);
    }
}

void Graph::simpleDFS(Node* n) {
    markVisited(n->getID());
    printVisited(n->getID());
    for (Node* i : n->getConnectedNodes()) {
        if (isVisited[i->getID()] == false) {
            simpleDFS(i);
        }
    }
}

void Graph::DFS() {
    std::cout << "DFS" << std::endl;
    for (Node* i : graphNodes) {
        if (isVisited[i->getID()] == false) {
            simpleDFS(i);
        }
    }
    std::cout << std::endl;
    clearVisited();
}

void Graph::BFS() {
    std::cout << "BFS" << std::endl;
    std::queue<Node*> q;
    Node* currentNode;
    for (Node* i : graphNodes) {
        if (isVisited[i->getID()] == false) {
            markVisited(i->getID());
            q.push(i);
            while (!q.empty()) {
                currentNode = q.front();
                q.pop();
                printVisited(currentNode->getID());
                for (Node* j : currentNode->getConnectedNodes()) {
                    if (isVisited[j->getID()] == false) {
                        markVisited(j->getID());
                        q.push(j);
                    }
                }
            }
        }
    }
    std::cout << std::endl;
    clearVisited();
}

void Graph::printGraph(std::string name) {
    std::cout << "GRAPH " << name << std::endl;
    for (Node* i : graphNodes) {
        std::cout << i->getID() << ": ";
        for (Node* j : i->getConnectedNodes()) {
            std::cout << j->getID() << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Graph::markVisited(int i) {
    isVisited[i] = true;
}

void Graph::printVisited(int i) {
    std::cout << "Visited: " << i << std::endl;
}

void Graph::clearVisited() {
    isVisited.clear();
}