#include<iostream>
using namespace std;

// student object
struct student {
    int grade;
    int studentID;
    string name;
};


// better sort 

vector<student> betterSorted (vector<student> arr){
    vector <student> copy = arr;

    sort(copy.begin(), copy.end(), [](const student& a, const student& b){
            return a.grade < b.grade;
            });
    return copy;
}

// routine sorts array with insertion sort
// input:array, size
// output: array

student* sorted( const student arr[], const size_t& size){
    // create new arr to not mutate
    student *copy = new student[size];
    for(int i=0;i<size;i++) copy[i]=arr[i];

    // loop through arr from start to end 
    for(int i=1;i<size;i++){
        // loop from the index to the end of that iteration
        // the end is either when the previous is smaller 
        // or when it is the end of the array
        for(int j=i; j > 0 && copy[j].grade< copy[j-1].grade; j--){
            student tmp = copy[j-1];
            copy[j-1] = copy[j];
            copy[j] = tmp;
        }
    }
    return copy;
}

//routine gives student quartiles
//input: array of student objects, quartile 
//output: grades to score better than given quartile

int quartile( student arr[], const size_t& size, const int& quartile){ 
    // sort students
    student *sortedStudents = sorted(arr, size);
    // take quartile percent of the count and find the right student. 
    // Better than that grade and you are better than that quartile of the students
    int count = size * (float(quartile) / 100.00);
    int grade = sortedStudents[count].grade;
    delete[] sortedStudents;
    return grade;
}

    
int main() {
    // student objects
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

    cout << "Better than 25%" << '\n';
    cout << quartile(studentArray, ARRAY_SIZE, 25) << '\n';
    return 0;
}
