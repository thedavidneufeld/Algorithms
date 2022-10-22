/*
* File: Graph.h
* Author: David Neufeld
* Date: 2022/10/21
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <map>
#include <vector>
#include <queue> // for BFS
#include "Node.h"

// A class that aids in the formations of graphs and performs graph searches
class Graph {
public:  
    Graph() {}
    ~Graph() {}
    // Forms an edge between two nodes in the graph
    void createEdge(Node* n, Node* m);
    // Algorithm for performing a DFS on connected or disconnected graph
    void DFS();
    // Algorithm for performing a BFS
    void BFS();
    // Prints out the nodes and the nodes they are connected to
    // Takes in an optional graph name
    void printGraph(std::string name = "");

private:
    // Algorithm for performing a DFS on a conncted graph
    void simpleDFS(Node* n);
    // Marks a node as visited
    void markVisited(int i);
    // Clears isVisited so that it can be used for future searches
    void clearVisited();
    // Prints that a node has been visited
    void printVisited(int i);
    // The nodes added to the graph when a new edge is formed
    std::vector<Node*> graphNodes;
    // Indicates whether or not a node has been previosly visited in a current search
    std::map<int, bool> isVisited;
    
};

#endif // GRAPH_H