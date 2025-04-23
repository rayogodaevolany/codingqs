#include<iostream>
#include<vector>
using namespace std;

// routine that multiplies all values in an array
// input: array of ints, index of array (defaults to zero)
// output: int
// recursive call inputs are tail, the calls get smaller 
int product(vector<int> arr, size_t index=0){
    //basecase: empty array returns 1, 1 int returns int
    if (index >= arr.size()){
        return 1;
    } else if (index == arr.size() - 1 ){
        return arr[index];
    }

    // head is first int
    int head = arr[index];
    // return head multiplied with the sum from the recursive call
    return head * product(arr, index+1);
}


int main(){
    // hardcode array of ints
    vector<int> arr = { 3, 1, 5, 2,5,7};

    // call product function with array
    // print res
    int res = 1;
    for (int i =0;i<arr.size();i++){
        res *= arr[i];
    }
    cout << res << "hi" << '\n';
    cout << product(arr);
    return 0;
}
