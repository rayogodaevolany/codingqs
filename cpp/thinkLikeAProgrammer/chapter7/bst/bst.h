#ifndef BST_H
#define BST_H

#include <cstddef>

class BST{
    private:
        struct studentRecord{
            int grade;
            int studentNum;
            studentRecord * left;
            studentRecord * right;
            studentRecord(
                    int gr,
                    int sn,
                    studentRecord * l,
                    studentRecord * r
                    ):
                grade(gr), studentNum(sn), left(l), right(r){}

        };
        typedef studentRecord * studentHead;

    public:
        BST();
        void insertRecord(studentRecord * record);
        studentRecord * lookup(int studentNum);
        int interpolation(int id, studentRecord ** arr, size_t size);
    private:
        studentHead _root;
        studentRecord * insertHelper(studentHead root, studentRecord * newRecord);
        studentRecord * lookupHelper(studentHead root, int studentNum);

};




#endif
