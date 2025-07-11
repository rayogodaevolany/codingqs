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
    // val : {index, ...}
    unordered_map<int, vector<int>> hash;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        // take the interval
        hash[arr[i]].push_back(i - *hash[arr[i]].end());
    }

    int res = 0;
    // for every hash key
    for (int j = 0; j < (int)hash.size(); j++){
        // from every element as the starting
        for (int i = 0; i < (int)hash[j].size(); i++){
            int interval = 0;
            // for every element in the vector
            for (int m = 0; m < ((int)hash[j].size() - i); m++){
                interval += hash[j][m];
                int count = 0;
                int nextinterval = 0;
                int increment = 1;
                // until out of bounds
                while(hash[j][i+increment] && interval > nextinterval){
                    nextinterval+=hash[j][i+increment];
                    if (interval == nextinterval){
                        nextinterval = 0;
                        count++;
                    }
                    increment++;
                }
                res = max(count, res);
            }
            interval = 0;
        }
    }
    cout << res << endl;
}

int main(){
    solve();
    return 0;
}
