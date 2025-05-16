#include <iostream>
#include "../include/recordCollection.h"
using namespace std;

recordCollection::recordCollection(){
    _head = nullptr;
}

recordCollection::~recordCollection(){
    deleteList(_head);
}

recordCollection& recordCollection::operator=(const recordCollection & rhs){
    if (this != &rhs){
        deleteList(_head);
        _head = copyList(rhs._head);
    }
    return *this;
}

int recordCollection::length(){
    listNode * pointer = _head;
    int length = 0;

    while(pointer != nullptr){
        length++;
        pointer = pointer->next;
    }

    return length;
}

// method returns array of the list values
int* recordCollection::grades(){
    // run through every node adding to vector
    //
    listNode * pointer = _head;
    int len; len = length();
    int * grades = new int[len];

    int i = 0;
    while(pointer != nullptr){
        grades[i] = pointer->grade;
        pointer = pointer->next;
        i++;
    }

    return grades;
}

// addRecord adds a record to the end of studentCollection
// input: head of record, grade, student number
// output: side effect add to linkedlist
void recordCollection::addRecord(
        int grade,
        int studentNum
        ){
    //create a new node
    listNode* newNode = new listNode;
    newNode->grade = grade;
    newNode->studentNum = studentNum;

    // make the new nodes pointer to the address _head points to
    newNode->next = (listNode*)_head;
    //change the _head pointer to the new node
    _head = newNode;
    // the newNode and _head now reference the newly added node; remove newNode.
    newNode = nullptr;
}

// averageRecords returns the average grade of the records given
// input: head of collection
// output: average grade

double recordCollection::averageRecords() {
    double sum = 0;
    int count=0;
    if (_head == nullptr) return 0;
    // make a pointer to traverse
    listNode * pointer = _head;
    // while the pointer is valid
    while (pointer != nullptr){
        // increment sum
        sum += pointer->grade;
        pointer = pointer->next;
        // increment counter
        count++;
    }
    return sum/count;
}


void recordCollection::deleteList(listNode* &head){
    listNode* pointer = head;

    while(pointer != nullptr){
        listNode * tmp = pointer->next;
        delete pointer;
        pointer = tmp;
    }
    head = nullptr;
}

recordCollection::studentCollection recordCollection::copyList(listNode * head){
    // create new list
    studentCollection newHead = nullptr;
    // return if head is null
    if(head == nullptr) return newHead;
    // create a pointer for head
    listNode* pointer = head->next;
    listNode* trailing = newHead;

    // create one node and copy info into it
    newHead = new listNode;
    newHead->grade = head->grade;
    newHead->studentNum = head->studentNum;
    newHead->next = nullptr;

    // loop over the head list and copy info into the new list
    // use a trailing pointer to connect the nodes
    while (pointer != nullptr){
        listNode * newNode = new listNode;
        newNode->grade = pointer->grade;
        newNode->studentNum = pointer->studentNum;

        trailing->next = newNode;
        trailing = trailing->next;
        pointer = pointer->next;
    }

    return newHead;

}

// routine runs through the collection picking up those that fall
// through the filter and then create a new collection with those records.
// inclusive
// input: filter ranges
// output: new collection
recordCollection recordCollection::RecordsWithinRange(double low, double high){
    // create new recordCollection
    recordCollection newrc;

    // if invalid low and high
    if( low > high) return newrc;

    // create pointer
    listNode * pointer = _head;

    // loop to add those that fit
    while(pointer != nullptr){
        if(pointer->grade >= low && pointer->grade <= high){
            newrc.addRecord(pointer->grade, pointer->studentNum);
        }
        pointer = pointer->next;
    }

    return newrc;
}

