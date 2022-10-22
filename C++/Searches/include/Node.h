/*
* File: Node.h
* Author: David Neufeld
* Date: 2022/10/21
*/

#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

// A node that can be used in the formation of a graph or tree
class Node {
public:
    // Constructor. Takes in an ID to identify the node
    Node(int ID);
    ~Node() {}
    int getID();
    std::vector<Node*> getConnectedNodes();
    // Adds to list of connected nodes. This operation is permanent
    // If n has the same ID as the node, nothing happens
    void connectNode(Node* n);

private:
    int nodeID;
    // Connections between nodes are essentially edges in a graph
    std::vector<Node*> connectedNodes;
};

#endif // NODE_H