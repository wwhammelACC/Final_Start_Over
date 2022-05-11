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
    //INITIAL TESTING AND SET UP
    //##########################################

    cout << "******* INITIAL SET UP TESTING *****************************" << endl;
    cout << "creating the graph..." << endl;
    Graph* graph = new Graph;
    cout << "done" << endl;
    cout << endl;

    string vertexA = "A";
    string vertexB = "B";
    string vertexC = "C";
    string vertexD = "D";
    string vertexE = "E";
    int weightAB = 4;
    int weightAD = 8;
    int weightBA = 4;
    int weightBC = 3;
    int weightBD = 5;
    int weightCB = 3; // same as BC?
    int weightCD = 2;
    int weightDA = 8; // same as AD?
    int weightDB = 5; // same as DB?
    int weightDE = 1;

    //adding Vertices
    graph->addVertex(1, &vertexA); //A
    graph->addVertex(2, &vertexB); //B
    graph->addVertex(3, &vertexC); //C
    graph->addVertex(4, &vertexD); //D
    graph->addVertex(5, &vertexE); //E


    // INITIAL PRINT starts at index 0
    graph->printGraph();

    return 0;
}

