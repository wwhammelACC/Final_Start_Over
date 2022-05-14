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
#include <utility>
//#include <bits/stdc++.h>

#include <iostream>
#include <string>       /* string */
#include <vector>

#define GRAPHSIZE 8

using std::vector;
using std::cout;
using std::endl;
using std::pair;
using std::make_pair;

class Graph {

// public methods
public:

    Graph(); // constructor
    ~Graph(); // destructor

    bool isEmpty();

    int getVertexCount();
    int getEdgeCount();
    int getEdgeWeight(int);
    string getVertex(int, int);
    string getEdge(int, int);
    bool getHeadID(int, Data*);

    bool addVertex(int, string*);
    bool addEdge(int, string*, int, string*, int);
//    bool removeEdge(int, int);
    bool removeEdge(int, int);
    bool removeVertex(int, int);

    void printGraph(int);

    void DFS(int);
    void breadthFirstTraversal(int);

    bool edgeExists();

//    vector<LinkedList*> graphList; // just this

// private methods
private:
    VertexNode *head;
    //vector<VertexNode*> vertexList;
    //vector<VertexNode*> edgeList;
    int countEdge;
    int countVertex;

    vector<LinkedList*> graphList; // just this

//    LinkedList *newLinkedList[GRAPHSIZE];
//    vector<VertexNode*> vertexList;

    //Save for later
//    vector<int> adj[];
//    vector<LinkedList*> graphList;
//    LinkedList *newLinkedList[GRAPHSIZE];
};

#endif //GRAPH_H
