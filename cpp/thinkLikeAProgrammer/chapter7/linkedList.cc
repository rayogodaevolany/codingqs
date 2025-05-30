#include<iostream>
#include <forward_list>
using namespace std;


// create a node struct
struct listNode {
    int grade;
    int studentNum;
};
// typedef listNode* studentCollection;


// addRecord adds a record to the end of studentCollection
// input: head of record, grade, student number
// output: side effect add to linkedlist
void addRecord(forward_list<listNode>& originalList, int studentNum, int grade){
    listNode * newNode = new listNode;
    newNode->grade = grade;
    newNode->studentNum = studentNum;
    originalList.push_front(*newNode);
}


// testAddRecord 
void testAddRecord(){
    forward_list<listNode> list;

    addRecord(list, 1, 75);
    addRecord(list, 2, 98);
    addRecord(list, 3, 65);
    forward_list<listNode>::iterator start = list.begin();
    while (start != list.end()){
        cout << start->grade << endl;
        start++;
    }
}


// averageRecords returns the average grade of the records given
// input: head of collection
// output: average grade

double averageRecords(forward_list<listNode>& list) {
    double sum = 0;
    int count=0;
    if (list.empty()) return 0;
    // iterate
    forward_list<listNode>::iterator start = list.begin(); 
    while (start != list.end()){
        sum += start->grade;
        count++;
        start++;
    }

    return sum/count;
}

// test averageRecords
void testAverageRecords(){

    forward_list<listNode> list;

    addRecord(list, 1, 75);
    addRecord(list, 2, 98);
    addRecord(list, 3, 65);

    cout << averageRecords(list) << endl;

}
int main(){
    // testAddRecord();
    testAverageRecords();
    return 0;
}
