#include "scIterator.h"
using namespace std;

scIterator::scIterator(){
    current = nullptr;
}

scIterator::scIterator(studentCollection::studentNode * initial){
    current = initial;
}

void scIterator::advance(){
    if (current != nullptr){
        current = current->next;
        return;
    }
}

bool scIterator::pastEnd(){
    return current == nullptr;
}

studentRecord scIterator::student(){
    if (current == nullptr){
        studentRecord dummyRecord(-1, -1, "");
        return dummyRecord;
    } else {
        return current->studentData;

    }
}
