#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve(){
    int n, q; cin >> n >> q;
    vector<int> location(n);
    unordered_map<int, vector<int>> hash(n);
    for (int i = 1; i <= n; i++){
        location[i] = i;
        hash[i].push_back(i);
    }

    int count = n;
    for (int i = 0; i < q; i++){
        int qtype; cin >> qtype;
        if (qtype == 1 ){
            int p,h; cin >> p >> h;
            //find where p is 
            //and erase it from the hash
            for (auto it = begin(hash[location[p]]); it != end(hash[location[p]]); it++){
                if (*it == p){
                    // needs to be optimized
                    hash[location[p]].erase(it);
                }
            }
            if (hash[location[p]].empty()){
                count--;
            }
            // place p in the right hash location
            if (hash[h].empty()){
                count++;
            }
            hash[h].push_back(p);
            location[p] = h;
            // change count if a hash entry becomes empty
        } else if (qtype == 2){
            cout << n - count << endl;
            // output count
        }
    }

}

int main(){
    solve();
    return 0;
}
