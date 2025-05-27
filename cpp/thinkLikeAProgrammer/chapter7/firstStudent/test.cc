#include <iostream>
#include "scIterator.h"
#include "studentCollection.h"

using namespace std;


void sortAlgo(studentRecord arr[], size_t arraySize){
    // get a studentCollection array
    int start = 0;
    int end = arraySize;


    // while loop that starts with a flag that is true so that it at least checks once
    for (int i = start + 1; i < end; i++){
        if (arr[i].grade() == -1) continue;
        bool flag = true;
        int j = i;
        while (flag){
            //  checks for if it is in valid range
            if (j <= start) flag = false;
            //  checks for if it is the last one that is valid
            for (int m = j; arr[m] != -1 && arr[m].grade() < arr[j].grade(); m--){
                
            }
            //  swaps if necessary
            //
            j--;
        }
    }

    for (int i = start + 1; i < end; i++){
        // loop while the index is valid, and 
        // the value before is smaller than the current
        for (int j = i; j > start && arr[j].grade() < arr[j -1].grade(); j--){
        // continue swapping the values
        // the swapped records have to be only valid values
           studentRecord tmp = arr[j - 1];
           arr[j - 1] = arr[j];
           arr[j] = tmp;
        }
    }

}

void sortLibrary(){
}

void test() {
    studentCollection sc;
    studentRecord stu3(84, 1152, "Sue");
    studentRecord stu2(75, 4875, "Ed");
    studentRecord stu1(98, 2938, "Todd");
    
    sc.addRecord(stu3);
    sc.addRecord(stu2);
    sc.addRecord(stu1);

    scIterator iter;
    int gradeTotal = 0;
    int numRecords = 0;
    iter = sc.firstItemIterator();
    while(!iter.pastEnd()){
        numRecords++;
        gradeTotal += iter.student().grade();
        iter.advance();
    }
    double average = static_cast<double> (gradeTotal)/ numRecords;
    cout << average << endl;
}


int main(){
    test();
    return 0;
}
