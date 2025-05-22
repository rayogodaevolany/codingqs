#include <iostream>
using namespace std;

int * iterSolveRec(int arr[], size_t size){
    int * copy = new int[size];
    for (int i = 0; i < size; i++) copy[i] = arr[i];
    return copy;
}

// copy a list to a new list
void solveRec(int arr[], size_t size, int* target){
    if (size == 0) return;
    target[size - 1] = arr[size - 1];
    solveRec(arr, size - 1, target);
}
int* recWrapper(int arr[], size_t size){
    int * copy = new int[size];
    solveRec(arr, size, copy);
    return copy;
}

void test(){
    const int arrSize = 10;
    int arr[arrSize] = { -1, 2, -3, -40, 45, -3, 5, 0, 2, -3};

    int * copy = recWrapper(arr, arrSize);
    for (int i = 0; i < arrSize; i++){
        cout << copy[i] << endl;
    }
    delete [] copy;

}

int main(){
    test();
    return 0;
}
