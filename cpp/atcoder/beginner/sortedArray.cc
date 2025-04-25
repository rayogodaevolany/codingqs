#include<iostream>
#include<vector>
using namespace std;

// get array of ints give how many subarrays i would need
// to group the ints into nondecreasing or nonincreasing orders.

int main(){
    int N;
    cin >> N;
    int x;
    vector<int> arr;
    while (cin>>x){
        arr.push_back(x);
    }

    int count = 0;
    // increasing and decreasing bools
    bool increasing = true;
    bool decreasing = false;
    // for every int in the array, compare to the int before
    for (int i=1;i<arr.size();i++){
        // if increasing
        if (arr[i] >= arr[i-1]){
            // and it was decreasing to begin with then increment
            if(decreasing && i != 1) count++;
            increasing = true;
            decreasing = false;
        } else {
            // if it is decreasing, but increasing to begin with increment
            if (increasing && i !=1) count++;
            increasing = false;
            decreasing = true;
        }
    }
    cout << count;
    return 0;
}
