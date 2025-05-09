#include<iostream>
#include<string>
using namespace std;

struct student{
    int grade;
    int studentID;
    string name;
};

class studentRecord {
    public: 
        studentRecord();
        studentRecord(int newGrade, int newID, string newName);
        int grade();
        void setGrade(int newGrade);
        int studentID();
        void setStudentID(int newID);
        string name();
        void setName(string newName);
        string letterGrade();
    private:
        int _grade;
        int _studentID;
        string _name;
        bool isValidGrade( int grade);
};

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
    if ((grade>=0) && (grade <=100)){
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


class studentCollection{
    private:
        struct studentNode{
            studentRecord studentData;
            studentNode * next;
        };
    public:
        studentCollection();
        void addRecord(studentRecord newStudent);
        studentRecord recordWithNumber(int idNum);
        void removeRecord(int idNum);
    private:
        typedef studentNode * studentList;
        studentList _listHead;
};

studentCollection::studentCollection(){
    _listHead = NULL;
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
    if(loopPtr == NULL){
        studentRecord dummyRecord(-1, -1, "");
        return dummyRecord;
    } else {
        return loopPtr->studentData;
    }
}


void test() {
    studentCollection s;
    studentRecord stu3(84, 1152, "Sue");
    studentRecord stu2(75, 4875, "Ed");
    studentRecord stu1(98, 2938, "Todd");
    
    s.addRecord(stu3);
    s.addRecord(stu2);
    s.addRecord(stu1);
    s.removeRecord(4875);
}
int main(){
    return 0;
}
