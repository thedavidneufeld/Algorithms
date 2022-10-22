/*
* File: testSearches.cpp
* Author: David Neufeld
* Date: 2022/10/21
*/

#include <iostream>
#include <string>
#include "Node.h"
#include "Graph.h"

int main() {
    std::vector<Node*> nodes;
    for (int i = 0; i < 8; i++) {
        nodes.push_back(new Node(i));
    }
    Graph g;
    g.createEdge(nodes[0], nodes[3]);
    g.createEdge(nodes[0], nodes[2]);
    g.createEdge(nodes[1], nodes[2]);
    g.createEdge(nodes[2], nodes[4]);
    g.createEdge(nodes[3], nodes[4]);
    Graph h;
    h.createEdge(nodes[5], nodes[7]);
    h.createEdge(nodes[6], nodes[5]);
    h.createEdge(nodes[6], nodes[1]);
    g.printGraph("G");
    h.printGraph("H");
    g.DFS();
    g.BFS();
    return 0;
}