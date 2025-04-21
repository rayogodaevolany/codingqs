#include<iostream>
using namespace std;

int* selectionSort(int inputarr[], int size) {
    int *arr = new int[size];
    for(int i = 0; i < 10; i++){
        arr[i] = inputarr[i];
    }

    int start = 0;
    int end = size - 1;
    for (int i = start + 1; i <= end; i++){
        for(int j = i; j > start && arr[j] < arr[j-1]; j--){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
        }
    }
    return arr;
}
int compareFunc( const void* voidA, const void* voidB){
    int * intA = (int*) voidA;
    int * intB = (int*) voidB;
    return *intA - *intB;
}

int main() {
    const int ARRAY_SIZE = 10;
    int intArray[ARRAY_SIZE] = {3, 4, 2, 12, -4, 0, -57, 309845, -283, 2};
    enum sortMethod {SELECTION, QSORT};
    sortMethod s = QSORT;

    int* sortedArray;
    switch(s) {
        case SELECTION: 
            sortedArray = selectionSort(intArray, ARRAY_SIZE);
            for (int i = 0; i < ARRAY_SIZE; i++){
                cout << sortedArray[i] << " ";
            }
            break;
        case QSORT: 
            for (int i = 0; i < ARRAY_SIZE; i++){
                cout << intArray[i] << " ";
            }
            cout << "\n";
            qsort(intArray, ARRAY_SIZE, sizeof(intArray[0]), compareFunc);
            for (int i = 0; i < ARRAY_SIZE; i++){
                cout << intArray[i] << " ";
            }
            break;
    }




}
