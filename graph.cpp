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
//    clearList();
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

//Maybe use later save for now..

// maybe add weight see data struct
//void Graph::add(int id, string *info){
//    VertexNode *newVertex = new VertexNode;
//    newVertex->data.id = id;
//    newVertex->data.data = *info;
//    if (id > 0 && *info != "/0") {  // input validation
//        if(graphList[newVertex]->addNode(id, info)) {
//            //inserted = true;
//            countVertex++;
//        }
//    }
//}
//
//
//
//void Graph::addVertex(int id, string *info, int weightID){
//    cout << "addVertex test line " << endl;
//    VertexNode *newVertex = new VertexNode;
//    newVertex->data.id = id;
//    newVertex->data.data = *info;
//    newVertex->data.weight = weightID;
//    if (id > 0 && *info != "/0") {
//        vertexList.push_back(newVertex);
//        //cout << "addVertex test line before addEdge " << endl;
//    }
//
//    //sort(vertexList.begin(), vertexList.end(), VertexNode());
//    //cout << "size of vector " << sizeof(vertexList.size()) << endl;
//}
//
//void Graph::addEdge(vector<int> adj[], int u, int v){
//void Graph::addEdge(vector<EdgeNode*> edgeList[], int u, int v){
//    cout << "addEdge test line " << endl;
//    adj[u].push_back(v);
//    adj[v].push_back(u);
//    for (auto elem : edgeList) {
//        //copy element elem into something
//    }
//}
//
//void Graph::addEdge2(){
//    int V = 5;
//    vector<int> adj[V];
//    addEdge(adj, vertexList[0]->data.id, vertexList[1]->data.id);
//    addEdge(adj, vertexList[0]->data.id, vertexList[4]->data.id);
//    addEdge(adj, vertexList[1]->data.id, vertexList[2]->data.id);
//    addEdge(adj, vertexList[1]->data.id, vertexList[3]->data.id);
//    addEdge(adj, vertexList[1]->data.id, vertexList[4]->data.id);
//    addEdge(adj, vertexList[2]->data.id, vertexList[3]->data.id);
//    addEdge(adj, vertexList[3]->data.id, vertexList[4]->data.id);
//}
//
//
//void Graph::addEdge(VertexNode newEdge){
//    cout << "initial addEdge test line " << endl;
//    if (id > 0 && *info != "/0"){  // input validation
//        if(graphList[newEdge.data.id]->addNode(id, info)) {
//            //inserted = true;
//            countVertex++;
//        }
//}
//
//void Graph::printGraph(){
//    cout << "initial print graph test line " << endl;
//    cout << adj->at(1) << endl;
//    cout << edgeList.at[0]->data.id << endl;
//
//    int V = 5;
//    cout << "initial print graph test line " << endl;
//    cout << edgeList[0] << endl;
//    cout << edgeList[0]->data.id << endl;
//    for (int v = 0; v < V; ++v) {
//        cout << "\n Adjacency list of vertex " << v
//             << "\n head ";
//        for (auto x : edgeList[v]->data.id) {
//            cout << "-> " << x;
//            printf("\n");
//        }
//    }
//}

//bool Graph::addEdge(int listID, int indexID, string *info, int weightID){
//    bool flag = false;
//    cout << "test line comparing vertex position and int id " << endl;
//    cout << vertexList[5]->data.id << vertexList[5]->data.data << endl;
//    if (indexID >= 0 && *info != "/0") {  // input validation
//        if (graphList[listID]->addNode(id, info)) {
//        if (graphList[listID]->addNode(vertexList[indexID]->data.id, &vertexList[indexID]->data.data, weightID)) {
//            flag = true;
//            countEdge++;
//        }
//    }
//    return flag;
//}

//    vertexList.assign(0, NULL);
//    for(int i = 0; i < GRAPHSIZE; i++){
//        LinkedList *newLinkedList = new LinkedList;
//        graphList.push_back(newLinkedList);
//    }
//    if (indexID >= 0 && listID >= 0){  // input validation
//        if (graphList[listID]->deleteNode(indexID)) {
//            flag = true;
//            countEdge -= 1;
//        }
//    }
//    return flag;