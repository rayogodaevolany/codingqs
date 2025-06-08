#include <iostream>
#include "studentCollection.h"
#include "scIterator.h"
using namespace std;
bool studentCollection::higherGrade(studentRecord r1, studentRecord r2){
    return r1.grade() > r2.grade();
}

bool studentCollection::lowerStudentNumber(studentRecord r1, studentRecord r2){
    return r1.studentID() < r2.studentID();
}

bool studentCollection::nameComesFirst(studentRecord r1, studentRecord r2){
    return strcmp(r1.name().c_str(), r2.name().c_str()) < 0;
}

studentRecord studentCollection::firstStudent(){
    // make a dummy record;
    if (_listHead == nullptr || _currentPolicy == nullptr){
        studentRecord dummyRecord(-1, -1, "");
        return dummyRecord;
    }
    studentNode * loopPtr = _listHead;
    studentRecord first = loopPtr->studentData;
    loopPtr = loopPtr->next;
    while (loopPtr != nullptr){
        if ((this->*_currentPolicy)(loopPtr->studentData, first)){
            first = loopPtr->studentData;
        }
        loopPtr = loopPtr->next;
    }
    return first;
}

studentRecord studentCollection::recordAt(int position){
    studentNode * loopPtr = _listHead;
    int i = 1;
    while (loopPtr != nullptr && i < position){
        i++;
        loopPtr = loopPtr->next;
    }
    if (loopPtr == nullptr){
        studentRecord dummyRecord(-1, -1, "");
        return dummyRecord;
    } else {
        return loopPtr->studentData;
    }
}

studentCollection::studentCollection(){
    _listHead = nullptr;
    _currentPolicy = nullptr;
}
void studentCollection::addRecord(studentRecord newStudent){
    studentNode * newNode = new studentNode;
    newNode->studentData = newStudent;
    newNode->next = _listHead;
    _listHead = newNode;
}

studentRecord studentCollection::recordWithNumber(int idNum){
    studentNode * loopPtr = _listHead;
    while(loopPtr->studentData.studentID() != idNum){
        loopPtr = loopPtr->next;
    }
    if(loopPtr == nullptr){
        studentRecord dummyRecord(-1, -1, "");
        return dummyRecord;
    } else {
        return loopPtr->studentData;
    }
}

void studentCollection::removeRecord(int idNum){
    studentNode * loopPtr = _listHead;
    studentNode * trailing = nullptr;
    while(loopPtr != nullptr && loopPtr->studentData.studentID() != idNum){
        trailing = loopPtr;
        loopPtr = loopPtr->next;
    }
    if (loopPtr == nullptr) return;
    if (trailing ==nullptr) {
        _listHead = _listHead->next;
    } else {
        trailing->next = loopPtr->next;
    }
    delete loopPtr;
}

void studentCollection::deleteList(studentList &listPtr){
    while(listPtr!=nullptr){
        studentNode * tmp = listPtr;
        listPtr = listPtr->next;
        delete tmp;
    }
}

studentCollection::studentList studentCollection::copiedList(studentList original){
    if (original == nullptr) return nullptr;

    studentList newList = new studentNode;
    newList->studentData = original->studentData;

    studentNode * oldLoopPtr = original->next;
    studentNode * newLoopPtr = newList;

    while(oldLoopPtr != nullptr){
        newLoopPtr->next = new studentNode;
        newLoopPtr = newLoopPtr->next;
        
        newLoopPtr->studentData = oldLoopPtr->studentData;

        oldLoopPtr= oldLoopPtr->next;
    }
    newLoopPtr->next = nullptr;
    return newList;
}

studentCollection::~studentCollection(){
    deleteList(_listHead);
}


studentCollection&  studentCollection::operator=(const studentCollection& rhs){
    if(this != &rhs){
        deleteList(_listHead);
        _listHead = copiedList(rhs._listHead);
    }
    return *this;
}

studentCollection::studentCollection(const studentCollection &original){
    _listHead = copiedList(original._listHead);
}

void studentCollection::setFirstStudentPolicy(criteria crit){
    int criteriaArr[3] = {GRADE, NUMBER, NAME};
    firstStudentPolicy funcArr[3] = {
                                &studentCollection::higherGrade,
                                &studentCollection::lowerStudentNumber,
                                &studentCollection::nameComesFirst
                            };
    int i = 0;
    while (criteriaArr[i] != crit){
        i++;
    }


    _currentPolicy = funcArr[i];
}
scIterator studentCollection::firstItemIterator(){
    return scIterator(_listHead);

}
