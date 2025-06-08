#include <iostream>
using namespace std;


int iterNum(int arr[], size_t size, int target){
    int total = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] == target)total++;
    }
    return total;
}

int recNum(int arr[], size_t size, int target){
    if (size == 0) return 0;
    int rest = recNum(arr, size - 1, target);
    if (arr[size -1] == target) rest++;
    return rest;
}

void test(){
    const int arrSize = 10;
    int arr[arrSize] = { -1, 2, -3, -40, 45, -3, 5, 0, 2, -3};
    int target = 3;
    cout << "num of target: " << iterNum(arr, arrSize, target) << endl;
    cout << "num of target: " << recNum(arr, arrSize, target) << endl;
}

int main(){
    test();
    return 0;
}
