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
    //INITIAL TESTING AND SET UP
    //##########################################

    cout << "******* INITIAL SET UP TESTING *****************************" << endl;
    cout << "creating the graph..." << endl;
    Graph* graph = new Graph;
    cout << "done" << endl;
    cout << endl;

//    cout << graph->addVertex(2, &vertexA) << endl;
//    cout << endl;

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

    // INITIAL ADDING TEST DATA TO VERTEX VECTOR
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

    // INITIAL CONNECTIONS OF VERTICES AND WEIGHTS
    //adding connection A to B and A to D
    //to graphList[0]
    graph->addEdge(0, &vertexA, 1, &vertexB, 4); //A to B
    graph->addEdge(0, &vertexA, 3, &vertexD, 8); //A to D
    cout << "There are " << graph->getVertexCount() << " Vertex entries in vertexList " << endl;
    cout << "There are " << graph->getEdgeCount() << " Edge connection entries in graphList " << endl;
    cout << endl;
//    //adding connection B to A, B to C
//    //and B to D to graphList[1]
    graph->addEdge(1, &vertexB, 0, &vertexA, 4); //B to A
    graph->addEdge(1, &vertexB, 2, &vertexC, 3); //B to C
    graph->addEdge(1, &vertexB, 3, &vertexD, 5); //B to D
    cout << "There are " << graph->getVertexCount() << " Vertex entries in vertexList " << endl;
    cout << "There are " << graph->getEdgeCount() << " Edge connection entries in graphList " << endl;
    cout << endl;
//    //adding connection C to B, C to D
//    //to graphList[2]
    graph->addEdge(2, &vertexC, 1, &vertexB, 3); //C to B
    graph->addEdge(2, &vertexC, 3, &vertexD, 2); //C to D
    cout << "There are " << graph->getVertexCount() << " Vertex entries in vertexList " << endl;
    cout << "There are " << graph->getEdgeCount() << " Edge connection entries in graphList " << endl;
    cout << endl;
//    //adding connection D to A, D to B
//    //and D to E, to graphList[3]
    graph->addEdge(3, &vertexD, 0, &vertexA, 8); //D to A
    graph->addEdge(3, &vertexD, 1, &vertexB, 5); //D to B
    graph->addEdge(3, &vertexD, 2, &vertexC, 5); //D to C
    graph->addEdge(3, &vertexD, 4, &vertexE, 1); //D to E
    cout << "There are " << graph->getVertexCount() << " Vertex entries in vertexList " << endl;
    cout << "There are " << graph->getEdgeCount() << " Edge connection entries in graphList " << endl;
    cout << endl;
    // adding connection E to D in graphList 4
//    graph->addEdge(4, &vertexE, 4, &vertexD, 1); //E to D

     //INITIAL GET VERTEX TESTING
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
    //INITIAL GET EDGE TESTING
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

//    INITIAL REMOVE TESTING
//    cout << "initial removeEdge testing " << endl;
//    cout << "Removing index from graphList " << endl;
//    cout << "Getting edge count befoe removal " << endl;
//    cout << "There are " << graph->getEdgeCount() << " Edge entries in graphList " << endl;
//    cout << "Trying index: " << ids[1] << "..." << endl;
//    if (graph->removeEdge(1, 1)) { // removing...
//        cout << "Success, index: " << ids[1] << " removed" << endl;
//    } else {
//        cout << "Failed, index: " << ids[1] << " was not found" << endl;
//    }
//    cout << "Confirming if edge was removed after removeEdge called" << endl;
//    cout << "There are " << graph->getEdgeCount() << " Edge entries in graphList " << endl;
//    cout << endl;

//    cout << "Printing before vertex removed " << endl;
//    for (int i = 0; i < GRAPHSIZE; i++){
//        graph->printGraph(i);
//    }
//    cout << "initial removeVertex testing " << endl;
//    cout << "Removing vertex node from vertexList " << endl;
//    cout << "Trying to remove vertex: " << graph->getVertex(3, 3) << " in graph " << 3 << "..." << endl;
//    if (graph->removeVertex(3,3)) { // vertexList 3, removing index 3
//        cout << "Success, index: " << graph->getVertex(3, 3) << " removed" << endl;
//    } else {
//        cout << "Failed, index: " << graph->getVertex(3, 3) << " was not found" << endl;
//    }
//    cout << "Confirming if vertex was removed after removeVertex called" << endl;
//    cout << "There are " << graph->getVertexCount() << " Vertex entries in graphList " << endl;
//    cout << endl;

    // INITIAL PRINT TESTING AFTER ADDING EDGE CONNECTIONS
//    cout << "Testing initial print for each graph list after Edge Data added " << endl;
//    for (int i = 0; i < GRAPHSIZE; i++){
//        graph->printGraph(i);
//    }

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
//    cout << "Initial testing of adding additional Edge connection to vector " << endl;
//    if (graph->addEdge(8, &vertexI, 4, &vertexE, 5)){
//        cout << "success. entry inserted." << endl;
//        cout << "There are " << graph->getEdgeCount() << " Edge connection entries in graphList " << endl;
//        cout << endl;
//    }else{
//        cout << endl;
//        cout << "failed to insert entry: " << 5 << endl;
//        cout << endl;
//    }
//    if (graph->addEdge(4, &vertexE, 8, &vertexI, 5)){
//        cout << "success. entry inserted." << endl;
//        cout << "There are " << graph->getEdgeCount() << " Edge connection entries in graphList " << endl;
//        cout << endl;
//    }else{
//        cout << endl;
//        cout << "failed to insert entry: " << 5 << endl;
//        cout << endl;
//    }
//    graph->addEdge(3, &vertexD, 4, &vertexE, 1); // D to E
//    graph->addEdge(4, &vertexE, 8, &vertexI, 5); // E to I
//    graph->addEdge(8, &vertexI, 4, &vertexE, 5); // I to E
//    graph->addEdge(8, &vertexI, 4, &vertexD, 6); // I to D


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
// NOTE CLEARING LIST NOT WORKING ATM
// NEED TO ADD DFS AND BFS


    return 0;
}


//    int V = 5;
//    vector<int> adj[V];
//    graph->addEdge(adj, 0, 1);
//    graph->addEdge(adj, 0, 4);
//    graph->addEdge(adj, 1, 2);
//    graph->addEdge(adj, 1, 3);
//    graph->addEdge(adj, 1, 4);
//    graph->addEdge(adj, 2, 3);
//    graph->addEdge(adj, 3, 4);

//adding Edges
//    graph->addEdge(weightAB);
//    graph->addEdge(weightAD);
//    graph->addEdge(weightBA);
//    graph->addEdge(weightBC);
//    graph->addEdge(weightBD);
//    graph->addEdge(weightCB);
//    graph->addEdge(weightCD);
//    graph->addEdge(weightDA);
//    graph->addEdge(weightDB);
//    graph->addEdge(weightDE);

//graph->addEdge2();


//SAVE FOR LATER MAYBE
//seed the rand function
//    srand(time(NULL));

//    const int testdatasize = BASE + (rand() % OFFSET + 1);
//    int ids[testdatasize];
//    string strs[testdatasize];
//
//    char buffer[BUFFERSIZE];
//    for (int i = 0; i < testdatasize; i++) {
//        ids[i] = rand() % MAXID + 1;
//        for (int j = 0; j < BUFFERSIZE - 1; j++) {
//            buffer[j] = 'a' + i;
//        }
//        buffer[BUFFERSIZE - 1] = '\0';
//        strs[i] = buffer;
//    }
//    ids[testdatasize-2] = ids[testdatasize-3];
//    strs[testdatasize-2] = "known duplicate";
//    ids[testdatasize-1] = - 1;
//    strs[testdatasize-1] = "known bad";
//
//    /*
//     * Show test data
//     */
//    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
//    for (int i = 0; i < testdatasize; i++) {
//        cout << ids[i] << " : " << strs[i] << endl;
//    }
//    cout << endl;

//void Graph::breadthFirstTraversal(int startVertex){
//    DataVertex* current;
//    for(int i=0; i<5; i++){
//        cout << "vertex " << graphList[i]->data.id << " contains: " << graphList[i]->data.information << endl;
//        current = graphList[i]->next;
//        while(current){
//            cout << " t is connected to vertex " << current->data.id << " which contains: " << current->data.information << endl;
//            current = current->next;
//        }
//    }
//}
//    graph->addVertex(0, &vertexA); //A note index is 0
//    graph->addVertex(1, &vertexB); //B note index is 1
//    graph->addVertex(2, &vertexC); //C note index is 2
//    graph->addVertex(3, &vertexD); //D note index is 3
//    graph->addVertex(4, &vertexE); //E note index is 4
//    //adding connection C to B, C to D
//    //to graphList[2]
//    graph->addEdge(2, 2, &vertexC, 0); //C
//    graph->addEdge(2, 1, &vertexB, 3); //B
//    graph->addEdge(2, 3, &vertexD, 2); //D
//    cout << "There are " << graph->getVertexCount() << " Vertex entries in vertexList " << endl;
//    cout << "There are " << graph->getEdgeCount() << " Edge connection entries in graphList " << endl;
//    cout << endl;
//    //adding connection D to A, D to B
//    //and D to E, to graphList[3]
//    graph->addEdge(3, 3, &vertexD, 0); //D
//    graph->addEdge(3, 0, &vertexA, 8); //A
//    graph->addEdge(3, 1, &vertexB, 5); //B
//    graph->addEdge(3, 4, &vertexB, 1); //E
//    cout << "There are " << graph->getVertexCount() << " Vertex entries in vertexList " << endl;
//    cout << "There are " << graph->getEdgeCount() << " Edge connection entries in graphList " << endl;
//    cout << endl;

//    cout << "printing graph list 0 in vector " << endl;
//    graph->printGraph(0);
//    cout << "printing graph list 1 in vector " << endl;
//    graph->printGraph(1);
//    cout << "printing graph list 2 in vector " << endl;
//    graph->printGraph(2);
//    cout << "printing graph list 3 in vector " << endl;
//    graph->printGraph(3);
//
//int weightAB = 4;
//int weightAD = 8;
//int weightBA = 4;
//int weightBC = 3;
//int weightBD = 5;
//int weightCB = 3; // same as BC?
//int weightCD = 2;
//int weightDA = 8; // same as AD?
//int weightDB = 5; // same as DB?
//int weightDC = 2;
//int weightDE = 1;
//    cout << "printing graph list 1 in vector " << endl;
//    graph->printGraph(1);
//    cout << "Removing C from graphList 1" << endl;
//    graph->removeEdge(1, 2); // graphlist 1, removing index 2
//    cout << "Checking if C was removed from graphList 1" << endl;
//    graph->printGraph(1); //checking graphlist 1 after removing index 2
//
//    cout << "printing graph list 2 in vector " << endl;
//    graph->printGraph(2);
//    cout << "Removing D from graphList 2" << endl;
//    graph->removeEdge(2, 3); // graphlist 2, removing index 3
//    cout << "Checking if D was removed from graphList 2" << endl;
//    graph->printGraph(2); //checking list 2 after removing index 3
//    cout << "Clearing vertexList " << endl;
//    for(int i = 0; i < GRAPHSIZE; i++) {
//        for (int j = 0; j < (graph->getVertexCount()); j++) {
//            graph->removeVertex(i, j);
//        }
//    }
//    cout << endl;
//    cout << "There are " << graph->getVertexCount() << " Vertex entries in vertexList " << endl;
//    cout << endl;

//    cout << "Printing after vertices and edges removed to show cleared list " << endl;
//    for (int i = 0; i < GRAPHSIZE; i++){
//        graph->printGraph(i);
//    }

//Delete all, to start more in depth testing....
//    cout << "clearing graph lists " << endl;
//    for (int i = 0; i < GRAPHSIZE; i++) {
//        ids[i] = i;
//        for (int j = 0; j < GRAPHSIZE; j++) {
//            ids[j] = j;
//            if (graph->removeEdge(ids[i], ids[j])) {
//                cout << "Success: " << ids[i] << ":" << ids[j] << " removed" << endl;
//            } else {
//                cout << "Failed: " << ids[i] << ":" << ids[j] << " was not found" << endl;
//            }
//        }
//    }