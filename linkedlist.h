/*********************
Name: William Hammel
Final Project
Purpose: Description: Create a working bi-directional
weighted graph class with all the standard methods
for a data structure of that type.
**********************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "data.h"
#include <iostream>

using std::cout;
using std::endl;

class LinkedList{

    /*
    * write all your public method prototypes here
    * this includes you constructor and destructor
    */

public:
    // public methods
    LinkedList();
    ~LinkedList();

    bool addNode(int, string*, int); // accepts id and data, and inserts to the list in order
    bool deleteNode(int); // accepts an id and deletes the node
    bool getNode(int, Data*); // retrieves the data from a node from a given id
    void printList(bool = false); // prints forward (default) or backward
    int getCount(); // reports the count (dynamically)
    bool clearList(); // deallocates all nodes and sets head to NULL
    bool exists(int); // tests for the existence of a node based on a given id

    /*
     * write all your private method prototypes here
     */

//private:
    // only attribute needed
    Node *head;
    Node *tails;
    void addHead(int, string*, Node*, Node*);
    void addMiddle(int, string*, Node*, Node*);
    void addTail(int, string*, Node*, Node*);
    void nodeAllocate(int, string*, Node**);
};

#endif //LINKEDLIST_H
