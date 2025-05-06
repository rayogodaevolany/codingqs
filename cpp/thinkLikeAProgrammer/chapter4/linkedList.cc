#include<iostream>
using namespace std;


// create a node struct
struct listNode {
    int grade;
    int studentNum;
    listNode* next;
};
typedef listNode* studentCollection;


// addRecord adds a record to the end of studentCollection
// input: head of record, grade, student number
// output: side effect add to linkedlist
void addRecord(studentCollection& sc, int grade, int studentNum){
    //create a new node
    listNode* newNode = new listNode;
    newNode->grade = grade;
    newNode->studentNum = studentNum;

    // make the new nodes pointer to the address sc points to
    newNode->next = (listNode*)sc;
    //change the sc pointer to the new node
    sc = newNode;
    // the newNode and sc now reference the newly added node; remove newNode.
    newNode = NULL;
}


// testAddRecord 
void testAddRecord(){
    studentCollection sc;
    listNode * node1 = new listNode;
    node1->studentNum = 1; node1->grade = 75;
    listNode * node2 = new listNode;
    node2->studentNum = 2; node2->grade = 98;
    listNode * node3 = new listNode;
    node3->studentNum = 3; node3->grade = 65;

    sc = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    node1 = node2 = node3 = NULL;

    addRecord(sc, 1274, 91);
}


// averageRecords returns the average grade of the records given
// input: head of collection
// output: average grade

double averageRecords(studentCollection sc) {
    double sum = 0;
    int count=0;
    if (!sc) return 0;
    // make a pointer to traverse
    listNode * pointer = sc;
    // while the pointer is valid
    while (pointer != NULL){
        // increment sum
        sum += pointer->grade;
        pointer = pointer->next;
        // increment counter
        count++;
    }
    return sum/count;
}

// test averageRecords
void testAverageRecords(){
    studentCollection sc;
    listNode * node1 = new listNode;
    node1->studentNum = 1; node1->grade = 75;
    listNode * node2 = new listNode;
    node2->studentNum = 2; node2->grade = 98;
    listNode * node3 = new listNode;
    node3->studentNum = 3; node3->grade = 65;

    sc = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    node1 = node2 = node3 = NULL;

    studentCollection zero = NULL;
    cout << averageRecords(zero);

}
int main(){
    testAddRecord();
    testAverageRecords();
    return 0;
}
