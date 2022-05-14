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
//    clearGraph();
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

bool Graph::removeEdge(int listID, int indexID){
    bool flag = false;
    cout << "Test line removeEdge " << endl;
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
    //cout << "initial print graph test line " << endl;
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

int Graph::getEdgeWeight(int weightVal){
    cout << "testing get weight " << endl;
    return weightVal;
}

//bool Graph::clearGraph(){
//    bool success = false;
//    for(int i = 0; i < graphList.size(); i++){
//        if(graphList[i] != NULL){
//            Node *current = graphList[i];
//            while(current != NULL){
//                graphList[i] = current->next;
//                delete current;
//                current = graphList[i];
//                count--;
//            }
//            graphList[i] = NULL;
//            tails = NULL;
//            success = true;
//        }
//    }
//    return success;
//}





// missing mystack, storage, store, getCount, getnodeweight, getpos
//void Graph::DFS(int id) {
//    bool found = false;
//    int total = 0;
//    bool visited[graphList.size()];
//    Data storage;
//    int store = id;
//    stack<int> myStack;
//    for (int i = 0; i < graphList.size(); i++) {
//        visited[i] = false;
//        if (graphList[i]->getHeadId() == store) {
//            graphList[i]->getNode(store, &storage);
//            found = true;
//        }
//    }
//    if (found == true) {
//        total = storage.weight;
//        graphList.push(storage.id); //adding the first data
//        while (!graphList.empty()) {
//            store = myStack.top();
//            graphList.pop();
//            if (visited[getPos(store)] == false) {
//                cout << store << " ";
//                visited[getPos(store)] = true;
//            }
//            for (int i = 0; i <= (graphList[getPos(store)]->getCount()) - 1; i++) {
//                id = graphList[getPos(store)]->getNodeId(i);//stores the id of the index given (i)
//                if (visited[getPos(id)] == false) {
//                    total = total + graphList[getPos(store)]->getNodeWeight(i);
//                    graphList.push(id);
//                }
//            }
//        }
//    }
//    cout << "the total weight of the traversal is " << total << endl;
//}


/*
* ****************************************
* Private
* ****************************************
*/

