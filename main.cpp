/*********************
Name: William Hammel
Final Project
Purpose: Description: Create a working bi-directional
weighted graph class with all the standard methods
for a data structure of that type.
**********************/

#include "main.h"

int main() {

    //##########################################
    //Creating Initial Test Data
    //##########################################
    int ids[GRAPHSIZE];
    string strs[GRAPHSIZE];
    char buffer[GRAPHSIZE];
    for (int i = 0; i < GRAPHSIZE; i++) {
        ids[i] = i;
        for (int j = 0; j < GRAPHSIZE; j++) {
            strs[j] = 'A' + j;
            //buffer[j] = 'A' + i;
        }
        buffer[GRAPHSIZE - 1] = '\0';
        //strs[i] = buffer;
    }
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << GRAPHSIZE << " entries)..." << endl;
    for (int i = 0; i < GRAPHSIZE; i++) {
        cout << strs[i] << ":" << ids[i] << endl;
    }
    cout << endl;

    string vertexA = "A";
    string vertexB = "B";
    string vertexC = "C";
    string vertexD = "D";
    string vertexE = "E";


    //##########################################
    //TESTING AND SET UP
    //##########################################

    cout << "******* TESTING *****************************" << endl;
    cout << "creating the graph..." << endl;
    Graph* graph = new Graph;
    cout << "done" << endl;
    cout << endl;

    // show it is empty by calling counts and print
    cout << "testing initial printing of vertices " << endl;
    for (int i = 0; i < GRAPHSIZE; i++){
        graph->printGraph(i);
    }
    cout << "testing initial count for getVertexCount " << endl;
    cout << "There are " << graph->getVertexCount() << " Vertex entries in vertexList " << endl;
    cout << "done" << endl;
    cout << endl;
    cout << "testing initial count for getEdgeCount " << endl;
    cout << "There are " << graph->getEdgeCount() << " Edge connection entries in graphList " << endl;
    cout << "done" << endl;
    cout << endl;

    //ADDING TEST DATA TO VERTEX VECTOR
    //adding Vertices
    for (int i = 0; i < GRAPHSIZE; i++) {
        if (graph->addVertex(ids[i], &strs[i])) {
            cout << "success. entry inserted." << endl;
            cout << "There are " << graph->getVertexCount() << " Vertex entries in vertexList " << endl;
            cout << "There are " << graph->getEdgeCount() << " Edge connection entries in graphList " << endl;
            cout << endl;
        } else {
            cout << endl;
            cout << "failed to insert entry: " << ids[i] << endl;
            cout << endl;
        }
    }

//  CONNECTIONS OF VERTICES AND WEIGHTS
    //adding connection A to B and A to D
    //to graphList[0]
    graph->addEdge(0, &vertexA, 1, &vertexB, 4); //A to B
    graph->addEdge(0, &vertexA, 3, &vertexD, 8); //A to D
    cout << "There are " << graph->getVertexCount() << " Vertex entries in vertexList " << endl;
    cout << "There are " << graph->getEdgeCount() << " Edge connection entries in graphList " << endl;
    cout << endl;
//  adding connection B to A, B to C
//  and B to D to graphList[1]
    graph->addEdge(1, &vertexB, 0, &vertexA, 4); //B to A
    graph->addEdge(1, &vertexB, 2, &vertexC, 3); //B to C
    graph->addEdge(1, &vertexB, 3, &vertexD, 5); //B to D
    cout << "There are " << graph->getVertexCount() << " Vertex entries in vertexList " << endl;
    cout << "There are " << graph->getEdgeCount() << " Edge connection entries in graphList " << endl;
    cout << endl;
//  adding connection C to B, C to D
//  to graphList[2]
    graph->addEdge(2, &vertexC, 1, &vertexB, 3); //C to B
    graph->addEdge(2, &vertexC, 3, &vertexD, 2); //C to D
    cout << "There are " << graph->getVertexCount() << " Vertex entries in vertexList " << endl;
    cout << "There are " << graph->getEdgeCount() << " Edge connection entries in graphList " << endl;
    cout << endl;
//  adding connection D to A, D to B
//  and D to E, to graphList[3]
    graph->addEdge(3, &vertexD, 0, &vertexA, 8); //D to A
    graph->addEdge(3, &vertexD, 1, &vertexB, 5); //D to B
    graph->addEdge(3, &vertexD, 2, &vertexC, 5); //D to C
    graph->addEdge(3, &vertexD, 4, &vertexE, 1); //D to E
    cout << "There are " << graph->getVertexCount() << " Vertex entries in vertexList " << endl;
    cout << "There are " << graph->getEdgeCount() << " Edge connection entries in graphList " << endl;
    cout << endl;
//    adding connection E to D in graphList 4
//    graph->addEdge(4, &vertexE, 4, &vertexD, 1); //E to D

//    GET VERTEX TESTING
    cout << "Initial testing getVertex " << endl;
    for (int i = 0; i < GRAPHSIZE; i++){
        for(int j = 0; j < GRAPHSIZE; j++){
            if(graph->getVertex(j, i)!= ""){
                cout << "found vertex " << graph->getVertex(j, i) << i << ":" << " in graphList " << j << endl;
            }else{
                cout << "empty string " << endl;
            }
        }
    }
    cout << endl;

//  GET EDGE TESTING
    cout << "Initial testing getEdge " << endl;
    for (int i = 0; i < GRAPHSIZE; i++){
        for(int j = 0; j < GRAPHSIZE; j++){
            if(graph->getEdge(j, i)!= ""){
                cout << "found edge " << graph->getEdge(j, i) << i << ":" << " in graphList " << j << endl;
            }else{
                cout << "empty string " << endl;
            }
        }
    }
    cout << endl;

//  ADD TESTING
    cout << "Displaying counts for vertex and edge connections before edge and vertex added" << endl;
    cout << "There are " << graph->getVertexCount() << " Vertex entries in vertexList " << endl;
    cout << "There are " << graph->getEdgeCount() << " Edge connection entries in graphList " << endl;
    cout << endl;
//    ADDING ADDITIONAL VERTEX
    cout << "Initial testing of adding additional vertex to vector " << endl;
    string vertexI = "I";
    if (graph->addVertex(8, &vertexI)){ //F note index is 5
        cout << "success. entry inserted." << endl;
        cout << "There are " << graph->getVertexCount() << " Vertex entries in vertexList " << endl;
        cout << endl;
    }else{
        cout << endl;
        cout << "failed to insert entry: " << 8 << endl;
        cout << endl;
    }
//     ADDING ADDITIONAL EDGE CONNECTION
    cout << "Testing of adding additional Edge connection to vector " << endl;
    if (graph->addEdge(8, &vertexI, 4, &vertexE, 5)){
        cout << "success. entry inserted." << endl;
        cout << "There are " << graph->getEdgeCount() << " Edge connection entries in graphList " << endl;
        cout << endl;
    }else{
        cout << endl;
        cout << "failed to insert entry: " << 5 << endl;
        cout << endl;
    }

    cout << endl;
    cout << "Displaying counts for vertex and edge connections after vertex and edge added" << endl;
    cout << "There are " << graph->getVertexCount() << " Vertex entries in vertexList " << endl;
    cout << "There are " << graph->getEdgeCount() << " Edge connection entries in graphList " << endl;
    cout << endl;

    //    Print after additional vertex and edge connection
    cout << "Testing print for each graph list after additional vertex and edge data added " << endl;
    for (int i = 0; i < GRAPHSIZE+1; i++){
        graph->printGraph(i);
    }

//    REMOVE TESTING
    cout << "Testing of removing Edge connection to vector " << endl;
    cout << endl;
    cout << "removeEdge testing " << endl;
    cout << "Removing index from graphList " << endl;
    cout << "Getting edge count before removal " << endl;
    cout << "There are " << graph->getEdgeCount() << " Edge entries in graphList " << endl;
    cout << endl;
    cout << "Trying index: " << ids[1] << "..." << endl;
    if (graph->removeEdge(1, 1)) { // removing...
        cout << "Success, index: " << ids[1] << " removed" << endl;
    } else {
        cout << "Failed, index: " << ids[1] << " was not found" << endl;
    }
    cout << endl;
    cout << "Confirming if edge was removed after removeEdge called" << endl;
    cout << "There are " << graph->getEdgeCount() << " Edge entries in graphList " << endl;
    cout << endl;

    cout << "removeVertex testing " << endl;
    cout << endl;
    cout << "Removing vertex node from vertexList " << endl;
    cout << "Getting vertex count before removal " << endl;
    cout << "There are " << graph->getVertexCount() << " Vertex entries in graphList " << endl;
    cout << endl;
    cout << "Trying to remove vertex: " << graph->getVertex(3, 3) << " in graph " << 3 << "..." << endl;
    if (graph->removeVertex(3,3)) { // vertexList 3, removing index 3
        cout << "Success, index: " << graph->getVertex(3, 3) << " removed" << endl;
    } else {
        cout << "Failed, index: " << graph->getVertex(3, 3) << " was not found" << endl;
    }
    cout << "Confirming if vertex was removed after removeVertex called" << endl;
    cout << "There are " << graph->getVertexCount() << " Vertex entries in graphList " << endl;
    cout << endl;

//    PRINT TESTING AFTER ADDING EDGE CONNECTIONS
    cout << "Print for each graph list after Edge Data added " << endl;
    for (int i = 0; i < GRAPHSIZE; i++){
        graph->printGraph(i);
    }

// NOTE CLEARING LIST NOT WORKING ATM
// NEED TO ADD DFS AND BFS

    return 0;
}

