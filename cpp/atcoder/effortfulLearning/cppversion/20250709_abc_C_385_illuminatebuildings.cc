#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// int int -> int
//
// the constraints are that they need to be equal size and 
// equal distance apart
//
// input num of elements is 3000, size of element is 3000
// output the number of elements that are the same
void solve(){
    int n; cin >> n;
    unordered_map<int, vector<int>> hash;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        hash[arr[i]].push_back(i);
    }

    for (int i = 0; i < (int)hash.size(); i++){
        int interval = hash[arr[i]] - 0;
        while(true){
        }
    }
}

int main(){
    solve();
    return 0;
}
