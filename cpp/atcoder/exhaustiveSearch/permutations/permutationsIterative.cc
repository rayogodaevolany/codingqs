#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> next_perm(vector<int> arr){
    int size = arr.size();
    int pivot = -1;
    // find the pivot point, the index before the longest non-increasing suffix
    for (int i = size - 2; i >= 0; i--) {
        if (arr[i] < arr[i+1]){
            pivot = i;
            break;
        }
    }
    if (pivot == -1){
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        return  sorted;
    }
    // find the smallest value in the suffix
    int minIndex = -1;
    for (int i = size - 1; i > pivot; i--) {
        if (arr[i] > arr[pivot]){
            minIndex = i;
            break;
        }
    }

    // swap the two
    swap(arr[pivot], arr[minIndex]);
    // reverse the suffix
    // reverse(arr.begin() + pivot + 1, arr.end());
    // take the suffix
    // reverse it 
    // vector<int> copy;
    // for (int i = size - 1; i > pivot; i--){
    //     copy.push_back(arr[i]);
    // }
    // for (int i = 0; i < size - 1 - pivot; i++){
    // // copy it into the right place
    //     arr[pivot + 1 + i] = copy[i];
    // }
    //
    int left = pivot + 1;
    int right = size - 1;
    while (left < right){
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        left++;
        right--;
    }

    return arr;

}

// routine take a vector of ints
// the returns all possible permutations
// vector<vector<int>> permut (vector<int> arr){
// }

void print(vector<vector<int>> perm){
    int size = perm.size();
    for (int i = 0; i< size; i++){
        int innerSize = perm[i].size();
        for (int j = 0; j < innerSize; j++){
            cout << perm[i][j];
        }
        cout << endl;
    }
}
void test(){
    vector<int> arr = {1,2,5,4,3};
    vector<int> perm = next_perm(arr);
    for (int i = 0; i< static_cast<int>(arr.size()); i++){
        cout << perm[i];
    }
    cout << endl;

}
int main(){
    test();
    return 0;
}
