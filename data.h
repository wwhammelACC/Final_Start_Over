/*
 * Do not modify this file
 */


#ifndef GRAPH_DATA_H
#define GRAPH_DATA_H

#include <string>
#include <vector>
#include <utility>
//#include <bits/stdc++.h>
using std::string;
using std::pair;
using std::vector;

struct Data {
    int id;
    string data;
    int weight;
};

struct VertexNode {
    Data data;
    VertexNode *next;
    VertexNode *prev;
};

struct Node {
    Data data;
    Node *next;
    Node *prev;
};


#endif /* GRAPH_DATA_H */
