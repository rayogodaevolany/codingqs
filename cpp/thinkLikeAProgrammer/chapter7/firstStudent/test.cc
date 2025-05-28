#include <iostream>
#include "scIterator.h"
#include "studentCollection.h"
#include <algorithm>

using namespace std;


void sortAlgo(studentRecord arr[], size_t arraySize){
    // get a studentCollection array
    int start = 0;
    int end = arraySize;

    // for every value starting at index 1
    for (int i = start + 1; i < end; i++){
        // if the indexed point is valid
        if (arr[i].grade() != -1){
            // create a right pointer
            int rightswap = i;
            // loop decrementing from one right of indexed point
            // until the out of range
            // or pointers are right/ looppointer is invalid
            for (int leftswap = i - 1;
                    leftswap >= start
                    && (arr[leftswap].grade() > arr[rightswap].grade()
                        || arr[leftswap].grade() == -1);
                    leftswap--){
                // if the loop pointer is valid
                if (arr[leftswap].grade() != -1){
                    // swap
                    studentRecord tmp = arr[leftswap];
                    arr[leftswap] = arr[rightswap];
                    arr[rightswap] = tmp;
                    rightswap = leftswap;
                }
            }
        }
    }

}
void sortAlgoBroken(studentRecord arr[], size_t arraySize){
    // get a studentCollection array
    int start = 0;
    int end = arraySize;

    // for every value starting at index 1
    for (int i = start + 1; i < end; i++){
        // find the first non -1 from i - 1
        int m = i - 1;
        while (arr[m].grade() == -1){
            m--;
        }
        // keep swapping values until they are in sorted order
        for (int j = i; j > start && (arr[j].grade() < arr[m].grade() || arr[j].grade() == -1); j--){
            if (arr[j].grade() != -1){
                studentRecord tmp = arr[m];
                arr[m] = arr[j];
                arr[j] = tmp;
                // continue onto next valid value
                m--;
                while (arr[m].grade() == -1){
                    m--;
                }
            }
        }
    }

}

// a comparison function for qsort
int comp(const void * a, const void * b){
    studentRecord *asr = (studentRecord *)a;
    studentRecord *bsr = (studentRecord *)b;
    return asr->grade() - bsr->grade();
}


void sortLibrary(studentRecord arr[], size_t arr_size){
    // copy all the records that aren't -1
    studentRecord * nonNegOnes = new studentRecord[arr_size];
    int counter = 0;
    for (int i = 0; i < arr_size; i++){
        if (arr[i].grade() != -1){
            nonNegOnes[i] = arr[i];
            counter++;
        }
    }
    // sort that array
    qsort(nonNegOnes, counter, sizeof(studentRecord), comp);
    // copy back into original array where values aren't -1
    int pointer = 0;
    for (int i = 0; i<arr_size; i++){
        if (arr[i].grade() != -1){
            arr[i] = nonNegOnes[pointer];
            pointer++;
        }
    }
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
