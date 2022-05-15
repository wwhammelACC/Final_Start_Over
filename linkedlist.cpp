/*********************
Name: William Hammel
Final Project
Purpose: Description: Create a working bi-directional
weighted graph class with all the standard methods
for a data structure of that type.
**********************/

#include "linkedlist.h"

/*
 * ****************************************
 * Constructors / Destructors
 * ****************************************
 */


//constructor
LinkedList::LinkedList() {

    head = NULL;
}

//desctructor
LinkedList::~LinkedList() {
    clearList();
}

/*
 * ****************************************
 * Public
 * ****************************************
 */

bool LinkedList::addNode(int id, string *info, int weightID){
    bool inserted = false;
    if (id >= 0 && *info != "/0"){
        // empty list here
        if(head == NULL) {
            Node *newNode = new Node;
            newNode->data.id = id;
            newNode->data.data = *info;
            newNode->data.weight = weightID;
            newNode->next = nullptr;
            head = newNode;
            tails = head; // essentially renaming headPointers
            inserted = true;
        }else{
            // current next will be new node
            if(!exists(id)){
                Node *newNode = new Node;
                newNode->data.id = id;
                newNode->data.data = *info;
                newNode->data.weight = weightID;
                tails->next = newNode;
                newNode->next = nullptr;
                tails = newNode;
                inserted = true;
            }
        }
    }
    return inserted;
}

bool LinkedList::deleteNode(int id){
    bool removed = false;
    if (id >= 0) {  // input validation
        if(head && id == head->data.id && head->next == NULL){//Single Node
            delete head;
            head = NULL;
            removed = true;
        }else if(head && id == head->data.id && head->next != NULL){ //head
            Node *current = head;
            head = head->next;
            delete current;
            removed = true;
            // if exists and id doesnt match
        }else if(head && head->next != NULL){
            Node *current = head;
            Node *currentNext = head->next;
            while (current->next != NULL && id != currentNext->data.id){
                current = current->next;
                currentNext = currentNext->next;
            }
            if(current->next && id == current->next->data.id && current->next->next == NULL){ // tail
                current->next = currentNext->next;
                tails = current;
                delete currentNext;
                removed = true;
            }else if(current->next && id == current->next->data.id){ // middle
                current->next = currentNext->next;
                delete currentNext;
                removed = true;
            }
        }
    }
    return removed;
}

int LinkedList::getHeadId() {
    Node *current = head;
    return current->data.id;
}

bool LinkedList::getNode(int id, Data *info) {
        bool flag = false;
    if (head != NULL) {
        Node *current = head;
        while (id != current->data.id && current->next != NULL) {
            current = current->next;
        }
        if (id == current->data.id) {
            info->data = current->data.data; // data is the string
            info->id = current->data.id;     // this is the int id
            flag = true;
        }
        else {
            info->data = "";
            info->id = -1;
            flag = false;
        }
    }
    return flag;
}

void LinkedList::printList(bool direction) {
    //bool flag = true;
    Node *current = head;
    if (direction == false) {    //traverse forward
        int i = 1;
        if (current == NULL) {
            cout << "Empty " << endl;
        } else {
            while (current != NULL) {
                cout << current->data.data << current->data.id << ":" << current->data.weight << "->";
                current = current->next; // go to the next node
                i++;
            }
            cout << "\b\b  ";
            cout << endl;
        }
    } else {
        current = head; // start a "tracking" pointer by pointing it head
        int i = 1;
        bool tail = false;
        while (current && !tail) { // find the tail
            if (current->next) {
                current = current->next;
            } else {
                tail = true; // found the tail
            }
        }
        // now traverse it backward
        if (current == NULL) {
            cout << "Empty " << endl;
        }else{
            while (current) {
                cout << current->data.data << current->data.id << ":" << current->data.weight << "->";
                current = current->prev;
                i++;
            }
            cout << "\b\b  ";
            cout << endl;
        }
    }
    cout << endl;
}

int LinkedList::getCount() {
    int count = 0;
    Node *current = head;
    while (current != NULL) {
        current = current->next; // go to the next node
        count++;
    }
    return count;
}

bool LinkedList::clearList(){
    bool success = false;
    if(head != NULL){
        Node *current = head;
        while(current != NULL){
            head = current->next;
            delete current;
            current = head;
        }
        head = NULL;
        success = true;
    }
    return success;
}

bool LinkedList::exists(int id) {
    bool flag = false;
    if (head != NULL) {
        Node *current = head; // NULL to current
        while (id != current->data.id && current->next != NULL) {
            current = current->next;
        }
        if (id == current->data.id) {
            flag = true;
        }
    }
    return flag;
}



