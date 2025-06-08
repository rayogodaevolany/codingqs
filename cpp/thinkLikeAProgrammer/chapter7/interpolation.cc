#include <iostream>
using namespace std;

struct studentRecord{
    int grade;
    int studentNum;
};

studentRecord** studentArray(){
    int grades[10] = {87,98,82,72,65,7,28,93,99,45};

    studentRecord ** stuArr = new studentRecord*[10];

    for (int i = 0; i < 10; i++){
        studentRecord * tmp = new studentRecord;
        tmp->grade = grades[i];
        tmp->studentNum = i + 1;
        stuArr[i] = tmp;
    }
    return stuArr;
}

int comp(const void * a, const void * b){
     studentRecord *stuA = *static_cast< studentRecord* const*>(a);
     studentRecord *stuB = *static_cast< studentRecord* const *>(b);
    return stuA->studentNum - stuB->studentNum;
}

int interpolation(int id, studentRecord ** arr, size_t size){
    // initialize low high and pos
    int low = 0, high = size - 1, pos;
    bool found = false;
    // loop until the answer is found or doesn't exist
    while ((id >= arr[low]->studentNum && id <= arr[high]->studentNum)){
        // set the checker to half like in binary search first
        pos =  low + ((id - arr[low]->studentNum) / (arr[high]->studentNum - arr[low]->studentNum)) * (high - low);
        // change low and high based on the id
        if (arr[pos]->studentNum > id){
            high = pos -1;
        } else if (arr[pos]->studentNum < id){
            low = pos + 1;
        } else {
            found = true;
            break;
        }

    }
    if (found) return pos;
    else return -1;
}

void solve(){
    studentRecord ** arr = studentArray();
    qsort(arr, 10, sizeof(studentRecord *), comp);

    // for (int i = 0; i < 10; i++){
    //     cout << arr[i]->studentNum << " ";
    // }
    // cout << endl;
    cout << interpolation(10, arr, 10) <<endl;

}

int main(){
    solve();
    return 0;
}
