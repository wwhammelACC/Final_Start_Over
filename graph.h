/*********************
Name: William Hammel
Final Project
Purpose: Description: Create a working bi-directional
weighted graph class with all the standard methods
for a data structure of that type.
**********************/

#ifndef GRAPH_H
#define GRAPH_H

#include "data.h"
#include "linkedlist.h"

#include <iostream>
#include <string>       /* string */
#include <vector>

#define GRAPHSIZE 11

using std::vector;
using std::cout;
using std::endl;

class Graph {

// public methods
public:

    Graph(); // constructor
    ~Graph(); // destructor

    int getVertexCount();
    int getEdgeCount();
    string getVertex(int, int);
    string getEdge(int, int);
    bool getHeadID(int, Data*);

    bool addEdge(int, string*, int, string*, int);
    bool addVertex(int, string*);
    bool removeEdge(int, int);
    bool removeVertex(int, int);

    void printGraph(int);

//    void DFS(int);
//    void breadthFirstTraversal(int);

//    bool clearGraph();

// private methods
private:
    Node *head;
    int countEdge;
    int countVertex;
    vector<LinkedList*> graphList;
};

#endif //GRAPH_H
