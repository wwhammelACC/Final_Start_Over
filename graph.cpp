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
            if((graphList[i]->exists(id1)) && graphList[i]->exists(id2)){
                if (graphList[i]->getHeadId() == id1) {
                    graphList[i]->deleteNode(id2);
                    flag = true;
                    countEdge -=1;
                } else if (graphList[i]->getHeadId() == id2) {
                    graphList[i]->deleteNode(id1);
                    flag = true;
                    countEdge -=1;
                }
            }
            else{
                flag = false;
            }
        }
    }
    return flag;
}

bool Graph::removeVertex(int listID, int indexID){
    bool flag = false;
    if (indexID >= 0 && listID >= 0){
        if (graphList[listID]->deleteNode(indexID))
            flag = true;
        countVertex -=1;
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

string Graph::getVertex(int listID, int indexID){
    //making temporary data holder for testing
    Data tmpData;
    string found = "";
    if(indexID >= 0){
        if (graphList[listID]->getNode(indexID, &tmpData)) {
            found = tmpData.data;
        }
    }
    return found;
}

string Graph::getEdge(int listID, int indexID){
    //making temporary data holder for testing
    Data tmpData;
    string found = "";
    if(indexID >= 0){
        if (graphList[listID]->getNode(indexID, &tmpData)) {
            found = tmpData.data;
        }
    }
    return found;
}

