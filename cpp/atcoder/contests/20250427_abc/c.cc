#include <iostream>
#include <vector>
using namespace std;

//check if it has the right properties
bool istilde(vector<int> vec) {
    // check if first is less than second
    if (vec[0] >= vec[1]){
        return false;
    }
    
    // use flags
    bool hill = false, valley = false;
    // check if it has the valley or hills
    // loop through the whole thing seeing if it has the right shape
    for (int i = 1; i< int(vec.size())-2 ; i++){
        if ( vec [1] < vec[2] && vec[2] > vec[3]){
            hill = true;
        } else if (vec[1] > vec[2] && vec[2] <vec[3]){
            valley = true;
        }
    }

    if ( valley && hill ){
        return true;
    } else return false;


}

int main(){
    int N; cin >> N;
    
    vector<int> vec;

    for(int i = 0; i < N; i++) vec.push_back(i);

    // sliding window problem
    // use two pointers 
    // once the right pointer gets to the end
    // then the left pointer moves to the end
    // check the properties of each subarray
    //
    
    int count = 0;
    // loop until right is at the end
    for (int i = 0; i < N; i++){
        vector<int> subvector = {vec.begin(), vec.begin() + i }; 
        if (istilde(subvector)){
            count++;
        }
    }
    // checking from left to right 
    for (int i = 0; i < N; i++){
    // loop until left is at the end
    // checking from left to right
        vector<int> subvector = {vec.begin() + i, vec.end()}; 
        if (istilde(subvector)){
            count++;
        }
    }

    cout << count << endl;

}
