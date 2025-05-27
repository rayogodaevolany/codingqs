#include <iostream>
#include "studentCollection.h"
using namespace std;

studentRecord::studentRecord(){
    setGrade(0);
    setStudentID(-1);
    setName("");
}

studentRecord::studentRecord(int newGrade, int newID, string newName){
    setGrade(newGrade);
    setStudentID(newID);
    setName(newName);
}
int studentRecord::grade(){
    return _grade;
}
void studentRecord::setGrade(int newGrade){
    if(isValidGrade(newGrade)){
        _grade = newGrade;
    }
}
int studentRecord::studentID(){
    return _studentID;
}
void studentRecord::setStudentID(int newID){
    _studentID = newID;
}

string studentRecord::name(){
    return _name;
}
void studentRecord::setName(string newName){
    _name = newName;
}

bool studentRecord::isValidGrade(int grade){
    if ((grade>=0 || grade == 0) && (grade <=100)){
        return true;
    } else {
        return false;
    }
}

string studentRecord::letterGrade(){
    if(!isValidGrade(_grade)) return "ERROR";
    const int NUMBER_CATEGORIES = 11;
    const string GRADE_LETTER[] = {"F","D","D+","C-","C","C+","B-","B","B+","A-","A","A+",};
    const int LOWEST_GRADE_SCORE[] = {0, 60, 67, 70, 73, 77, 80, 83, 87, 90,93};
    int category = 0;
    while (category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade)
        category++;
    return GRADE_LETTER[category-1];
}
