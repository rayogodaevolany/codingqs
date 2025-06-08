#include <iostream>
using namespace std;

// true is odd, false is even
bool iterparity(int arr[], size_t size){
    int total = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] == 1) total++;
    }
    if (total % 2 > 0) return true;
    else return false;

}

bool parity(int arr[], size_t size){
    if (size == 0) return false;
    bool truOrFal = parity(arr, size - 1);
    if (arr[size - 1] == 1) truOrFal = !truOrFal;
    return truOrFal;
}

void test(){
    const int arrSize = 1;
    int arr[arrSize] = {0 };
    if (iterparity(arr, arrSize)) cout << "iter true" << endl;
    else  cout << "iter false" << endl;

    if (parity(arr, arrSize)) cout << "iter true" << endl;
    else  cout << "iter false" << endl;
}
int main(){
    test();
    return 0;
}
