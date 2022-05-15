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
    srand(time(NULL));
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
    string vertexF = "F";
    string vertexG = "G";
    string vertexH = "H";

    //##########################################
    //TESTING AND SET UP
    //##########################################

    cout << "******* TESTING *****************************" << endl;
    cout << "creating the graph..." << endl;
    Graph *graph = new Graph;
    cout << "done" << endl;
    cout << endl;

    // show it is empty by calling counts and print
    cout << "testing initial printing of vertices " << endl;
    for (int i = 0; i < GRAPHSIZE; i++) {
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
    graph->addEdge(4, &vertexE, 4, &vertexD, 1); //E to D

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
    if (graph->addVertex(8, &vertexI)){
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

//  REMOVE TESTING
//  REMOVE EDGE
    cout << "Testing of removing Edge connection to vector " << endl;
    cout << endl;
    cout << "removeEdge testing " << endl;
    cout << "Removing index from graphList " << endl;
    cout << "Getting edge count before removal " << endl;
    cout << "There are " << graph->getEdgeCount() << " Edge entries in graphList " << endl;
    cout << endl;
    cout << "Trying indexes : " << ids[2] << ":" << ids[2] << "..." << endl;
    if (graph->removeEdge(2, 2)) { // removing...
        cout << "Success, index: "<< ids[2] << ids[2] << " removed" << endl;
    } else {
        cout << "Failed, index: " << ids[2] << ids[2] << " was not found" << endl;
    }
    cout << endl;
    cout << "Confirming if edge was removed after removeEdge called" << endl;
    cout << "There are " << graph->getEdgeCount() << " Edge entries in graphList " << endl;
    cout << endl;

//  REMOVE VERTEX
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

//  PRINT TESTING AFTER ADDING EDGE CONNECTIONS
    cout << "Print for each graph list after Edge Data added " << endl;
    for (int i = 0; i < GRAPHSIZE; i++){
        graph->printGraph(i);
    }

    //##########################################
    //TESTING VARIOUS COMBINATIONS OF OPERATIONS
    //##########################################

    cout << "Testing various combinations of methods " << endl;
    cout << "Current graph and vertex count and edge count " << endl;
    cout << endl;
    for (int i = 0; i < GRAPHSIZE; i++){
        graph->printGraph(i);
    }
    cout << "There are " << graph->getEdgeCount() << " edge entries in the current graph." << endl;
    cout << "done" << endl;
    cout << endl;
    cout << "There are " << graph->getVertexCount() << " vertex entries in the current graph." << endl;
    cout << endl;

    // ADDING VERTICES
    string vertexJ = "J";
    if (graph->addVertex(9, &vertexJ)){
        cout << "success. entry inserted." << endl;
        cout << "There are " << graph->getVertexCount() << " Vertex entries in vertexList " << endl;
        cout << endl;
    }else{
        cout << endl;
        cout << "failed to insert entry: " << 8 << endl;
        cout << endl;
    }
    string vertexK = "K";
    if (graph->addVertex(10, &vertexK)){
        cout << "success. entry inserted." << endl;
        cout << "There are " << graph->getVertexCount() << " Vertex entries in vertexList " << endl;
        cout << endl;
    }else{
        cout << endl;
        cout << "failed to insert entry: " << 8 << endl;
        cout << endl;
    }

    // ADDING EDGES
    cout << "Testing of adding additional Edge connection to vector " << endl;
    if (graph->addEdge(5, &vertexF, 6, &vertexG, 7)){
        cout << "success. entry inserted." << endl;
        cout << "There are " << graph->getEdgeCount() << " Edge connection entries in graphList " << endl;
        cout << endl;
    }else{
        cout << endl;
        cout << "failed to insert entry: " << 5 << endl;
        cout << endl;
    }
    cout << endl;
    cout << "Testing of adding additional Edge connection to vector " << endl;
    if (graph->addEdge(6, &vertexG, 8, &vertexI, 7)){
        cout << "success. entry inserted." << endl;
        cout << "There are " << graph->getEdgeCount() << " Edge connection entries in graphList " << endl;
        cout << endl;
    }else{
        cout << endl;
        cout << "failed to insert entry: " << 5 << endl;
        cout << endl;
    }
    cout << "Displaying counts for vertex and edge connections after vertex and edge added" << endl;
    cout << "There are " << graph->getVertexCount() << " Vertex entries in vertexList " << endl;
    cout << "There are " << graph->getEdgeCount() << " Edge connection entries in graphList " << endl;
    cout << endl;
    //    Print after additional vertex and edge connection
    cout << "Testing print for each graph list after additional vertex and edge data added " << endl;
    for (int i = 0; i < GRAPHSIZE; i++){
        graph->printGraph(i);
    }

//     MORE GET TESTING
    // Print before testing get edge, vertex with random numbers
    cout << "Print for each graph list before get edge and get vertex extra tests" << endl;
    for (int i = 0; i < GRAPHSIZE; i++){
        graph->printGraph(i);
    }
    cout << "Testing a couple random vertex retrievals from a graph " << endl;
    for (int i = 0; i < GRAPHSIZE; i++){
        int randID = ids[rand() % GRAPHSIZE];
        for(int j = 0; j < GRAPHSIZE; j++){
            if(graph->getVertex(j, randID)!= ""){
                cout << "found vertex " << graph->getVertex(j, randID) << randID << ":" << " in graphList " << j << endl;
            }else{
                cout << "empty string " << endl;
            }
        }
    }
    cout << endl;
    cout << "testing retrieval of -1 in get vertex in a graph with elements in it " << endl;
    cout << "Trying: " << "-1 " << "..." << endl;
    if(graph->getVertex(0, -1)!= ""){
        cout << "found -1 " << ": " << graph->getVertex(0, -1) << endl;
    }else{
        cout << "not found " << endl;
    }
    cout << endl;
    if(graph->getVertex(9, -1)!= ""){
        cout << "found -1 " << ": " << graph->getVertex(9, -1) << endl;
    }else{
        cout << "not found " << endl;
    }
    cout << endl;
    if(graph->getVertex(-1, -1)!= ""){
        cout << "found -1 " << ": " << graph->getVertex(-1, -1) << endl;
    }else{
        cout << "not found " << endl;
    }
    cout << endl;

    cout << "testing retrieval of 314159 in a table with elements in it " << endl;
    cout << "Trying: " << "314159 " << "..." << endl;
    if(graph->getVertex(0, 314159)!= ""){
        cout << "found 314159 " << ": " << graph->getVertex(0, 314159) << endl;
    }else{
        cout << "not found " << endl;
    }
    cout << endl;
    if(graph->getVertex(5, 314159)!= ""){
        cout << "found 314159 " << ": " << graph->getVertex(5, 314159) << endl;
    }else{
        cout << "not found " << endl;
    }
    cout << endl;

    cout << "Testing a couple random edge retrievals from a graph " << endl;
    for (int i = 0; i < GRAPHSIZE; i++){
        int randID = ids[rand() % GRAPHSIZE];
        for(int j = 0; j < GRAPHSIZE; j++){
            if(graph->getEdge(j, randID)!= ""){
                cout << "found edge " << graph->getEdge(j, randID) << randID << ":" << " in graphList " << j << endl;
            }else{
                cout << "not found " << endl;
            }
        }
    }
    cout << endl;
    cout << endl;
    cout << "testing retrieval of -1 in get vertex in a graph with elements in it " << endl;
    cout << "Trying: " << "-1 " << "..." << endl;
    if(graph->getEdge(0, -1)!= ""){
        cout << "found -1 " << ": " << graph->getEdge(0, -1) << endl;
    }else{
        cout << "not found " << endl;
    }
    cout << endl;
    if(graph->getEdge(9, -1)!= ""){
        cout << "found -1 " << ": " << graph->getEdge(9, -1) << endl;
    }else{
        cout << "not found " << endl;
    }
    cout << endl;
    if(graph->getEdge(-1, -1)!= ""){
        cout << "found -1 " << ": " << graph->getEdge(-1, -1) << endl;
    }else{
        cout << "not found " << endl;
    }
    cout << endl;
    cout << "testing retrieval of 314159 in a table with elements in it " << endl;
    cout << "Trying: " << "314159 " << "..." << endl;
    if(graph->getVertex(0, 314159)!= ""){
        cout << "found 314159 " << ": " << graph->getVertex(0, 314159) << endl;
    }else{
        cout << "not found " << endl;
    }
    cout << endl;
    if(graph->getVertex(5, 314159)!= ""){
        cout << "found 314159 " << ": " << graph->getVertex(5, 314159) << endl;
    }else{
        cout << "not found " << endl;
    }
    cout << endl;


//     MORE REMOVAL TESTING
    cout << "Testing a couple random edge removals from a graph with elements in it " << endl;
    cout << "There are " << graph->getEdgeCount() << " entries in the table before removal." << endl;
    int randID = ids[rand() % GRAPHSIZE];
    if(graph->removeEdge(randID, 2)){
        cout << "edge removed " << endl;
    }else{
        cout << "edge not removed " << endl;
    }
    if(graph->removeEdge(4, randID)){
        cout << "edge removed " << endl;
    }else{
        cout << "edge not removed " << endl;
    }
    if(graph->removeEdge(randID, randID)){
        cout << "edge removed " << endl;
    }else{
        cout << "edge not removed " << endl;
    }
    cout << "testing printGraph and getVertexCount after removal " << endl;
    for (int i = 0; i < GRAPHSIZE; i++){
        graph->printGraph(i);
    }
    cout << "There are " << graph->getEdgeCount() << " entries in the table." << endl;
    cout << "done" << endl;
    cout << endl;

    cout << "Testing a couple random vertex removals from a graph with elements in it " << endl;
    cout << "There are " << graph->getVertexCount() << " vertex entries in the graph before removal." << endl;
    if(graph->removeVertex(randID, 2)){
        cout << "vertex removed " << endl;
    }else{
        cout << "vertex not removed" << endl;
    }
    if(graph->removeVertex(3, randID)){
        cout << "vertex removed" << endl;
    }else{
        cout << "vertex not removed" << endl;
    }
    if(graph->removeVertex(randID, randID)){
        cout << "vertex removed " << endl;
    }else{
        cout << "vertex not removed" << endl;
    }
    if(graph->removeVertex(0, 1)){
        cout << "vertex removed " << endl;
    }else{
        cout << "vertex not removed" << endl;
    }
    cout << "testing printGraph and getVertexCount after removal " << endl;
    for (int i = 0; i < GRAPHSIZE; i++){
        graph->printGraph(i);
    }
    cout << "There are " << graph->getVertexCount() << " vertex entries in the graph." << endl;
    cout << "done" << endl;
    cout << endl;

    cout << "testing vertex removal of -1 from a graph with elements in it " << endl;
    cout << endl;
    cout << "Trying: " << "-1 " << "..." << endl;
    if (graph->removeVertex(0, -1)) {
        cout << "Success: " << "-1 " << " removed" << endl;
    } else {
        cout << "Failed: " << "-1 " << " was not found" << endl;
    }
    cout << endl;
    if (graph->removeVertex(-1, 3)) {
        cout << "Success: " << "-1 " << " removed" << endl;
    } else {
        cout << "Failed: " << "-1 " << " was not found" << endl;
    }
    cout << endl;
    cout << "testing vertex removal of 314159 from a graph with elements in it " << endl;
    cout << endl;
    cout << "Trying: " << "314159 " << "..." << endl;
    if (graph->removeVertex(0, 314159)) {
        cout << "Success: " << "314159 " << " removed" << endl;
    } else {
        cout << "Failed: " << "314159 " << " was not found" << endl;
    }
    cout << "current graph " << endl;
    cout << endl;
    for (int i = 0; i < GRAPHSIZE; i++) {
        graph->printGraph(i);
    }
    cout << "There are " << graph->getVertexCount() << " Vertex entries in graphList " << endl;
    cout << "There are " << graph->getEdgeCount() << " Edge entries in graphList " << endl;

    //************************************************
    //******** RANDOM TESTS ***************************
    //************************************************/

    cout << "******** RANDOM TESTS ***************************" << endl;
    cout << "using switch to randomly test methods " << endl;
    int randID2;
    int choice = rand() % CHOICES + 1;
    for (int i = 0; i < 15 * RANDOM_MULTIPLIER; i++) {
        switch (choice) {
            case 1:
            case 2:
                //add edge
                randID2 = rand() % GRAPHSIZE;
                cout << "addEdge random" << endl;
                if (graph->addEdge(ids[randID2], &strs[randID2], ids[randID2], &strs[randID2], ids[randID2])) {
                    cout << "success. entry inserted." << endl;
                    cout << "There are " << graph->getEdgeCount() << " entries in the table." << endl;
                } else {
                    cout << "failed to add " << ids[randID2] << strs[randID2] << endl;
                }
                cout << endl;
            case 3:
            case 4:
                // add vertex
                randID2 = rand() % GRAPHSIZE;
                cout << "addVertex random" << endl;
                if (graph->addVertex(ids[randID2], &strs[randID2])) {
                    cout << "success. entry inserted." << endl;
                    cout << "There are " << graph->getVertexCount() << " entries in the table." << endl;
                } else {
                    cout << "failed to add " << ids[randID2] << endl;
                }
                cout << endl;
                break;
            case 5:
            case 6:
                // removeVertex
                randID2 = ids[rand() % GRAPHSIZE];
                cout << "removeVertex " << endl;
                if (graph->removeVertex(randID2, randID2)) {
                    cout << "Success: " << randID2 << " removed" << endl;
                } else {
                    cout << "Failed: " << randID2 << " was not found" << endl;
                }
                cout << endl;
                break;
            case 7:
                // remove edge
                randID2 = ids[rand() % GRAPHSIZE];
                cout << "removeEdge " << endl;
                if (graph->removeEdge(randID2, randID2)) {
                    cout << "Success: " << randID2 << " removed" << endl;
                } else {
                    cout << "Failed: " << randID2 << " was not found" << endl;
                }
                cout << endl;
                break;
            case 8:
            case 9:
                // get edge
                randID2 = ids[rand() % GRAPHSIZE];
                cout << "getEdge " << endl;
                for (int i = 0; i < GRAPHSIZE; i++){
                    for(int j = 0; j < GRAPHSIZE; j++){
                        if(graph->getEdge(j, randID)!= ""){
                            cout << "found edge " << graph->getEdge(j, randID2) << randID2 << ":" << " in graphList " << j << endl;
                        }else{
                            cout << "not found " << endl;
                        }
                    }
                }
            case 10:
                // get vertex
                randID = ids[rand() % GRAPHSIZE];
                cout << "getVertex " << endl;
                for (int i = 0; i < GRAPHSIZE; i++) {
                    int randID2 = ids[rand() % GRAPHSIZE];
                    for (int j = 0; j < GRAPHSIZE; j++) {
                        if (graph->getVertex(j, randID2) != "") {
                            cout << "found vertex " << graph->getVertex(j, randID2) << randID2 << ":" << " in graphList "
                                 << j << endl;
                        } else {
                            cout << "empty string " << endl;
                        }
                    }
                }
                break;
            case 11:
                // get vertex count
                cout << "getVertexCount random" << endl;
                cout << "There are " << graph->getVertexCount() << " entries in the graph." << endl;
                cout << endl;
                break;
            case 12:
                //get edge count
                cout << "getEdgeCount random" << endl;
                cout << "There are " << graph->getEdgeCount() << " entries in the graph." << endl;
                cout << endl;
                break;


        }
        choice = rand() % CHOICES + 1;
    }
    cout << "Testing and showing current printTable and getCount after random method calls " << endl;
    cout << "current graph " << endl;
    cout << endl;
    for (int i = 0; i < GRAPHSIZE; i++){
        graph->printGraph(i);
    }
    cout << "There are " << graph->getVertexCount() << " Vertex entries in graphList " << endl;
    cout << "There are " << graph->getEdgeCount() << " Edge entries in graphList " << endl;
    cout << endl;

    return 0;
}
