#include <iostream>
using namespace std;

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
        typedef bool (* firstStudentPolicy)(studentRecord r1, studentRecord r2);
    public:
        studentCollection();
        ~studentCollection();
        studentCollection(const studentCollection &copy);
        studentCollection& operator=(const studentCollection &rhs);
        void addRecord(studentRecord newStudent);
        studentRecord recordWithNumber(int IDnum);
        void removeRecord(int IDnum);
        void setFirstStudentPolicy(firstStudentPolicy f);
        studentRecord firstStudent();
        studentRecord recordAt(int position);
        friend class scIterator;
    private:
        firstStudentPolicy _currentPolicy;
        typedef studentNode * studentList;
        studentList _listHead;
        void deleteList(studentList &listPtr);
        studentList copiedList(const studentList copy);
};

class scIterator {
    public:
        scIterator();
        scIterator(studentCollection::studentNode * initial);
    private:
        studentCollection::studentNode * current;
};

bool higherGrade(studentRecord r1, studentRecord r2){
    return r1.grade() > r2.grade();
}

bool lowerStudentNumber(studentRecord r1, studentRecord r2){
    return r1.studentID() < r2.studentID();
}

bool nameComesFirst(studentRecord r1, studentRecord r2){
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
        if (_currentPolicy(loopPtr->studentData, first)){
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

void studentCollection::setFirstStudentPolicy(firstStudentPolicy f){
    _currentPolicy = f;
}

int main(){
    return 0;
    }
