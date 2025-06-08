#include <iostream>
#include <vector>
using namespace std;

// routine take a vector of ints
// the returns all possible permutations
vector<vector<int>> permut (vector<int> arr){
    // create vector
    vector<vector<int>> res;
    int size = arr.size();
    //basecase: one number
    if (size == 1){
        res.push_back(arr);
        return res;
    }
    //recursive case: one letter less
    int curNum = *arr.begin();
    arr.erase(arr.begin());
    res = permut(arr);

    //work to be done:
    vector<vector<int>> newRes;
    //place head letter in between all spaces in the tail from the recursion
    //for every array in res
    for (int i = 0; i < static_cast<int>(res.size()); i++){
        // put the head into every part of the array and put that into the results
        // for every index in the subarray 
        for (int j = 0; j <= static_cast<int>(res[i].size()); j++){
            vector<int> copy = res[i];
            copy.insert(copy.begin()+j,curNum);
            newRes.push_back(copy);
        }

    }

    return newRes;


}

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
    vector<int> arr = {1,2,3};
    vector<vector<int>> perm = permut(arr);
    print(perm);

}
int main(){
    test();
    return 0;
}
