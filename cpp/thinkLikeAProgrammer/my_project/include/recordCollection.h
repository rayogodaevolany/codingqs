#include <cstddef>

#pragma once

class recordCollection {
    private:
        struct listNode {
            int grade;
            int studentNum;
            listNode* next;
        };
    typedef listNode* studentCollection;
    public:
        recordCollection();
        recordCollection(studentCollection sc);
        ~recordCollection();
        // copy operator= other constructors
        listNode getRecord();
        void setRecord(listNode record);
        recordCollection& operator=(const recordCollection & rhs);
        void addRecord(
                int grade,
                int studentNum
                );
        double averageRecords();
        studentCollection RecordsWithinRange(double low, double high);
    private:
        studentCollection _head;
        void deleteList(listNode* &head);
        studentCollection copyList(listNode* head);

};
