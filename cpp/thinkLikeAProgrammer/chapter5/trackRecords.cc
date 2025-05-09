#include<iostream>
using namespace std;

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
int main(){
    return 0;
}
