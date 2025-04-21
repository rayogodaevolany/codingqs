#include<iostream>
using namespace std;

// bool function that is passed an array and the number of elements in
// that array and determines whether the data in the array is sorted. This should
// require only one pass!

bool isItSorted(int* arr, int numElems){
    if (numElems == 0 || numElems ==1){
        return true;
    }

    // loop through array and check whether each ele is smaller than next till end
    for(int i =0;i <numElems - 1; i++){
        // check whether this ele is smaller than the next
        if (arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}

int main(){
    const int ARRAY_SIZE = 10;
    // int intArray[ARRAY_SIZE] = {3, 4, 2, 12, -4, 0, -57, 309845, -283, 2};
    int intArray[ARRAY_SIZE] = { -123123, -3, 0, 1, 4, 8, 12, 40, 57, 309845 };
    bool res;
    res = isItSorted(intArray, ARRAY_SIZE);

    cout << res;
}
