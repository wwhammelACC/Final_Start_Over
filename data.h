/*
 * Do not modify this file
 */

#ifndef BINTREE_DATA_H
#define BINTREE_DATA_H

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
    int startVert, endVert;
};

struct VertexNode {
    Data data;
    vector<pair<int,int>> newEdges;
    VertexNode *next;
    VertexNode *prev;
};

struct EdgeNode {
    int id;
};

struct Node {
    Data data;
    Node *next;
    Node *prev;
};


#endif /* BINTREE_DATA_H */
