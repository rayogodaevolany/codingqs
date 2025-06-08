#include <iostream>
using namespace std;

// take an array and sum the positive ints
int sum(int arr[], size_t size){
    int total = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] > 0){
            total += arr[i];
        }
    }
    return total;
}

int delegate(int arr[], size_t size){
    if (size == 0) return 0;
    int totalOfRest = sum(arr, size - 1);
    if (arr[size -1] > 0) totalOfRest += arr[size - 1];
    return totalOfRest;

}

int recSum(int arr[], size_t size){
    if (size == 0) return 0;
    int totalOfRest = recSum(arr, size - 1);
    if (arr[size -1] > 0) totalOfRest += arr[size - 1];
    return totalOfRest;

}

void test(){
    const int arrSize = 10;
    int arr[arrSize] = { -1, 2, 3, -40, 45, 5, 5, 0, 2, -3};
    cout << "normal sum: " << sum(arr, arrSize) << endl;
    cout << "delegate sum: " << delegate(arr, arrSize) << endl;
    cout << "recursive sum : " << recSum(arr, arrSize) << endl;
}

int main(){
    test();
    return 0;
}
