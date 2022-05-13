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

struct edgeData{
    int id;
    string data;
    int weight;
};

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

struct EdgeNode {
    edgeData data;
    EdgeNode *next;
    EdgeNode *prev;
};

struct Node {
    Data data;
    Node *next;
    Node *prev;
};


#endif /* BINTREE_DATA_H */
