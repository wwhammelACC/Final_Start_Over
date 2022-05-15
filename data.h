/*
 * Do not modify this file
 */

#ifndef GRAPH_DATA_H
#define GRAPH_DATA_H

#include <string>
using std::string;

struct Data {
    int id;
    string data;
    int weight;
};

struct Node {
    Data data;
    Node *next;
    Node *prev;
};


#endif /* GRAPH_DATA_H */
