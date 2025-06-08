#ifndef STUDENTCOLLECTION_H
#define STUDENTCOLLECTION_H

#include <cstddef>
#include <string>
using namespace std;

class scIterator;

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

class studentCollection{
    private:
        struct studentNode{
            studentRecord studentData;
            studentNode * next;
        };
        typedef bool (studentCollection::*firstStudentPolicy)(studentRecord r1, studentRecord r2);
    public:
        enum criteria {GRADE, NUMBER, NAME};
        studentCollection();
        ~studentCollection();
        studentCollection(const studentCollection &copy);
        studentCollection& operator=(const studentCollection &rhs);
        void addRecord(studentRecord newStudent);
        studentRecord recordWithNumber(int IDnum);
        void removeRecord(int IDnum);
        void setFirstStudentPolicy(enum criteria);
        studentRecord firstStudent();
        studentRecord recordAt(int position);
        friend class scIterator;
        scIterator firstItemIterator();
    private:
        bool higherGrade(studentRecord r1, studentRecord r2);
        bool lowerStudentNumber(studentRecord r1, studentRecord r2);
        bool nameComesFirst(studentRecord r1, studentRecord r2);
        firstStudentPolicy _currentPolicy;
        typedef studentNode * studentList;
        studentList _listHead;
        void deleteList(studentList &listPtr);
        studentList copiedList(const studentList copy);
};


#endif
