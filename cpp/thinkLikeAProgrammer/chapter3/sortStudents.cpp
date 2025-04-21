#include <iostream>
using namespace std;

struct student {
    int grade;
    int studentID;
    string name;
};

int compare(const void *a, const void *b) {
    struct student *structa = (struct student*) a;
    struct student *structb = (struct student*) b;
    int res = structa->studentID - structb->studentID;
    return res;
}

int main() {
    const int ARRAY_SIZE = 10;
    student studentArray[ARRAY_SIZE] = {
        {87, 10001, "Fred"},
        {28, 10002, "Tom"},
        {100, 10003, "Alistair"},
        {78, 10004, "Sasha"},
        {84, 10005, "Erin"},
        {98, 10006, "Belinda"},
        {75, 10007, "Leslie"},
        {70, 10008, "Candy"},
        {81, 10009, "Aretha"},
        {68, 10010, "Veronica"}
    };

    // sort studentArray using qsort
    qsort(studentArray,ARRAY_SIZE, sizeof(studentArray[0]),compare);

    // loop over array to print it out 
    for (int i =0; i<ARRAY_SIZE; i++){
        cout << studentArray[i].studentID << " " << studentArray[i].name << endl;
    }

}
