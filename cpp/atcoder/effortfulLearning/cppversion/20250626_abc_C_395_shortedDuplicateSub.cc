#include <iostream>
#include <unordered_map>
using namespace std;

//hashmap
//kinda greedy
void solve(){
    unordered_map <int, int> hash;
    int n; cin >> n;

    //initiate to a large num
    int mincount = 1e9;
    // loop through n times
    for (int i = 0; i < n; i++){
        // initiate count to large num
        int count = 1e9;
        // get x
        int x; cin >> x;
        // if x is in the hash
        if (hash.count(x) != 0){
             count = i - hash[x];
        }
        hash[x] = i;
        mincount = min(mincount, count);

    }
    if (mincount == 1e9){
        cout << -1 << endl;
    } else {
        cout << mincount + 1 << endl;
    }
}


int main(){
    solve();
    return 0;
}
