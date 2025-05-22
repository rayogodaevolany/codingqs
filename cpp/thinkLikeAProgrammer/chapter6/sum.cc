#include <iostream>
using namespace std;

int sum(int arr[], size_t size){
    int sumarr = 0;
    // loop over array summing 
    for(int i = 0; i < size; i++){
        sumarr += arr[i];
    }
    return sumarr;

}

int arrSumRec(int arr[], size_t size){
    if(size == 0)return 0;

    int lastNum = arr[size - 1];
    int allButLast;
    allButLast = arrSumRec(arr, size - 1);
    return lastNum + allButLast;
}

int zeros(int arr[], size_t size){
    int count = 0;
    for(int i = 0; i< size; i++){
        if( arr[i] == 0){
            count++;
        }
    }
    return count;
}

int count = 0;

//int recZerosBad(int arr[], size_t size){
//    //write a delegater that calls the iterative function
//    if(size == 0) return count;
//    if(arr[size - 1] == 0) count++;
//    recZerosBad(arr, size -1);
//}

int recZeros(int arr[], size_t size){
    if(size == 0) return 0;
    int rest = recZeros(arr, size - 1);
    if(arr[size - 1] == 0) rest++;
    return rest;
}

int main(){
    int arr[4] = {1, 2, 3, 4};
    cout << sum(arr, 4) << endl;
    // cout << arrSumDelegate(arr, 4) << endl;
    cout << arrSumRec(arr, 4) << endl;
}
