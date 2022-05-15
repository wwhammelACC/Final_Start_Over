/*********************
Name: William Hammel
Final Project
Purpose: Description: Create a working bi-directional
weighted graph class with all the standard methods
for a data structure of that type.
**********************/

#include "graph.h"

/*
 * ****************************************
 * Constructors / Destructors
 * ****************************************
 */


//constructor
Graph::Graph() {
    countVertex = 0;
    countEdge = 0;
    
}

//destructor
Graph::~Graph() {
    for (int i = 0; i < graphList.size(); i++) {
        if (graphList[i]) {
            delete graphList[i];
        }
    }
}

/*
 * ****************************************
 * Public
 * ****************************************
 */


bool Graph::addVertex(int id, string *info){
    bool flag = false;
    if (id >= 0 && *info != "/0") {
        LinkedList *newLinkedList = new LinkedList;
        newLinkedList->addNode(id, info, -1);
        graphList.push_back(newLinkedList);
        countVertex++;
        flag = true;
    }
    return flag;
}

bool Graph::addEdge(int id1, string *info1, int id2, string *info2, int weight) {
    bool flag = false;
    if (id1 != id2 && weight >= 0) {
        for (int i = 0; i < graphList.size(); i++) {
            if (graphList[i]->getHeadId() == id1) {
                graphList[i]->addNode(id2, info2, weight);
                flag = true;
                countEdge++;
            } else if (graphList[i]->getHeadId() == id2) {
                graphList[i]->addNode(id1, info1, weight);
                flag = true;
                countEdge++;
            }
        }
    }
    return flag;
}

bool Graph::removeEdge(int id1, int id2){
    bool flag = false;
    if (id1 >=0 && id2 >= 0) {
        for (int i = 0; i < graphList.size(); i++) {
            if ((graphList[i]->exists(id1)) && graphList[i]->exists(id2)) {
                if (id1 == graphList[i]->getHeadId()) {
                    graphList[i]->deleteNode(id2);
                    flag = true;
                    countEdge -= 1;
                }
            }
        }
    }
        return flag;
}

bool Graph::removeVertex(int indexID){
    bool flag = false;
    if (indexID >=0) {
        for (int i = 0; i < graphList.size(); i++) {
            if ((graphList[i]->exists(indexID))) {
                if (indexID == graphList[i]->getHeadId()) {
                    graphList[i]->clearList();
                    graphList.erase(graphList.begin() + i);
                    countVertex -= 1;
                    flag = true;
                }
            }
        }
    }
    return flag;
}

void Graph::printGraph(int listIndex){
    if(graphList.size() > listIndex){
        graphList[listIndex]->printList();
    }else{
        cout << "No entry found " << endl;
    }
}

int Graph::getVertexCount(){
// count is internal and updated within insertEntry
    return countVertex;
}

int Graph::getEdgeCount(){
// count is internal and updated within insertEntry
    return countEdge;
}

string Graph::getVertex(int indexID){
    //making temporary data holder for testing
    Data tmpData;
    string found = "";
    if (indexID >=0) {
        for (int i = 0; i < graphList.size(); i++) {
            if ((graphList[i]->exists(indexID))) {
                if (graphList[i]->getNode(indexID, &tmpData)) {
                    found = tmpData.data;
                }
            }
        }
    }
    return found;
}

void Graph::clearGraph(){
    for(int i = 0; i < graphList.size(); i++){
        if(graphList[i] != NULL){
            graphList[i]->clearList();
            countVertex = 0;
            countEdge = 0;
        }
    }
    graphList.clear();
}
